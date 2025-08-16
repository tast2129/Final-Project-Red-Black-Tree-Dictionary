cmake_minimum_required(VERSION 3.10)
project(DictionaryProject)

set(CMAKE_CXX_STANDARD 11)

# If your source files are inside src/
add_executable(dictionary
    code/main.cpp
    code/Dictionary.cpp
    code/RedBlackTree.cpp
)
