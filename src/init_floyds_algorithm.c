#include "../inc/pathfinder.h"

void init_floyds_algorithm(int **w_matrix, int **h_matrix, bool **rep_matrix, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (w_matrix[i][j] != 999)
            {
                if (i == j)
                {
                    continue;
                }
                for (size_t k = 0; k < n; k++)
                {
                    if (i == k)
                    {
                        continue;
                    }
                    if (w_matrix[i][k] == w_matrix[i][j] + w_matrix[j][k])
                    {
                        rep_matrix[i][k] = true;
                        rep_matrix[k][i] = true;
                    }
                    if (w_matrix[i][k] > w_matrix[i][j] + w_matrix[j][k])
                    {
                        w_matrix[i][k] = w_matrix[i][j] + w_matrix[j][k];
                        h_matrix[i][k] = h_matrix[i][j];
                    }
                    
                }
            }
        }
    }
}
