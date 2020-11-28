#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <malloc/malloc.h>
#include <unistd.h>
#include <fcntl.h>

//Utils pack
void mx_printchar(char);
void mx_print_unicode(wchar_t);
void mx_printstr(const char *);
void mx_print_strarr(char **, const char *);
void mx_printint(int);
double mx_pow(double, unsigned int);
int mx_sqrt(int);
char *mx_nbr_to_hex(unsigned long);
unsigned long mx_hex_to_nbr(const char *);
char *mx_itoa(int);
void mx_foreach(int *, int, void (*)(int));
int mx_binary_search(char **, int, const char *, int *);
int mx_bubble_sort(char **, int);
int mx_quicksort(char **, int, int);

//String pack
int mx_strlen(const char *);
void mx_swap_char(char *, char *);
void mx_str_reverse(char *);
void mx_strdel(char **);
void mx_del_strarr(char ***);
int mx_get_char_index(const char *, char);
char *mx_strdup(const char *);
char *mx_strndup(const char *, size_t);
char *mx_strcpy(char *, const char *);
char *mx_strncpy(char *, const char *, int);
int mx_strcmp(const char *, const char *);
char *mx_strcat(char *, const char *);
char *mx_strstr(const char *, const char *);
int mx_get_substr_index(const char *, const char *);
int mx_count_substr(const char *, const char *);
int mx_count_words(const char *, char);
char *mx_strnew(const int);
char *mx_strtrim(const char *);
char *mx_del_extra_spaces(const char *);
char **mx_strsplit(char const *, char);
char *mx_strjoin(char const *, char const *);
char *mx_file_to_str(const char *);
char *mx_replace_substr(const char *, const char *, const char *);
int mx_read_line(char **, size_t, char, const int);
int mx_strncmp(const char *s1, const char *s2, int n);

// Memory pack
void *mx_memset(void *, int, size_t);
void *mx_memcpy(void *, const void *, size_t);
void *mx_memccpy(void *, const void *, int, size_t);//
int mx_memcmp(const void *, const void *, size_t);
void *mx_memchr(const void *, int, size_t);
void *mx_memrchr(const void *, int, size_t);
void *mx_memmem(const void *, size_t, const void *, size_t);
void *mx_memmove(void *, const void *, size_t);
void *mx_realloc(void *, size_t);

// List pack
typedef struct s_list
{
    void *data;
    struct s_list *next;
} t_list;

t_list *mx_create_node(void *);
int mx_list_size(t_list *);
void mx_pop_back(t_list **);
void mx_pop_front(t_list **);
void mx_push_back(t_list **, void *);
void mx_push_front(t_list **, void *);
t_list *mx_sort_list(t_list *, bool (*)(void *, void *));

// Utils
bool mx_isspace(char);
size_t mx_atoi(const char *);
bool mx_isalpha(const char);
bool mx_isdigit(const char);
bool mx_islower(int);
bool mx_isupper(int);
char *mx_strchr(const char *, int);
void mx_printerr(const char *);

