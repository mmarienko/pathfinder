#include "../inc/pathfinder.h"

void mx_delete_graph(t_graph **graph) {
    if (!graph || !(*graph))
        return;

    mx_del_strarr(&((*graph)->vertices));

    for (size_t i = 0; i < (*graph)->size; i++) {
        free((*graph)->dependences[i]);
        (*graph)->dependences[i] = NULL;
    }

    free((*graph)->dependences);
    (*graph)->dependences = NULL;

    for (size_t i = 0; i < (*graph)->size; i++) {
        free((*graph)->visited[i]);
        (*graph)->visited[i] = NULL;
    }

    free((*graph)->visited);
    (*graph)->visited = NULL;

    free((*graph));
    (*graph) = NULL;
}
