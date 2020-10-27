#include "../inc/libmx.h"

char *mx_itoa(int number) {
    if (number == -2147483648) {
        char* str = "-2147483648";
        return str;
    }
    int check = 0;
    if (number < 0) {
        check = 1;
        number = -number;
    }
    char* str = malloc(12);
    int i = 0;
    while(number > 10) {
        str[i] = (number % 10) + 48;
        number = number / 10;
        i++;
    }
    str[i] = number + 48;
    char* str2;
    if (check) {
        str2 = malloc(i + 3);
        str2[0] = '-';
    } else {
        str2 = malloc(i + 2);
    }
    for (int j = 0; j < i + 1; j++) {
        str2[i - j + check] = str[j];
    }
    mx_strdel(&str);
    str2[i + 1 + check] = '\0';
    return str2;
}

