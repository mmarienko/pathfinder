#include "../inc/libmx.h"

void mx_c_pop_back(t_c_node **head)
{
    if (head == NULL || *head == NULL)
        return;

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    t_c_node *before_last_node = NULL;
    t_c_node *last_node = NULL;

    for (t_c_node *i_node = *head; i_node != NULL; i_node = i_node->next)
    {
        before_last_node = last_node;
        last_node = i_node;
    }

    before_last_node->next = NULL;

    free(last_node);
    last_node = NULL;
}
