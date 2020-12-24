#include "../inc/pathfinder.h"

static void print_invalid(int nline) {
    nline++;

    err_invalid_line(nline);
}

void check_spaces(char **lines, char *file) {
    char *fl = file;
    char **ln = lines;
    int i = 0;
    int len = 0;

    if (*fl == '\n') {
        print_invalid(0);
    }

    while (*fl) {
        if (*fl == '\n' && *(fl + 1) == '\n') {
            while (ln[i]) {
                len = mx_strlen(ln[i]);

                if (mx_strncmp(fl - len, ln[i], mx_strlen(ln[i])) == 0) {
                    print_invalid(i + 1);
                }

                i++;
            }
        }
        
        fl++;
    }
}


void join(char **res, char *s2) {
    char *newstr = mx_strnew(mx_strlen(*res) + mx_strlen(s2));
    int i = 0;
    int si = -1;
    char *s1 = *res;

    while (s1[++si]) {
        newstr[i] = s1[si];
        i++;
    }

    si = -1;

    while (s2[++si]) {
        newstr[i] = s2[si];
        i++;
    }

    mx_strdel(&(*res));
    
    *res = newstr;
}

void parsing(char *fd, int ***matrix, char ***set) {
    char **arrarr = NULL;
    char **src = mx_strsplit(fd, '\n');

    create_arr(src, &arrarr);
    create_set(&(*set), &arrarr, src[0]);

    *matrix = create_matrix(*set, &arrarr);
    
    mx_del_strarr(&src);
    mx_del_strarr(&arrarr);
}

