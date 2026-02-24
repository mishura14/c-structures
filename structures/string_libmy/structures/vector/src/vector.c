#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct{
    void *data;
    size_t capacity;
    size_t element_size;
    size_t length;

}Vector;
//метод создания вектора
Vector *vector_create(size_t element_size, size_t capacity)
{
    Vector* v = malloc(sizeof *v);
    if(!v) return NULL;
    v->data = malloc(capacity * element_size);
    if(!v->data){
        free(v);
        return NULL;
    }
    v->capacity = capacity;
    v->element_size = element_size;
    v->length = 0;
    return v;
};
//метод очистки вектора из памяти
void free_vector(Vector *v)
{
    free(v->data);
    free(v);
}
//метод добавление элеметов в конец вектора
void append(Vector *v, const void *value)
{
    if (v->length >= v->capacity) {
        v->capacity = (v->capacity == 0) ? 2 : v->capacity * 2;

        v->data = realloc(v->data, v->capacity * v->element_size);
        if (!v->data) {
            perror("realloc");
            exit(1);
        }
    }

    memcpy(
        (char *)v->data + v->length * v->element_size,
        value,
        v->element_size
    );

    v->length++;
}
//метод удаление элемента из конца вектора
void pop(Vector *v,void *back_element)
{
    if(v->length == 0){
        return;
    }
    v->length--;
    if(back_element){
        memcpy(back_element,(char *)v->data + v->length * v->element_size, v->element_size);
    }

}
//метод get возвращающий указатель на элемент по индексу
void* get(Vector *v, size_t index)
{
    if(index >= v->length){
        return NULL;
    }
    return (char*)v->data + index * v->element_size;
}

// метод set перезаписывающий элемент по индексу
void set(Vector *v, size_t index,const void *value)
{
    if(index >= v->length){
        return;
    }
    memcpy((char *)v->data + index * v->element_size,value,v->element_size);
}

// метод erase удалающий элемент по индексу
void erase(Vector *v, size_t index)
{
    if (index >= v->length) {
        return; // защита от выхода за границы
    }

    // если удаляем не последний элемент — сдвигаем
    if (index < v->length - 1) {
        memmove(
            (char *)v->data + index * v->element_size,
            (char *)v->data + (index + 1) * v->element_size,
            (v->length - index - 1) * v->element_size
        );
    }

    v->length--;
}

// метод clear очищающий элементы вектора но не удалая его самово
void clear(Vector *v)
{
    if (!v) return;
    v->length = 0;
}



// метод reserve увеличивающий capacity вектора
void reserve(Vector *v, size_t new_capacity)
{
    if (new_capacity <= v->capacity) {
        return;
    }

    void *new_data = realloc(v->data, new_capacity * v->element_size);
    if (!new_data) {
        perror("realloc");
        return;
    }

    v->data = new_data;
    v->capacity = new_capacity;
}


// insert вставка по индексу
void insert(Vector *v,size_t index,const void *value)
{
    if (index > v->length){
        return;
    }
    if(v->length >= v->capacity){
        v->capacity = (v->capacity == 0) ? 2 : v->capacity * 2;
        void *new_data = realloc(v->data, v->capacity * v->element_size);
        if(!new_data){
            perror("realloc");
            return;
        }
        v->data = new_data;
    }
    memmove(
        (char *)v->data + (index + 1) * v->element_size,
        (char *)v->data + index * v->element_size,
        (v->length - index) * v->element_size
    );
    memcpy(
        (char *)v->data + index * v->element_size,
        value,
        v->element_size
    );
    v->length++;

}
