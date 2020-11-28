#include "../inc/pathfinder.h"

t_graph *mx_create_graph(size_t size) {
    if (size == 0)
        return NULL;
    
    t_graph *newgraph = (t_graph *) malloc(sizeof(t_graph));

    if (!newgraph)
        return NULL;

    newgraph->sum = 0;
    newgraph->size = size;
    newgraph->vertices = (char **) malloc(sizeof(char *) * (newgraph->size + 1)); // + 1 for make it NULL-terminated

    if (!newgraph->vertices)
        return NULL;

    for (size_t i = 0; i <= newgraph->size; i++)
        newgraph->vertices[i] = NULL;

    newgraph->dependences = (size_t **) malloc(sizeof(size_t *) * newgraph->size);

    if (!newgraph->dependences)
        return NULL;

    for (size_t i = 0; i < newgraph->size; i++) {
        newgraph->dependences[i] = (size_t *) malloc(sizeof(size_t) * newgraph->size);

        if (!newgraph->dependences[i])
            return NULL;
        
        for (size_t j = 0; j < newgraph->size; j++)
            newgraph->dependences[i][j] = 0;
    }

    newgraph->visited = (bool **) malloc(sizeof(bool *) * newgraph->size);

    if (!newgraph->visited)
        return NULL;

    for (size_t i = 0; i < newgraph->size; i++) {
        newgraph->visited[i] = (bool *) malloc(sizeof(bool) * newgraph->size);

        if (!newgraph->visited[i])
            return NULL;
        
        for (size_t j = 0; j < newgraph->size; j++)
            newgraph->visited[i][j] = false;
    }

    return newgraph;
}
