# реализация Vector на C
Для сборки библиотеки нужно
создать папку build
```
mkdir build
```
нужно в нее перейти 
```
cd build
```
и выполнить команды
```
cmake ..
cmake --build .
```
В моем vector реализовны следующие методы:
- append
  ```c
    void append(Vector *v, const void *value);
  ```
- get
  ```c
    void *get(const Vector *v, size_t index);
  ```
- set
  ```c
    void set(Vector *v, size_t index, const void *value);
  ```
- insert
  ```c
    void insert(Vector *v, size_t index, const void *value);
  ```
- erase
  ```c
    void erase(Vector *v, size_t index);
  ```
- clear
  ```c
    void clear(Vector *v);
  ```
- reserve
  ```c
    void reserve(Vector *v, size_t new_capacity);
  ```
- free_vector
  ```c
    void free_vector(Vector *v);
  ```
- create_vector
  ```c
    Vector *create_vector(size_t element_size);
  ```
Это базовый набор методов для работы с вектором.
