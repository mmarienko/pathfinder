#include "../inc/pathfinder.h"

void print_shortest(int **w_matrix, int **h_matrix, char **islands, bool **rep_matrix, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (h_matrix[i][j] != -1 && w_matrix[i][j] != 999)
            {
                int k = n;
                int l = h_matrix[i][j];
                int count = 0;
                int rep = 1;

                while (k > 0)
                {
                    if (rep_matrix[i][l] == true)
                    {
                        rep++;
                    }
                    if (l == (int)j)
                    {
                        int r = h_matrix[i][j];
                        for (size_t m = 0; m <= 40; m++)
                        {
                            mx_printchar('=');
                        }
                        mx_printchar('\n');
                        mx_printstr("Path: ");
                        mx_printstr(islands[i]);
                        mx_printstr(" -> ");
                        mx_printstr(islands[j]);
                        if (rep > 1)
                        {
                            mx_printchar(' ');
                            mx_printstr("(");
                            mx_printstr(mx_itoa(rep));
                            mx_printstr(")");
                        }
                        mx_printchar('\n');
                        mx_printstr("Route: ");
                        mx_printstr(islands[i]);
                        for (size_t m = 0; m < (size_t)count; m++)
                        {
                            mx_printstr(" -> ");
                            mx_printstr(islands[r]);
                            r = h_matrix[r][j];
                        }
                        mx_printstr(" -> ");
                        mx_printstr(islands[j]);
                        mx_printchar('\n');
                        r = h_matrix[i][j];
                        mx_printstr("Distance: ");
                        if (count != 0)
                        {
                            if (w_matrix[i][r] != 999)
                            {
                                mx_printstr(mx_itoa(w_matrix[i][r]));
                            }
                            else
                            {
                                mx_printstr(mx_itoa(w_matrix[r][i]));
                            }

                            for (size_t m = 0; m < (size_t)count; m++)
                            {
                                mx_printstr(" + ");
                                if (w_matrix[h_matrix[r][j]][r] != 999)
                                {
                                    mx_printstr(mx_itoa(w_matrix[h_matrix[r][j]][r]));
                                }
                                else
                                {
                                    mx_printstr(mx_itoa(w_matrix[r][h_matrix[r][j]]));
                                }

                                r = h_matrix[r][j];
                            }
                            mx_printstr(" = ");
                        }
                        mx_printstr(mx_itoa(w_matrix[i][j]));
                        mx_printchar('\n');
                        for (size_t m = 0; m <= 40; m++)
                        {
                            mx_printchar('=');
                        }
                        mx_printchar('\n');
                        w_matrix[j][i] = 999;
                        break;
                    }
                    else if (k > 0)
                    {
                        l = h_matrix[l][j];
                        k--;
                        count++;
                    }
                }
            }
        }
    }
}
