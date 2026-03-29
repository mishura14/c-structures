typedef struct ListDouble{
    int data;
    struct ListDouble* next;
    struct ListDouble* last;
} ListDouble;

//функция  полного удалениея списка
void freeListDouble(ListDouble* head);

//функция добавлния в конец списка
ListDouble* addListDouble(ListDouble* head, int data);

//функция удаление элемента по значению
ListDouble* deleteListDouble(ListDouble* head, int value);
