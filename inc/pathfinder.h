#pragma once

#include "../libmx/inc/libmx.h"
#include "limits.h"

#include "stdio.h" //debug

typedef struct s_bridge
{
    void *src;
    void *dest;
    void *weight;
    struct s_bridge *next;
} t_bridge;

char **init_islands(t_bridge *bridges, size_t size);
int **init_matrix(t_bridge *bridges, char **islands, size_t size);
bool mx_isvalid(const char *from, const char *to, const char *distance);

t_bridge *mx_create_bridge(void *src, void *dest, void *weight);
size_t mx_bridge_size(t_bridge *list);
void mx_pop_bridge_back(t_bridge **list);
void mx_pop_bridge_front(t_bridge **list);
void mx_push_bridge_back(t_bridge **list, void *src, void *dest, void *weight);
void mx_push_bridge_front(t_bridge **list, void *src, void *dest, void *weight);
t_bridge *mx_sort_bridge(t_bridge *, bool (*)(void *, void *));
t_bridge *mx_free_bridge(t_bridge *list);
