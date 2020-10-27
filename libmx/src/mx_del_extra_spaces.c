#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str)
{
    if (str == NULL)
        return NULL;
    char *trimmed = mx_strtrim(str);
    int j = 0;
    char *nospaces = mx_strnew(mx_strlen(trimmed));
    if (nospaces == NULL)
        return NULL;
    for (int i = 0; i < mx_strlen(trimmed); i++)
    {
        if (!mx_isspace(trimmed[i]))
        {
            nospaces[j] = trimmed[i];
            j++;
        }
        else if (mx_isspace(trimmed[i]) && !mx_isspace(trimmed[i + 1]))
        {
            nospaces[j] = ' ';
            j++;
        }
        else if (mx_isspace(trimmed[i]))
        {
            while (mx_isspace(trimmed[i + 1]))
            {
                i++;
            }
            nospaces[j] = trimmed[i];
            j++;
        }
    }
    mx_strdel(&trimmed);
    return nospaces;
}

