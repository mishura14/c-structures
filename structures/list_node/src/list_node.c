#include<stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *next;
} ListNode;
//функция добавление элемента в связной список
ListNode* addListNode(ListNode * ln, int value)
{
    ListNode *t = malloc(sizeof(ListNode));
    t->data = value;
    t->next = ln;
    return t;
}
//функция удаление элемента в связном списке
ListNode* deleteListNode(ListNode* ln, int value)
{
    ListNode* last = NULL;
    ListNode* next = NULL;
    ListNode* t = ln;

    while(t && (t->data != value)){
        last = t;
        t = t->next;
    }
    if(!t) return ln;

    if(!last){
        next = t->next;
        free(t);
        return next;
    }else{
        last->next = t->next;
        free(t);
        return ln;
    }


}
//фукнция очистки списка
void freeListNode(ListNode* ln)
{
    ListNode* t;
    while(ln){
        t = ln->next;
        free(ln);
        ln = t;
    }
}
