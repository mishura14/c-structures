#include "recursion.h"
#include<stdio.h>
//тест факториала
void test_f(){
    if(f(5, 1) == 120){
        printf("Test factorial passed\n");
    }
}
// тест числа фибоначи
void test_fib(){
    if(fib(5) == 5 && fib(10) == 55){
        printf("test fib passed\n");
    }
}


int main(){
    test_f();
    test_fib();
    printf("Тесты пройдены\n");
}
