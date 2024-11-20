add_executable(main main.c)
add_library(main_lib main.c)
target_include_directories(main_lib PUBLIC .)