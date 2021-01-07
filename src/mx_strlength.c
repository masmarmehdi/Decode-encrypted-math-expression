int mx_strlength(const char *str) {
    return (*str) ? mx_strlength(++str) + 1 : 0;
}
