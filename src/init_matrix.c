#include "../inc/pathfinder.h"

int **init_matrix(t_bridge *bridges, char **islands, size_t size)
{
    int **matrix = (int **)malloc((size) * sizeof(int *));

    for (size_t i = 0; i < size; i++)
    {
        matrix[i] = (int *)malloc((size) * sizeof(int));
    }

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            matrix[i][j] = 999; //debug
        }
    }

    for (t_bridge *i_node = bridges; i_node != NULL; i_node = i_node->next)
    {
        int i, j;
        for (size_t k = 0; k < size; k++)
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
        matrix[i][j] = mx_atoi(i_node->weight);
        matrix[j][i] = mx_atoi(i_node->weight);
    }

    return matrix;
}
