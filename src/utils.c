#include "../inc/pathfinder.h"

bool mx_isvalid(const char *from, const char *to, const char *distance) {
    if (!from || !to || !distance)
        return false;

    for (int i = 0; i < mx_strlen(from); i++)
        if (!mx_isalpha(from[i]))
            return false;

    for (int i = 0; i < mx_strlen(to); i++)
        if (!mx_isalpha(to[i]))
            return false;

    for (int i = 0; i < mx_strlen(distance); i++)
        if (!mx_isdigit(distance[i]))
            return false;

    if (mx_strcmp(from, to) == 0)
        return false;

    return true;
}



