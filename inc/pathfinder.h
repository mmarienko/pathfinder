#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

#include <stdio.h>

int get_count_islands(const char *filename, int fd);
t_c_node *get_bridges_from_file(int fd);
char **get_islands_from_bridges(t_c_node *bridges, size_t n);

int **init_w_matrix(t_c_node *bridges, char **islands, size_t n);
int **init_h_matrix(t_c_node *bridges, char **islands, size_t n);
bool **init_rep_matrix(size_t n);
void init_floyds_algorithm(int **w_matrix, int **h_matrix, bool **rep_matrix, size_t n);
void print_shortest(int **w_matrix, int **h_matrix, char **islands, bool **rep_matrix, size_t n);

#endif
