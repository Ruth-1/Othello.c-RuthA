cmake_minimum_required(VERSION 3.17)
project(Othello C)

set(CMAKE_C_STANDARD 11)

add_executable(Othello main.c boardchanges.c boardchanges.h boolFunc.c boolFunc.h globalVar.h voidFunc.c voidFunc.h)