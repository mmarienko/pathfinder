#include "../inc/libmx.h"

void mx_pop_back(t_list **head)
{
    if (head == NULL || *head == NULL)
        return;

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    t_list *before_last_node = NULL;
    t_list *last_node = NULL;

    for (t_list *i_node = *head; i_node != NULL; i_node = i_node->next)
    {
        before_last_node = last_node;
        last_node = i_node;
    }

    before_last_node->next = NULL;

    free(last_node);
    last_node = NULL;
}
