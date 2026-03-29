#include<stdlib.h>

typedef struct ListNode{
    int data;
    struct ListNode *next;
} ListNode;
//функция добавление элемента в связной список
ListNode* addListNode(ListNode * ln, int value);

//функция удаление элемента в связном списке
ListNode* deleteListNode(ListNode* ln, int value);

//фукнция очистки списка
void freeListNode(ListNode* ln);
