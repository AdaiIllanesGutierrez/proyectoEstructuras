// list.c
#include "list.h"
#include <stdlib.h>

List *list_create() {
    List *list = (List *)malloc(sizeof(List));
    list->head = list->tail = list->current = NULL;
    return list;
}

void list_pushBack(List *list, void *data) {
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    new_node->data = data;
    new_node->next = NULL;
    if (list->tail) {
        list->tail->next = new_node;
        list->tail = new_node;
    } else {
        list->head = list->tail = new_node;
    }
}

void *list_first(List *list) {
    list->current = list->head;
    return list->current ? list->current->data : NULL;
}

void *list_next(List *list) {
    if (list->current) {
        list->current = list->current->next;
        return list->current ? list->current->data : NULL;
    }
    return NULL;
}

void list_clean(List *list) {
    ListNode *current = list->head;
    while (current) {
        ListNode *to_free = current;
        current = current->next;
        free(to_free);
    }
    free(list);
}