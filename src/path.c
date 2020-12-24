#include "../inc/pathfinder.h"

t_path *create_path(int isl, int dist) {
	t_path *node = (t_path *)malloc(1 * sizeof(t_path));

	node->idPath = isl;
	node->distPath = dist;
	node->nextConnect = NULL;
	node->nextPath = NULL;
	
	return node;
}


int add_index_pathes(t_path **path) {
    t_path *indexed = *path;
    t_path *bonds = NULL;
    int i = 0;

    for (; indexed; indexed = indexed->nextPath) {
        bonds = indexed;

        while (bonds) {
            bonds->index = i;
            bonds = bonds->nextConnect;
        }

        i++;
    }
    
    return i;
}

void add_link(t_path **cur, t_path **new) {
    t_path *current = *cur;

    while (current->nextConnect) {
        current->nextPath = *new;
        current = current->nextConnect;
    }
    
    current->nextPath = *new;
}

t_path *add_one_path(t_path **previous, int isl, int dist) {
    t_path *new = NULL;
    t_path *last = *previous;
    t_path *res = NULL;

    if (!last) {
        return res = create_path(isl, dist);
    }

    res = create_path(last->idPath, last->distPath);
    new = res;
    last = last->nextConnect;

    while (last) {
        new->nextConnect = create_path(last->idPath, last->distPath);
        last = last->nextConnect;
        new = new->nextConnect;
    }
    
    new->nextConnect = create_path(isl, dist);

    return res;
}

t_path *add_path(t_path **previous, int isl, int dist) {
    t_path *cur = NULL;
    t_path *res = NULL;
    t_path *new = NULL;
    t_path *fast = NULL;

    if (*previous) {
        cur = *previous;
    }

    res = add_one_path(&cur, isl, dist);
    fast = res;

    if (cur) {
        cur = cur->nextPath;
    }

    while (cur) {
        new = add_one_path(&cur, isl, dist);

        add_link(&fast, &new);

        fast = fast->nextPath;
        cur = cur->nextPath;
    }
    
    return res;
}

static void pop_all_bond(t_path **head) {
    t_path *p = NULL;

    if (!head || !(*head)) {
        return;
    }

    while ((*head)->nextConnect) {
        p = (*head)->nextConnect;

        free(*head);

        *head = p;
    }

    if (!(*head)->nextConnect && !(*head)->nextPath) {
        free(*head);

        *head = NULL;

        return;
    }
}

static void pop_next_path(t_path **head) {
    t_path *p = NULL;

    if (!head || !(*head)) {
        return;
    }
    if ((*head)->nextPath == NULL) {
        free(*head);

        *head = NULL;

        return;
    }
    else {
        p = (*head)->nextPath;

        free(*head);

        *head = p;
    }
}

void delete_path(t_path **head) {
    if (!head || !(*head)) {
        return;
    }
    
    while (*head) {
        pop_all_bond(&(*head));
        pop_next_path(&(*head));
    }
}

static t_path *add_one(t_path **previous) {
    t_path *new = NULL;
    t_path *last = *previous;
    t_path *res = NULL;

    res = create_path(last->idPath, last->distPath);
    new = res;
    last = last->nextConnect;

    while (last) {
        new->nextConnect = create_path(last->idPath, last->distPath);
        last = last->nextConnect;
        new = new->nextConnect;
    }

    return res;
}

t_path *copy_path(t_path **data) {
    t_path *cur = NULL;
    t_path *res = NULL;
    t_path *new = NULL;
    t_path *fast = NULL;

    if (*data) {
        cur = *data;
    }

    res = add_one(&cur);
    fast = res;
    cur = cur->nextPath;

    while (cur) {
        new = add_one(&cur);

        add_link(&fast, &new);

        fast = fast->nextPath;
        cur = cur->nextPath;
    }
    
    return res;
}

void path_push_back(t_path **path, t_path **previous, int isl, int dist) {
    t_path *last = *path;
    t_path *cur = *previous;
    t_path *new = NULL;
    
    while (last->nextPath != NULL) {
        last = last->nextPath;
    }
    while (cur) {
        new = add_one_path(&cur, isl, dist);

        if (unique_path(&new, &(*path)) == 1) {
            add_link(&last, &new);

            last = last->nextPath;
        }
        
        cur = cur->nextPath;
    }
}

static int cmp(t_path *bond, t_path *fast) {
    while (bond && fast) {
        if (bond->idPath > fast->idPath) {
            return 1;
        }
        if (bond->idPath < fast->idPath) {
            return 0;
        }

        bond = bond->nextConnect;
        fast = fast->nextConnect;
    }

    if (bond && !fast) {
        return 1;
    }

    return 0;
}

static void swp_d(t_path **disp, t_path **bond, t_path **fast) {
    t_path *temp = (*fast)->nextPath;
    t_path *cur = *disp;

    while (cur->nextPath != *fast) {
        cur = cur->nextPath;
    }

    add_link(&cur, &(*bond));

    cur = *disp;

    if (*disp == *bond) {
        *disp = *fast;
    }
    else {
        while (cur && cur->nextPath != *bond) {
            cur = cur->nextPath;
        }

        add_link(&cur, &(*fast));
    }

    add_link(&(*fast), &(*bond)->nextPath);
    add_link(&(*bond), &temp);
}

static void swp(t_path **disp, t_path **bond, t_path **fast) {
    t_path *temp = (*fast)->nextPath;
    t_path *cur = *disp;

    if ((*bond)->nextPath == *fast) {
        add_link(&(*fast), &(*bond));
        add_link(&(*bond), &temp);

        if (*disp == *bond) {
            *disp = *fast;
        }
        else {
            while (cur && cur->nextPath != *bond) {
                cur = cur->nextPath;
            }

            add_link(&cur, &(*fast));
        }
    }
    else {
        swp_d(&(*disp), &(*bond), &(*fast));
    }
}

void sort_path(t_path **disp, int sizeP) {
    t_path *bond = *disp;
    t_path *fast = (*disp)->nextPath;

    for (int i = 0; i < sizeP; i++) {
        bond = *disp;
        fast = bond->nextPath;

        for (; bond->index != i; bond = bond->nextPath) {
            fast = bond->nextPath;
        }

        while (fast) {
            if (cmp(bond, fast) == 1) {
                swp(&(*disp), &bond, &fast);

                for (bond = *disp; bond->index != i; bond = bond->nextPath) {
                    fast = bond->nextPath;
                }
            }
            else {
                fast = fast->nextPath;
            }
        }
    }
}

static void compare(t_path **newOne, t_path **curOne, int *flag) {
    if (*newOne && *curOne) {
        if ((*newOne)->idPath != (*curOne)->idPath) {
            *flag = 1;
        }
        if ((*newOne)->distPath != (*curOne)->distPath) {
            *flag = 1;
        }
    }
    if (!(*newOne) || !(*curOne)) {
        *flag = 1;
    }
}

static void step(t_path **oldOne, t_path **path, t_path **new) {
    *path = *new;
    *oldOne = (*oldOne)->nextPath;
}

int unique_path(t_path **new, t_path **current) {
    t_path *path = *new;
    t_path *oldOne = *current;
    int flag = -1;

    while (oldOne) {
        if (oldOne->nextConnect == NULL || !path) {
            compare(&path, &oldOne, &flag);
            step(&oldOne, &path, &(*new));

            if (flag == -1) {
                return -1;
            }
            if (oldOne) {
                flag = -1;
            }

            continue;
        }

        compare(&path, &oldOne, &flag);

        path = path->nextConnect;
        oldOne = oldOne->nextConnect;
    }
    
    return flag;
}
