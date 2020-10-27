#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub)
{
    if (str != NULL && sub != NULL)
    {
        int lenght1 = mx_strlen(str); //9
        int lenght2 = mx_strlen(sub); //3

        int more = 0;
        while (more < lenght1 - lenght2  + 1) // < 6
        {
            int count = 0;
            for (int i = more; i < lenght2 + more; i++)
            {
                if (str[i] == sub[i - more])
                {
                    count++;
                }
            }
            if (count == lenght2)
            {
                return more;
            }
            more++;
        }
        return -1;
    }
    return -2;
}

