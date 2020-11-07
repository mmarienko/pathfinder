#include "../inc/libmx.h"

void mx_free_int_matrix(int **matrix, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}
