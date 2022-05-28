#ifndef SNAKECONSOLE_GAME_H
#define SNAKECONSOLE_GAME_H


#include "data_structures.h"

void start_game();

void process_game();

int game_score();

point_t game_fruit_pos();

bool_t game_is_processing();

direction_t game_direction();


#endif //SNAKECONSOLE_GAME_H
