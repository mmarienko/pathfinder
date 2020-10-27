#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
	while(*haystack) {
		if(mx_strlen(haystack) >= mx_strlen(needle)) {
			needle = mx_strchr(haystack, *needle);
			if (!haystack) return 0;
			if(mx_strcmp(haystack, needle) == 0)
				return (char*)needle;
			haystack++;
		} else break;
	}
	return 0;
}

