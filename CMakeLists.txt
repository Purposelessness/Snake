cmake_minimum_required(VERSION 3.20)
project(SnakeConsole C)

set(CMAKE_C_STANDARD 99)

add_executable(SnakeConsole main.c data_structures.h config.h snake.c snake.h game.c game.h utility.h)
