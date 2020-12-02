#include "../inc/pathfinder.h"

size_t mx_bridge_size(t_bridge *list)
{
    if (!list)
        return 0;

    if (list->next == NULL)
        return 1;

    int count = 0;

    for (t_bridge *i_node = list; i_node != NULL; i_node = i_node->next)
    {
        count++;
    }

    return count;
}

t_bridge *mx_create_bridge(void *src, void *dest, void *weight)
{
    if (!src || !dest || !weight)
        return NULL;

    t_bridge *new_node = (t_bridge *)malloc(sizeof(t_bridge));

    if (!new_node)
        return NULL;

    new_node->src = src;
    new_node->dest = dest;
    new_node->weight = weight;
    new_node->next = NULL;

    return new_node;
}

void mx_pop_bridge_back(t_bridge **head)
{
    if (!head || !(*head))
        return;

    if (!((*head)->next))
    {
        free(*head);
        *head = NULL;
        return;
    }

    t_bridge *before_last_node = NULL;
    t_bridge *last_node = NULL;

    for (t_bridge *i_node = *head; i_node != NULL; i_node = i_node->next)
    {
        before_last_node = last_node;
        last_node = i_node;
    }

    before_last_node->next = NULL;

    free(last_node);
    last_node = NULL;
}

void mx_pop_bridge_front(t_bridge **head)
{
    if (head == NULL || *head == NULL)
        return;

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    t_bridge *first_node = *head;
    t_bridge *second_node = first_node->next;

    *head = second_node;
    free(first_node);
    first_node = NULL;
}

void mx_push_bridge_back(t_bridge **list, void *src, void *dest, void *weight)
{
    if (!src || !dest || !weight)
        return;

    t_bridge *new_node = mx_create_bridge(src, dest, weight);

    if (!list || !(*list))
    {
        (*list) = new_node;
        return;
    }

    t_bridge *last_node = (*list);

    while (last_node->next)
        last_node = last_node->next;

    last_node->next = new_node;
}

void mx_push_bridge_front(t_bridge **list, void *src, void *dest, void *weight)
{
    if (!src || !dest || !weight)
        return;

    t_bridge *new_node = mx_create_bridge(src, dest, weight);
    t_bridge *first_node = *list;

    *list = new_node;
    new_node->next = first_node;
}

t_bridge *mx_sort_bridge(t_bridge *list, bool (*cmp)(void *, void *))
{
    if (!list || !cmp) 
        return list;

    int size = mx_bridge_size(list);

    for (int i = 0; i < size; i++) {
        t_bridge *temp = list;

        for (int j = 0; j < size - 1; j++) {
            if (cmp(temp->weight, temp->next->weight)) {
                void *weight = temp->weight; 
                temp->weight = temp->next->weight; 
                temp->next->weight = weight;     
            }

            temp = temp->next;
        }
    }

    return list;
}

t_bridge *mx_free_bridge(t_bridge *list)
{
    if (!list)
        return NULL;

    t_bridge *head = list->next;

    while (head)
    {
        t_bridge *temp = head;
        head = head->next;

        free(temp->src);
        free(temp->dest);
        free(temp->weight);
        free(temp);
    }

    free(list->src);
    free(list->dest);
    free(list->weight);

    list->next = NULL;

    return list;
}
