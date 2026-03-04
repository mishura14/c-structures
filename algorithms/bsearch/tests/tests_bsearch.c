#include "vector.h"
#include "bsearch.h"
#include <time.h>
#include <stdio.h>
int cmp_int(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main(){
    clock_t start = clock();
    int key = 234521324;
    Vector *vector = vector_create(sizeof(int), 100000);
    for (unsigned long long i = 0;i < 1000000000; i++){
        append(vector,&i);
    }
    int* element = bsearch(&key,vector->data,vector->length,vector->element_size, cmp_int);
    clock_t end = clock();
    double time_spent = (double)(end-start)/CLOCKS_PER_SEC;
    if (key == *element){
        printf("element найдет %d\n", *element);
    }

    printf("Binary search time: %.10f seconds\n", time_spent);


    free_vector(vector);
    return 0;
}
