#include <stdio.h>
#include "ListNode.h"

void test_addListNode(){
    ListNode *ln = NULL;
    for(int i = 0;i < 10;i++){
        ln =  addListNode(ln, i);
    }
    ListNode* t = ln;
    while(t){
        printf("%d\n",t->data);
        t = t->next;
    }
    printf("тесты на добавление прошел\n");
    freeListNode(ln);
}
void test_deleteListNode(){
    ListNode *ln = NULL;
    for(int i = 0;i < 10;i++){
        ln =  addListNode(ln, i);
    }

    ln = deleteListNode(ln,0);
    ln = deleteListNode(ln,9);
    ln = deleteListNode(ln,5);
    ListNode* t = ln;
    while(t){
        printf("%d\n",t->data);
        t = t->next;
    }
    printf("тесты надо удаление прошел\n");
    freeListNode(ln);
}

int main(){
    test_addListNode();
    test_deleteListNode();
    printf("все тесты прошли");
}
