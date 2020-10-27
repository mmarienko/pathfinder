#include "../inc/libmx.h"

void mx_pop_front(t_list **head)
{
    if (head == NULL || *head == NULL)
        return;

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    t_list *first_node = *head;
    t_list *second_node = first_node->next;

    *head = second_node;
    free(first_node);
    first_node = NULL;
}
