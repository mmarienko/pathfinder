#include "../inc/pathfinder.h"

int mx_get_vertex_index(t_graph *graph, const char *find) {
    if (!graph || !find)
        return -2;

    for (size_t i = 0; i < graph->size; i++)
        if (graph->vertices[i])
            if (!mx_strcmp(graph->vertices[i], find))
                return i;

    return -1;
}
