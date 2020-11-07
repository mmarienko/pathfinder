#include "../inc/pathfinder.h"

char **get_islands_from_bridges(t_c_node *bridges, size_t n) {
    char **islands = (char **)malloc((n) * sizeof(char *));

    for (size_t i = 0; i < n; i++)
    {
        islands[i] = (char *)malloc(sizeof(char));
    }

    int n_island = 0;
    for (t_c_node  *i_node = bridges; i_node != NULL; i_node = i_node->next)
    {
        bool flag_s = false;
        bool flag_d = false;
        for (size_t i = 0; i < n; i++)
        {
            if (mx_strcmp(i_node->src, islands[i]) == 0)
            {
                flag_s = true;
            }
            if (mx_strcmp(i_node->dest, islands[i]) == 0)
            {
                flag_d = true;
            }
        }
        if (flag_s == false)
        {
            islands[n_island] = i_node->src;
            n_island++;
        }
        if (flag_d == false)
        {
            islands[n_island] = i_node->dest;
            n_island++;
        }
    }

    return islands;
}
