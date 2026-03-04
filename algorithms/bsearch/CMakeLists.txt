cmake_minimum_required(VERSION 3.10)
project(bsearch_project C)

# --- bsearch как динамическая библиотека ---
add_library(bsearch SHARED
    src/bsearch.c
)
target_include_directories(bsearch PUBLIC
    include
)

# --- тестовый исполняемый файл ---
add_executable(test_bsearch
    tests/tests_bsearch.c
    src/bsearch.c
)

# --- include пути для теста ---
target_include_directories(test_bsearch PRIVATE
    include
    ${CMAKE_SOURCE_DIR}/lib
)

# --- rpath чтобы динамическая библиотека находилась ---
set_target_properties(test_bsearch PROPERTIES
    BUILD_RPATH "$ORIGIN/../lib"
)

# --- линковка с библиотекой vector и math ---
target_link_libraries(test_bsearch PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/libvector.so.1
    m
)
