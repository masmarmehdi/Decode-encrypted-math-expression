#include "../inc/header.h"

#define FOR(I, VAL) for(int I = 0; I< VAL; ++I)

//Checking wether the whole operation is valid.
static char *validate_operator(char* operator) {
    char *trimmed_string = mx_trimstring(operator);
    if (! trimmed_string || mx_strlength(trimmed_string) != 1) {
        mx_printerror("Invalid operation: ");
        mx_printerror(operator);
        mx_printerror("\n");
        free(trimmed_string);

        exit(EXIT_FAILURE);
    }

    if (! ((trimmed_string[0] == '+') || (trimmed_string[0] == '-') || (trimmed_string[0] == '*') || (trimmed_string[0] == '/') || (trimmed_string[0] == '?'))) {
        mx_printerror("Invalid operation: ");
        mx_printerror(operator);
        mx_printerror("\n");
        free(trimmed_string);

        exit(EXIT_FAILURE);
    }

    return trimmed_string;
}
//checking wether the operands are valid or not.
static char* validate_operand(char* operand) {
    char *trimmed_string = mx_trimstring(operand);
    if (! trimmed_string || mx_strlength(trimmed_string) == 0) {
        mx_printerror("Invalid operand: ");
        mx_printerror(operand);
        mx_printerror("\n");
        free(trimmed_string);

        exit(EXIT_FAILURE);
    }

    int value = mx_atoi(trimmed_string, operand);
    (void) value;
    return trimmed_string;
}
//checking wether the result is valid or not.
static char* validate_result(char* result) {
    char *trimmed_string = mx_trimstring(result);
    if (! trimmed_string || mx_strlength(trimmed_string) == 0) {
        mx_printerror("Invalid result: ");
        mx_printerror(result);
        mx_printerror("\n");
        free(trimmed_string);

        exit(EXIT_FAILURE);
    }

    int value = mx_atoi(trimmed_string, result);
    (void) value;
    return trimmed_string;
}

static void generate_possible(char *current, t_list **all) {
    if (! current) {
        return;
    }

    int pos = mx_get_char_index(current, '?');
    if (pos > -1) {
        char *replace = mx_strduplicate(current);
        FOR(i, 10) {
            replace[pos] = i +'0';
            generate_possible(replace, all);
        }
        free(replace);
    } else {
        mx_push(all, mx_strduplicate(current));
    }
}

static void print_valid(char* first, char *operator, char* second, char* result) {
    mx_printinteger(mx_atoi(first, NULL));
    mx_printstring(" ");
    mx_printstring(operator);
    mx_printstring(" ");
    mx_printinteger(mx_atoi(second, NULL));
    mx_printstring(" = ");
    mx_printinteger(mx_atoi(result, NULL));
    mx_printstring("\n");
}

//the process og the operators "+,-,* and /"
static void process__of_the_operator(char* first, char *operator, char* second, char* result) {
    int first_value = mx_atoi(first, NULL);
    int second_value = mx_atoi(second, NULL);
    int result_value = mx_atoi(result, NULL);

    switch (operator[0]) {
        case '+':
            if (first_value + second_value == result_value) {
                print_valid(first, operator, second, result);
            }
            break;
        case '-':
            if (first_value - second_value == result_value) {
                print_valid(first, operator, second, result);
            }
            break;
        case '*':
            if (first_value * second_value == result_value) {
                print_valid(first, operator, second, result);
            }
            break;
        case '/':
            if ((int) (first_value / (double) second_value) == result_value) {
                print_valid(first, operator, second, result);
            }
            break;
    }
}

void mx_clear_list(t_list **list) {
    if (!*list) return;
    t_list *temp = NULL;
    while (*list) {
        if ((*list)->data){
            free((*list)->data);
            (*list)->data = NULL;
        }

        temp = (*list) -> next;
        (*list) -> next = NULL;
        free(*list);
        *list = temp;
    }
}

int main(int argc, char **argv) {
    if (argc != 5) {//this means that we need to input 5 command argument which are : first operand , operator , second operand and result.
        mx_printerror("usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]\n");
        exit(EXIT_FAILURE);
    }

    char *first_operand, *operator, *second_operand, *result;
    operator = validate_operator(argv[2]);//the operator took the 3rd place in the execution.(after ./part_of_the_matrix and the first operand).
    first_operand = validate_operand(argv[1]);//the first operand took the 2nd place in the execution.(after ./part_of_the_matrix).
    second_operand = validate_operand(argv[3]);//the second operand took the 4th place in the execution.(after ./part_of_the_matrix,first operand,operator).
    result = validate_result(argv[4]);// the result took the 5th place int the execution.(after all in the above).

    t_list *possible_first_operands = NULL;
    t_list *possible_second_operands = NULL;
    t_list *possible_results = NULL;
    if (! mx_strsearch(first_operand, '?')) {
        possible_first_operands = mx_create_node(first_operand);
    } else {
        generate_possible(first_operand, &possible_first_operands);
    }

    if (! mx_strsearch(second_operand, '?')) {
        possible_second_operands = mx_create_node(second_operand);
    } else {
        generate_possible(second_operand, &possible_second_operands);
    }

    if (! mx_strsearch(result, '?')) {
        possible_results = mx_create_node(result);
    } else {
        generate_possible(result, &possible_results);
    }

    char *operators[] = {"+", "-", "*", "/", NULL};//the oprators that exists.

    char *c_operator;
    FOR(I, 4) {
        if (operator[0] == '?') {
            c_operator = operators[I];
        } else if (I == 0) {
            c_operator = operator;
        } else {
            break;
        }


        t_list *fcarret = possible_first_operands;
        while (fcarret) {
            t_list *scarret = possible_second_operands;
            while (scarret) {
                t_list *rcarret = possible_results;
                while (rcarret) {
                    process__of_the_operator(fcarret->data, c_operator, scarret->data, rcarret->data);
                    rcarret = rcarret->next;
                }

                scarret = scarret->next;
            }

            fcarret = fcarret->next;
        }
    }

    free(operator);
    operator = NULL;
    mx_clear_list(&possible_first_operands);
    mx_clear_list(&possible_second_operands);
    mx_clear_list(&possible_results);
    return 0;
}
