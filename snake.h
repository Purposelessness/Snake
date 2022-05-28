#ifndef SNAKECONSOLE_SNAKE_H
#define SNAKECONSOLE_SNAKE_H


#include "data_structures.h"

void reset_snake();

void move_snake(direction_t direction);

point_t snake_head();

int snake_len();

struct points snake_points();

void snake_eat_fruit();


#endif //SNAKECONSOLE_SNAKE_H
