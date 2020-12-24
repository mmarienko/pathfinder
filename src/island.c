#include "../inc/pathfinder.h"

t_island *create_island(int isl, int dist) {
    t_island *node = (t_island *)malloc(1 * sizeof(t_island));

    node->indexIsland = isl;
    node->distTo = dist;
    node->path = NULL;
    node->next = NULL;
    
    return node;
}


static void check_island12(char *island1, char *island2, char *dis, int nline) {
    if (mx_strcmp(island1, island2) == 0 && mx_atoi(dis) != 0) {
        nline++;

        err_invalid_line(nline);
    }
}

static void linearr(char *line, char **island1, char **island2, char **dis) {
    int i = 0;
    char *str = line;
    
    while (str[i] != '-') {
        i++;
    }

    *island1 = mx_strndup(str, i);

    str += i + 1;
    i = 0;

    while (str[i] != ',') {
        i++;
    }

    *island2 = mx_strndup(str, i);

    str += i + 1;
    i = 0;

    while (str[i] != '\0') {
        i++;
    }

    *dis = mx_strndup(str, i);
}

static void fill_islands(char ***arrarr, char **lines, int line) {
    char **arr = *arrarr;
    char *island1 = NULL;
    char *island2 = NULL;
    char *dist = NULL;
    int arr_indicator = 0;

    while (lines[line]) {
        linearr(lines[line], &island1, &island2, &dist);
        check_island12(island1, island2, dist, line);

        arr[arr_indicator++] = mx_strdup(island1);
        mx_strdel(&island1);

        arr[arr_indicator++] = mx_strdup(island2);
        mx_strdel(&island2);

        arr[arr_indicator++] = mx_strdup(dist);
        mx_strdel(&dist);

        for (int i = 0; i < arr_indicator - 3; i += 3) {
            if (mx_strcmp(arr[arr_indicator - 3], arr[i]) == 0 && 
                mx_strcmp(arr[arr_indicator - 2], arr[i + 1]) == 0) {
                err_duplicate_bridges();
            }
            if (mx_strcmp(arr[arr_indicator - 2], arr[i]) == 0 && 
                mx_strcmp(arr[arr_indicator - 3], arr[i + 1]) == 0) {
                err_duplicate_bridges();
            }
        }
        
        line++;
    }
}

void create_arr(char **lines, char ***arrarr) {
    int line = 1;

    while (lines[line]) {
        line++;
    }

    *arrarr = (char **)malloc((line * 3 + 1) * sizeof(char *));
    
    fill_islands(&(*arrarr), lines, 1);
}

void island_pop_front(t_island **head) {
    t_island *p = NULL;
    
    if (!head || !(*head)) {
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);

        *head = NULL;

        return;
    }
    else {
        p = (*head)->next;

        free(*head);
        
        *head = p;
    }
}

static void firs_if (t_island *temp, t_island *leftOne, int index) {
    if (temp && temp->indexIsland == index) {
        if (temp->next) {
            leftOne->next = temp->next;
        }
        else {
            leftOne->next = NULL;
        }

        delete_path(&temp->path);
        free(temp);
        
        temp = NULL;
    }
}

void island_pop_middle(t_island **unvisited, int index) {
    t_island *temp = NULL;
    t_island *leftOne = NULL;

    if (!unvisited || !(*unvisited)) {
        return;
    }
    if ((*unvisited)->indexIsland == index) {
        delete_path(&((*unvisited)->path));
        island_pop_front(&(*unvisited));
    }
    else {
        temp = *unvisited;
        leftOne = temp;

        while (temp != NULL && temp->indexIsland != index) {
            leftOne = temp;
            temp = temp->next;
        }
        
        firs_if (temp, leftOne, index);
    }
}


void pbi(t_island **island, t_path **path, int isl, int dist) {
    t_island *new = create_island(isl, dist);
    t_island *last = *island;

    if (path && *path) {
        new->path = copy_path(&(*path));
    }
    if (*island == NULL) {
        *island = new;

        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new;
    
    return;
}
