#include "../inc/header.h"

void mx_push(t_list **list, void *data) {
    if (!list) return;
    if ((!*list) || !(*list)->data) {
        *list = mx_create_node(data);
        return;
    }

    (*list)->tail->next = mx_create_node(data);
    (*list)->tail = (*list)->tail->next;
}
