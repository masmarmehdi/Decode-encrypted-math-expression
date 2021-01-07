#include "../inc/header.h"

char *mx_strnduplicate(const char *s1, int n) {
    char *dup = NULL;
    int length = (size_t)mx_strlength(s1);

    if (n < length) {
        length = n;
    }
    dup = mx_newstring(length);
    mx_strncopy(dup, s1, length);
    return dup;
}
