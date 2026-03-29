#include <stdio.h>
#include <stdlib.h>

typedef struct ListDouble{
    int data;
    struct ListDouble* next;
    struct ListDouble* last;
} ListDouble;

//функция  полного удалениея списка
void freeListDouble(ListDouble* head)
{
    ListDouble* t;
    while(head){
        t = head->next;
        free(head);
        head = t;
    }
}
//функция добавлния в конец списка
ListDouble* addListDouble(ListDouble* head, int data)
{
    ListDouble* node = malloc(sizeof(ListDouble));
    if(!node) return head;
    node->data = data;
    node->next = NULL;
    node->last = NULL;

    if(!head) return node;
    ListDouble* cur = head;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = node;
    node->last = cur;
    return head;
}
//функция удаление элемента по значению
ListDouble* deleteListDouble(ListDouble* head, int value)
{
    ListDouble* cur = head;

    while (cur) {
        if (cur->data == value) {
            if (cur->last)
                cur->last->next = cur->next;
            else
                head = cur->next; // удаляем head

            if (cur->next)
                cur->next->last = cur->last;

            free(cur);
            break;
        }
        cur = cur->next;
    }

    return head;
}
