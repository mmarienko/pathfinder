#include "../inc/pathfinder.h"

bool mx_check_if_sum_is_too_big(t_graph *graph) {
    size_t sum = 0;

    for (size_t i = 0; i < graph->size; i++)
        for (size_t j = 0; j < graph->size; j++)
            sum += graph->dependences[i][j];

    return sum / 2 > INT_MAX;
}
