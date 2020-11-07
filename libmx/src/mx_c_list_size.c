#include "../inc/libmx.h"

int mx_c_list_size(t_c_node *list)
{
    int count = 0;

    if (list == NULL)
        return 0;

    if (list->next == NULL)
        return 1;

    for (t_c_node *i_node = list; i_node != NULL; i_node = i_node->next)
    {
        count++;
    }

    return count;
}
