
# минимальная версия CMake
cmake_minimum_required(VERSION 3.20)

# имя проекта, язык и версия
project(Vector VERSION 1.0.0 LANGUAGES C)

# стандарт C
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# ========== библиотека ==========
add_library(vector SHARED
    src/vector.c
)

# путь к заголовкам
target_include_directories(vector PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# версия библиотеки (для .so)
set_target_properties(vector PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)

# ========== тесты ==========
add_executable(tests_vector
    tests/vector_tests.c
)

target_link_libraries(tests_vector PRIVATE
    vector
)
