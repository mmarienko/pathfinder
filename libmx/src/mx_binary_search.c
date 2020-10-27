#include "../inc/libmx.h"

int mx_binary_search(char** arr, int size, const char *s, int *count) {
    int r = size - 1;
    int l = 0;
    int counter = 0;
    while (r >= l) {
        counter++;
        int mid = l + (r - l) / 2;
        if (mx_strcmp(arr[mid], s) == 0) {
            *count = counter;
            return mid;
        }
        else {
            if (mx_strcmp(arr[mid], s) == 1) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    *count = 0;
    return -1;
}

