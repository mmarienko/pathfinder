#include "../inc/libmx.h"

t_c_node *mx_c_create_node(void *src, void *dest, void *weight)
{
    t_c_node *new_node = (t_c_node *)malloc(sizeof(t_c_node));
    new_node->src = src;
    new_node->dest = dest;
    new_node->weight = weight;
    new_node->next = NULL;

    return new_node;
}
