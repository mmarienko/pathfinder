#include "../inc/pathfinder.h"

size_t mx_get_last_vertex_index(t_graph *graph) {
    if (!graph)
        return 0;

    size_t i = 0;

    while (graph->vertices[i])
        i++;

    return i;
}
