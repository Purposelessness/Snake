#ifndef SNAKECONSOLE_UTILITY_H
#define SNAKECONSOLE_UTILITY_H


#include "data_structures.h"

#define POINT_IS_WALL(p) (p.x <= 0 || p.x >= WIDTH - 1 || p.y <= 0 || p.y >= HEIGHT - 1)
#define POINTS_EQUAL(p1, p2) (p1.x == p2.x && p1.y == p2.y ? true : false)


#endif //SNAKECONSOLE_UTILITY_H
