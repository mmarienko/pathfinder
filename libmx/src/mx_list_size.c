#include "../inc/libmx.h"

int mx_list_size(t_list *list)
{
    int count = 0;

    if (list == NULL)
        return 0;

    if (list->next == NULL)
        return 1;

    for (t_list *i_node = list; i_node != NULL; i_node = i_node->next)
    {
        count++;
    }

    return count;
}
