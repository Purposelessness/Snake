#include <stdlib.h>
#include <conio.h>

#include "game.h"
#include "snake.h"
#include "utility.h"

point_t fruit_pos = {};
int score;
bool_t is_processing;

direction_t direction = NONE;

void generate_fruit();

void reset_game();

void start_game() {
    is_processing = TRUE;
    reset_game();
}

void reset_game() {
    reset_snake();
    generate_fruit();
    score = 0;
    direction = NONE;
}

void generate_fruit() {
    do {
        fruit_pos.x = rand() % (WIDTH - 1);
    } while (fruit_pos.x == 0);

    do {
        fruit_pos.y = rand() % (HEIGHT - 1);
    } while (fruit_pos.y == 0);
}

void process_input() {
    if (!kbhit())
        return;
    switch (getch()) {
        case 'w':
            direction = TOP;
            break;
        case 'a':
            direction = LEFT;
            break;
        case 's':
            direction = BOTTOM;
            break;
        case 'd':
            direction = RIGHT;
            break;
        case 'r':
            reset_game();
            break;
        case 'q':
            is_processing = FALSE;
            break;
    }
}

void process_game() {
    direction_t prev_direction = direction;
    process_input();
    if (is_processing == FALSE)
        return;

    if (snake_len() > 1 && direction == -prev_direction) {
        direction = prev_direction;
    }

    move_snake(direction);
    point_t head = snake_head();
    if (IS_WALL(head) == TRUE) {
        reset_game();
        return;
    }

    struct points sp = snake_points();
    for (int i = 1; i < sp.len; ++i) {
        if (POINTS_EQUAL(head, sp.data[i]) == TRUE) {
            reset_game();
            return;
        }
    }

    if (POINTS_EQUAL(head, fruit_pos) == TRUE) {
        snake_eat_fruit();
        generate_fruit();
        score += 10;
    }
}

int game_score() {
    return score;
}

point_t game_fruit_pos() {
    return fruit_pos;
}

bool_t game_is_processing() {
    return is_processing;
}

direction_t game_direction() {
    return direction;
}
