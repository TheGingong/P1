cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_C_STANDARD 11)

add_subdirectory(src)
enable_testing()
add_subdirectory(test)
