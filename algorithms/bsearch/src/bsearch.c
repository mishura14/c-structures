#include <stddef.h>

//бинарный поиск
void* bsearch(
    const void* key,// указатель на то что ищем
    const void* base,// указательна на начало масива
    size_t n,// размер масива
    size_t size,// размер элемента
    int (*cmp)(const void*, const void*)
){
    size_t left = 0;
    size_t right = n;

    while ( left < right){
        size_t mid = left + (right - left) / 2;

        const void* element = (const char*)base + mid * size;

        int result = cmp(key, element);

        if (result == 0){
            return (void*)element;//нашли
        }else if (result < 0) {
            right = mid;//ищем в лево
        }else{
            left = mid + 1;// ищем в право
        }
    }
    return NULL;
}
