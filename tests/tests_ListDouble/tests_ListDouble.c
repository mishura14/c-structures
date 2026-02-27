#include "list_double.h"
#include <stdio.h>

void test_addListNode(){
    ListDouble *ln = NULL;
    for(int i = 0;i < 10;i++){
        ln =  addListDouble(ln, i);
    }
    ListDouble* t = ln;
    while(t){
        printf("%d\n",t->data);
        t = t->next;
    }
    printf("тесты на добавление прошел\n");
    freeListDouble(ln);
}
void test_deleteListNode(){
    ListDouble *ln = NULL;
    for(int i = 0;i < 10;i++){
        ln =  addListDouble(ln, i);
    }

    ln = deleteListDouble(ln,0);
    ln = deleteListDouble(ln,9);
    ln = deleteListDouble(ln,5);
    ListDouble* t = ln;
    while(t){
        printf("%d\n",t->data);
        t = t->next;
    }
    printf("тесты надо удаление прошел\n");
    freeListDouble(ln);
}

int main(){
    test_addListNode();
    test_deleteListNode();
    printf("все тесты прошли");
}
