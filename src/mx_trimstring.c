#include "../inc/header.h"

char *mx_trimstring(const char *str) {
    if (!str)
        return NULL;

    while (mx_isspace(*str))
        str++;

    int len = mx_strlength(str);

    while (mx_isspace(str[len - 1]))
        len--;

    return mx_strnduplicate(str, len);
}
