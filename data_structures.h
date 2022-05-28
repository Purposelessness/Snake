#ifndef SNAKECONSOLE_DATA_STRUCTURES_H
#define SNAKECONSOLE_DATA_STRUCTURES_H


#include "config.h"

typedef enum {
    FALSE = 0,
    TRUE = 1
} bool_t;

typedef struct {
    int x;
    int y;
} point_t;

typedef enum {
    NONE = 0,
    LEFT = -1,
    BOTTOM = -2,
    RIGHT = 1,
    TOP = 2
} direction_t;

struct points {
    point_t *data;
    int len;
};


#endif //SNAKECONSOLE_DATA_STRUCTURES_H
