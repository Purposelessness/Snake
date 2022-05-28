#include <string.h>
#include "snake.h"

int len;
int size;
point_t pos[MAX_SNAKE_LEN] = {};

void reset_snake() {
    len = 1;
    size = 1;
    pos[0].x = WIDTH / 2;
    pos[0].y = HEIGHT / 2;
}

point_t snake_head() {
    return pos[0];
}

void move_snake(direction_t direction) {
    memmove(&pos[1], &pos[0], sizeof(*pos) * size);

    switch (direction) {
        case TOP:
            --pos[0].y;
            break;
        case LEFT:
            --pos[0].x;
            break;
        case BOTTOM:
            ++pos[0].y;
            break;
        case RIGHT:
            ++pos[0].x;
            break;
        case NONE:
        default:
            break;
    }
}

struct points snake_points() {
    struct points p = {.data = pos, .len = size};
    return p;
}

void snake_eat_fruit() {
    ++size;
}

int snake_len() {
    return size;
}
