// list.h
#ifndef LIST_H
#define LIST_H

typedef struct ListNode {
    void *data;
    struct ListNode *next;
} ListNode;

typedef struct {
    ListNode *head;
    ListNode *tail;
    ListNode *current;
} List;

List *list_create();
void list_pushBack(List *list, void *data);
void *list_first(List *list);
void *list_next(List *list);
void list_clean(List *list);

#endif // LIST_H