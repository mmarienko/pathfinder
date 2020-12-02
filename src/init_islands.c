#include "../inc/pathfinder.h"

char **init_islands(t_bridge *bridges, size_t size) {
    char **islands = (char **)malloc((size) * sizeof(char *));

    for (size_t i = 0; i < size; i++)
    {
        islands[i] = (char *)malloc(sizeof(char));
    }

    int n_island = 0;
    for (t_bridge  *i_node = bridges; i_node != NULL; i_node = i_node->next)
    {
        bool flag_s = false;
        bool flag_d = false;
        for (size_t i = 0; i < size; i++)
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
