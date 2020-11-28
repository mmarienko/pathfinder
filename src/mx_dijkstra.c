#include "../inc/pathfinder.h"

size_t minDistance(size_t dist[], bool sptSet[], size_t size) { 
    size_t min = LONG_MAX, min_index; 
  
    for (size_t v = 0; v < size; v++) 
        if (!sptSet[v] && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  
void printPath(t_graph *graph, int start, int parent[], int j) { 
    if (parent[j] == -1 || !mx_strcmp(graph->vertices[start], graph->vertices[j]))
        return; 

    printPath(graph, start, parent, parent[j]); 
  
    mx_printstr(" -> ");
    mx_printstr(graph->vertices[j]);
}

void printDist(t_graph *graph, int start, int parent[], int j, size_t dist) { 
    if (parent[j] == -1 || !mx_strcmp(graph->vertices[start], graph->vertices[j]))
        return;

    printDist(graph, start, parent, parent[j], dist);

    mx_printint(graph->dependences[parent[j]][j]);

    graph->sum += graph->dependences[parent[j]][j];

    if (graph->sum != dist)
        mx_printstr(" + ");
    else {
        mx_printstr(" = ");
        mx_printint(dist);
    }
}
  
void printSolution(t_graph **graph, int start, size_t dist[], int parent[]) { 
    for (size_t i = 0; i < (*graph)->size; i++) {
        if (!mx_strcmp((*graph)->vertices[start], (*graph)->vertices[i]) || (*graph)->visited[start][i])
            continue;
            
        mx_printstr("========================================\n");

        mx_printstr("Path: ");
        mx_printstr((*graph)->vertices[start]);
        mx_printstr(" -> ");
        mx_printstr((*graph)->vertices[i]);
        mx_printchar('\n');

        mx_printstr("Route: ");
        mx_printstr((*graph)->vertices[start]);
        printPath((*graph), start, parent, i);
        mx_printchar('\n');

        (*graph)->sum = 0;

        mx_printstr("Distance: ");
        if ((*graph)->dependences[start][i] == dist[i])
            mx_printint(dist[i]);
        else
            printDist(*graph, start, parent, i, dist[i]);
        mx_printchar('\n');

        mx_printstr("========================================\n");

        (*graph)->visited[start][i] = true;
        (*graph)->visited[i][start] = true;
    }
} 

void mx_dijkstra(t_graph **graph, const char *src) {
    if (!graph || !src)
        return;

    size_t start = mx_get_vertex_index(*graph, src);
    size_t dist[(*graph)->size];
    bool sptSet[(*graph)->size]; 
    int parent[(*graph)->size]; 

    for (size_t i = 0; i < (*graph)->size; i++) { 
        parent[0] = -1; 
        dist[i] = LONG_MAX;
        sptSet[i] = false; 
    } 
  
    dist[start] = 0;
  
    for (size_t count = 0; count < (*graph)->size - 1; count++) { 
        size_t u = minDistance(dist, sptSet, (*graph)->size); 
        sptSet[u] = true; 

        for (size_t v = 0; v < (*graph)->size; v++) {
            if (!sptSet[v] && (*graph)->dependences[u][v] && dist[u] + (*graph)->dependences[u][v] < dist[v]) { 
                parent[v] = u;
                dist[v] = dist[u] + (*graph)->dependences[u][v];
            } 
        }
    }
    
    printSolution(graph, start, dist, parent); 
}
