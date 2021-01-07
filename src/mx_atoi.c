#include "../inc/header.h"

int mx_atoi(char *str, char *original) {
    int start = -1;
    int end = -1;
    int minus = 0;
    int res = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] == '-') && ((mx_isdigit(str[i + 1]) == true) || (str[i + 1] == '?'))) {
            minus = 1;
            continue;
        }
        if ((mx_isdigit(str[i]) == false ) && str[i] != '?') {
            mx_printerror("Invalid operand: ");
            mx_printerror(original); 
            mx_printerror("\n");
            free(str);

            exit(EXIT_FAILURE);
        }
        if ((mx_isspace(str[i]) == false) && (start == -1))
            start = i;
        if ((start > -1) && (mx_isdigit(str[i]) == false) && (end == -1))
            end = i;
    }
    if (end == -1)
        for (int i = start; str[i] != '\0'; i++)
            res = 10 * res + (int)str[i] - 48;
    else
        for (int i = start; i < end; i++)
            res = 10 * res + (int)str[i] - 48;
    return minus == 0 ? res : -1 * res;
}
