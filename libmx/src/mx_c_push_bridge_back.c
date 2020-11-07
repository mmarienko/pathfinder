#include "../inc/libmx.h"

void mx_c_push_back(t_c_node **list, void *src, void *dest, void *weight)
{
    t_c_node *new_node = mx_c_create_node(src, dest, weight);

    if (list == NULL || *list == NULL)
    {
        *list = new_node;
        return;
    }

    t_c_node *last_node = NULL;

    for (t_c_node *i_node = *list; i_node != NULL; i_node = i_node->next)
    {
        last_node = i_node;
    }

    last_node->next = new_node;
}
