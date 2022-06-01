#include <string.h>
#include "snake.h"

int size;
point_t pos[MAX_SNAKE_LEN] = {};

void reset_snake() {
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

void snake_shrink() {
    if (size != 1)
        size = size / 2 + size % 2;
}

int snake_len() {
    return size;
}
