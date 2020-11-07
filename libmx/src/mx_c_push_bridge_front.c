#include "../inc/libmx.h"

void mx_c_push_front(t_c_node **list, void *src, void *dest, void *weight)
{
    t_c_node *new_node = mx_c_create_node(src, dest, weight);
    t_c_node *first_node = *list;

    *list = new_node;
    new_node->next = first_node;
}
