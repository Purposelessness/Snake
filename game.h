#ifndef SNAKECONSOLE_GAME_H
#define SNAKECONSOLE_GAME_H


#include <stdbool.h>
#include "data_structures.h"

void start_game();

void process_game();

int game_score();

point_t game_fruit_pos();

point_t game_shrink_fruit_pos();

bool game_is_processing();

direction_t game_direction();


#endif //SNAKECONSOLE_GAME_H
