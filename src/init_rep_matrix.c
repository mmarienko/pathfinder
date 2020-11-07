#include "../inc/pathfinder.h"

bool **init_rep_matrix(size_t n)
{
    bool **rep_matrix = (bool **)malloc((n) * sizeof(bool *));

    for (size_t i = 0; i < n; i++)
    {
        rep_matrix[i] = (bool *)malloc((n) * sizeof(bool));
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            rep_matrix[i][j] = false;
        }
    }

    return rep_matrix;
}
