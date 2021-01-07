#include "../inc/header.h"

void mx_printerror(const char *s) {
    write(STDERR_FILENO, s, mx_strlength(s));
}
