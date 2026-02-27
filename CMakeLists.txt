#минимальная версия Cmake
cmake_minimum_required(VERSION 3.20)

#имя проетка, язык и версия
project(c-structures VERSION 1.0 LANGUAGES C)

#стандарт языка
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)


#==============добавления библиотек==============

#---------библиотека vector--------------
add_library(vector SHARED
    structures/vector/src/vector.c
)
#путь к заголовочному файлу
target_include_directories(vector PUBLIC
    structures/vector/include
)
#версия библиотеки
set_target_properties(vector PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

#----------библиотека bitVector-------------
add_library(bitVector SHARED
    structures/bitVector/src/bitVector.c
)
#путь к заголовочному файлу
target_include_directories(bitVector PUBLIC
    structures/bitVector/include
)
#версия библиотеки
set_target_properties(bitVector PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

#----------библиотека listDouble-------------
add_library(listDouble SHARED
    structures/ListDouble/src/ListDouble.c
)
#путь к заголовочному файлу
target_include_directories(listDouble PUBLIC
    structures/ListDouble/include
)
#версия библиотеки
set_target_properties(listDouble PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

#----------библиотека single_linked-------------
add_library(single_linked SHARED
    structures/Single-linked/src/list_node.c
)
#путь к заголовочному файлу
target_include_directories(single_linked PUBLIC
    structures/Single-linked/include
)
#версия библиотеки
set_target_properties(single_linked PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

#----------библиотека string-------------
add_library(string SHARED
    structures/my_string_libmy/src/my_string.c
)
#путь к заголовочному файлу
target_include_directories(string PUBLIC
    structures/my_string_libmy/include
)
#версия библиотеки
set_target_properties(string PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

#----------c-structures--------------------
add_library(c-structures SHARED
    structures/vector/src/vector.c
    structures/bitVector/src/bitVector.c
    structures/ListDouble/src/ListDouble.c
    structures/Single-linked/src/list_node.c
    structures/my_string_libmy/src/my_string.c
)
#путь к заголовочному файлу
target_include_directories(c-structures PUBLIC
    structures/vector/include
    structures/bitVector/include
    structures/ListDouble/include
    structures/Single-linked/include
    structures/my_string_libmy/include
)
#версия библиотеки
set_target_properties(c-structures PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

#========test===============

#------------тест vector-------------------
add_executable(tests_vector
    tests/tests_vector/tests_vector.c
)
target_link_libraries(tests_vector PRIVATE vector)

#------------тест bitVector-------------------
add_executable(tests_bitVector
    tests/tests_bitVector/tests_bitVector.c
)
target_link_libraries(tests_bitVector PRIVATE bitVector)

#-------------тест ListDouble-------------------
add_executable(tests_listDouble
    tests/tests_ListDouble/tests_ListDouble.c
)
target_link_libraries(tests_listDouble PRIVATE listDouble)

#-------------тест single-linked-------------
add_executable(tests_single-linked
    tests/tests_single-linked/tests_single-linked.c
)
target_link_libraries(tests_single-linked PRIVATE single-linked)

#--------------тест string--------------------
add_executable(tests_string
    tests/tests_string/tests_string.c
)
target_link_libraries(tests_string PRIVATE string)
