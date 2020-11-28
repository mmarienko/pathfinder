#include "../inc/pathfinder.h"

bool mx_check_isduplicate(t_graph *graph, const char *dup1, const char *dup2) {
    if (!graph || !dup1 || !dup2)
        return false;
    
    int index1 = mx_get_vertex_index(graph, dup1);
    int index2 = mx_get_vertex_index(graph, dup2);

    if (index1 == -1 || index2 == -1)
        return false;

    return graph->dependences[index1][index2] != 0;
}
