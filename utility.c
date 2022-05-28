#include "utility.h"

bool_t is_wall(int x, int y) {
    return x <= 0 || x >= WIDTH - 1 || y <= 0 || y >= HEIGHT - 1;
}

bool_t points_equal(point_t p1, point_t p2) {
    return p1.x == p2.x && p1.y == p2.y;
}
