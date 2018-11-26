cmake_minimum_required(VERSION 3.12)
project(project_aed_lp C)

set(CMAKE_C_STANDARD 11)

add_executable(project_aed_lp main.c
                project/maze.h
                libs/strings_kmp.c
                libs/strings_kmp.h
                libs/lib_util.c
                libs/lib_util.h
                project/matrix.c
                project/matrix.h
                project/maze.c
                project/maze.c
                project/fase1.c
                project/fase1.h
                project/fase2.c
                project/fase2.h
                libs/client_string_sort.c
                libs/client_string_sort.h
                libs/stringsorting.c
                libs/stringsorting.h)