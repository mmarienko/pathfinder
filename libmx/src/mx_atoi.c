#include "../inc/libmx.h"

int mx_atoi(const char *str) {
    long n = 0;
    int i = 0;
    int ch = 1;

    for ( ; mx_isspace(str[i]); i++);
    if (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            ch = -1;
        i++;
    }
    for( ; mx_isdigit(str[i]); i++) {
        if (ch == -1 && ((n > -(__LONG_MAX__ / 10)) || ((n == -(-__LONG_MAX__ / 10)) 
            && (str[i] - 48 > -(-__LONG_MAX__ % 10)))))
            return 0;
        if ((n > (__LONG_MAX__ / 10)) || ((n == (__LONG_MAX__ / 10)) 
            && str[i] - 48 > __LONG_MAX__ % 10 && ch != -1))
            return -1;
        n = n * 10 + str[i] - 48;
    }
    return ch * n;
}
