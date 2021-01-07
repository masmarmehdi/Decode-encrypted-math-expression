#include "../inc/header.h"

inline int mx_get_char_index(char *str, char c) {
    int size = mx_strlength(str);
    for (int i = 0; i < size; i++) {
        if (str[i] == c)
            return i;
    }
    return -1;
}
