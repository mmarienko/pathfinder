#include "../inc/pathfinder.h"

int **init_w_matrix(t_c_node *bridges, char **islands, size_t n)
{
    int **w_matrix = (int **)malloc((n) * sizeof(int *));

    for (size_t i = 0; i < n; i++)
    {
        w_matrix[i] = (int *)malloc((n) * sizeof(int));
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            w_matrix[i][j] = 999;
        }
    }

    for (t_c_node *i_node = bridges; i_node != NULL; i_node = i_node->next)
    {
        int i, j;
        for (size_t k = 0; k < n; k++)
        {
            if (mx_strcmp(i_node->src, islands[k]) == 0)
            {
                i = k;
            }
            if (mx_strcmp(i_node->dest, islands[k]) == 0)
            {
                j = k;
            }
        }
        w_matrix[i][j] = mx_atoi(i_node->weight);
        w_matrix[j][i] = mx_atoi(i_node->weight);
    }

    return w_matrix;
}
