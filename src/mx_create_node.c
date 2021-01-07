#include "../inc/header.h"

inline t_list *mx_create_node(void *data) {
    t_list *newNode = (t_list*) malloc(sizeof(t_list));
    newNode -> next = NULL;
    newNode -> data = data;
    newNode -> tail = newNode;
    return newNode;
}
