#include "../inc/pathfinder.h"


static void count_err(int count, char *nIslands) {
    if (count == 0 || count != mx_atoi(nIslands) || count == 1) {
        err_invalid_number_of_islands();
    }
}

static int count_set(char **arr, char *nIslands) {
    int count = 0;
    int j = 0;

    if (arr && *arr) {
        if (arr[0]) {
            count++;
        }

        for (int i = 1; arr[i] != NULL; i++) {
            if (mx_isdigit(arr[i][0])) {
                i++;
            }
            if (arr[i] == NULL) {
                break;
            }

            for (j = i - 1; j >= 0; j--) {
                if (mx_strcmp(arr[i], arr[j]) == 0) {
                    break;
                }
                if (j == 0) {
                    count++;
                }
            }
        }
    }

    count_err(count, nIslands);

    return count;
}

static int crflag(char *arr, char **set1) {
    int j = 0;
    int flag = 0;

    while (set1[j]) {
        if (mx_strcmp(arr, set1[j]) == 0) {
            flag++;

            break;
        }

        j++;
    }

    return flag;
}


static void crset(char ***set, char ***arrarr) {
    char **arr = *arrarr;
    char **set1 = *set;
    int i = 0;

    for (int flag = 0; *arr; flag = 0) {
        if (mx_isdigit(**arr)) {
            arr++;
        }
        if (*arr) {
            flag = crflag(*arr, set1);

            if (flag != 0) {
                arr++;

                continue;
            }
            if (flag == 0) {
                set1[i] = mx_strdup(*arr);
                set1[i + 1] = NULL;
                i++;
            }

            arr++;
        }
    }
}

void create_set(char ***set, char ***arrarr, char *nIslands) {
    int count = count_set(*arrarr, nIslands);
    *set = (char **)malloc((count + 1) * sizeof(char *));
    **set = NULL;
    
    crset(&(*set), &(*arrarr));
}

void err_duplicate_bridges() {
    mx_printerr("error: duplicate bridges\n");
    
    exit(0);
}

void err_file_empty(char *filename) {
    mx_printerr("error: file ");
    mx_printerr(filename);
    mx_printerr(" is empty\n");
    
    exit(0);
}

void err_file_not_exist(char *filename) {
    mx_printerr("error: file ");
    mx_printerr(filename);
    mx_printerr(" does not exist\n");
    
    exit(0);
}

void err_first_line_invalid() {
    mx_printerr("error: line 1 is not valid\n");
    
    exit(0);
}

void err_invalid_args() {
    mx_printerr("usage: ./pathfinder [filename]\n");
    
    exit(0);
}

void err_invalid_line(int number_of_line) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(number_of_line));
    mx_printerr(" is not valid\n");
    
    exit(0);
}

void err_invalid_number_of_islands() {
    mx_printerr("error: invalid number of islands\n");
    
    exit(0);
}

void err_length_of_bridges_big() {
    mx_printerr("error: sum of bridges lengths is too big\n");
    
    exit(0);
}


static void print_invalid(int nline)
{
    nline++;

    err_invalid_line(nline);
}

static void checkline(char **lines, int nline)
{
    int i = 0;
    int copy_i = 0;

    for (int n = 1; n <= nline; n++)
    {
        i = 0;
        copy_i = 0;

        while (mx_isalpha(lines[n][i]))
        {
            i++;
        }

        if (i == 0 || lines[n][i] != '-')
        {
            print_invalid(n);
        }

        i++;

        copy_i = i;

        while (mx_isalpha(lines[n][copy_i]))
        {
            copy_i++;
        }

        if (copy_i - i == 0 || lines[n][copy_i] != ',')
        {
            print_invalid(n);
        }

        copy_i++;
        i = copy_i;

        while (mx_isdigit(lines[n][copy_i]))
        {
            copy_i++;
        }

        if (copy_i - i == 0 || lines[n][copy_i] != '\0')
        {
            print_invalid(n);
        }
    }
}

static void parserr(char *file)
{
    char **lines = mx_strsplit(file, '\n');
    int nline = 0;
    int at = 0;

    while (lines[nline])
    {
        nline++;
    }

    if (lines[0][0] == '0')
    {
        err_invalid_number_of_islands();
    }

    while (lines[0][at])
    {
        if (!mx_isdigit(lines[0][at]))
        {
            err_first_line_invalid();
        }

        at++;
    }

    checkline(lines, nline - 1);
    check_spaces(lines, file);
    mx_del_strarr(&lines);
}

void test_err(int argc, char *file, char **argv)
{
    if (argc != 2)
    {
        err_invalid_args();
    }
    if (mx_strcmp(file, "-2") == 0)
    {
        err_file_empty(argv[1]);
    }
    if (mx_strcmp(file, "-1") == 0)
    {
        err_file_not_exist(argv[1]);
    }

    parserr(file);
}

