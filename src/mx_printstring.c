#include "../inc/header.h"

void mx_printstring(const char *s) {
	write(1, s, mx_strlength(s));
}
