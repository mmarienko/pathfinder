#include "../inc/libmx.h"

t_c_node *mx_sort_c_list(t_c_node *lst, bool (*cmp)(void *, void *))
{
    for (t_c_node *i_node = lst; i_node != NULL; i_node = i_node->next)
    {
        for (t_c_node *j_node = lst; j_node != NULL; j_node = j_node->next)
        {
            if (!cmp(i_node->weight, j_node->weight))
            {
                void *temp = i_node->weight;
                i_node->weight = j_node->weight;
                j_node->weight = temp;
            }
        }
    }
    return lst;
}
