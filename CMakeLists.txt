cmake_minimum_required(VERSION 3.27)
project(Projet_Langage_C C)

set(CMAKE_C_STANDARD 11)

add_executable(Projet_Langage_C main.c
        column.c
        column.h
        cdataframe.c
        cdataframe.h
        menu.c
        menu.h)
