#include "../inc/pathfinder.h"

int **init_h_matrix(t_c_node *bridges, char **islands, size_t n)
{
    int **h_matrix = (int **)malloc((n) * sizeof(int *));

    for (size_t i = 0; i < n; i++)
    {
        h_matrix[i] = (int *)malloc((n) * sizeof(int));
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            h_matrix[i][j] = -1;
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
        h_matrix[i][j] = j;
        h_matrix[j][i] = i;
    }

    return h_matrix;
}
