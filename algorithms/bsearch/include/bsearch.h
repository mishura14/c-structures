#include<stddef.h>

//бинарный поиск
void* bsearch(
    const void* key,// указатель на то что ищем
    const void* base,// указательна на начало масива
    size_t n,//размер масива
    size_t size,// размер элемента
    int (*cmp)(const void*, const void*)
);
