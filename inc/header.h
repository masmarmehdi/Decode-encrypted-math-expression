#ifndef PART_OF_THE_MATRIX_HEADER_H
#define PART_OF_THE_MATRIX_HEADER_H

//libraries that i used
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>


typedef struct  s_list {
    void *data;
    struct s_list *next;
    struct s_list *tail;
}               t_list;

//functions that i have used during this challenge.
char* mx_strncopy(char *dst, const char *src, int len);
char *mx_strnduplicate(const char *s1, int n);
char *mx_newstring(const int size);
char *mx_trimstring(const char *str);
bool mx_isdigit(char c);
int  mx_strlength(const char *str);
void mx_printerror(const char *s);
bool mx_isspace(char c);
void mx_printchar(char c);
void mx_printinteger(int n);
void mx_printstring(const char *s);
char *mx_strsearch(const char *s, int c);
int mx_atoi(char *str, char* original);
int mx_get_char_index(char *str, char c);
char *mx_strduplicate(const char *str);

t_list *mx_create_node(void *data);
void mx_push(t_list **list, void *data);

#endif
