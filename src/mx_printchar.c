#include "../inc/header.h"

void mx_printchar(char c) {
    write(STDOUT_FILENO, &c, 1);
}