#include "../inc/libmx.h"

void mx_c_pop_front(t_c_node **head)
{
    if (head == NULL || *head == NULL)
        return;

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    t_c_node *first_node = *head;
    t_c_node *second_node = first_node->next;

    *head = second_node;
    free(first_node);
    first_node = NULL;
}
