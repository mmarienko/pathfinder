#include "../inc/libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *))
{
    for (t_list *i_node = lst; i_node != NULL; i_node = i_node->next)
    {
        for (t_list *j_node = lst; j_node != NULL; j_node = j_node->next)
        {
            if (!cmp(i_node->data, j_node->data))
            {
                void *temp = i_node->data;
                i_node->data = j_node->data;
                j_node->data = temp;
            }
        }
    }
    return lst;
}
