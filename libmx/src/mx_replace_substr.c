#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
	size_t cache_sz_inc = 16;
	const size_t cache_sz_inc_factor = 3;
	const size_t cache_sz_inc_max = 1048576;

	char *pret, *ret = NULL;
	const char *pstr2, *pstr = str;
	size_t i, count = 0;
	#if (__STDC_VERSION__ >= 199901L)
	uintptr_t *pos_cache_tmp, *pos_cache = NULL;
	#endif
	size_t cache_sz = 0;
	size_t cpylen, orglen, retlen, tolen, fromlen = mx_strlen(sub);
	while ((pstr2 = mx_strstr(pstr, sub)) != NULL) {
		count++;

		/* Increase the cache size when necessary. */
		if (cache_sz < count) {
			cache_sz += cache_sz_inc;
			pos_cache_tmp = mx_realloc(pos_cache, sizeof(*pos_cache) * cache_sz);
			if (pos_cache_tmp == NULL) {
				free(pos_cache);
				return ret;
			} else pos_cache = pos_cache_tmp;
			cache_sz_inc *= cache_sz_inc_factor;
			if (cache_sz_inc > cache_sz_inc_max) {
				cache_sz_inc = cache_sz_inc_max;
			}
		}

		pos_cache[count-1] = pstr2 - str;
		pstr = pstr2 + fromlen;
	}

	orglen = pstr - str + mx_strlen(pstr);
	if (count > 0) {
		tolen = mx_strlen(replace);
		retlen = orglen + (tolen - fromlen) * count;
	} else	retlen = orglen;
	ret = mx_strnew(retlen);
	if (ret == NULL) {
		free(pos_cache);
		return ret;
	}

	if (count == 0) {
		mx_strcpy(ret, str);
	} else {
		pret = ret;
		mx_memcpy(pret, str, pos_cache[0]);
		pret += pos_cache[0];
		for (i = 0; i < count; i++) {
			mx_memcpy(pret, replace, tolen);
			pret += tolen;
			pstr = str + pos_cache[i] + fromlen;
			cpylen = (i == count-1 ? orglen : pos_cache[i+1]) - pos_cache[i] - fromlen;
			mx_memcpy(pret, pstr, cpylen);
			pret += cpylen;
		}
		ret[retlen] = '\0';
	}
	free(pos_cache);
	return ret;
}

