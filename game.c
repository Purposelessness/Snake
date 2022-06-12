#include <stdlib.h>
#include <conio.h>

#include "game.h"
#include "snake.h"
#include "utility.h"

enum item {
    FRUIT,
    SHRINK_FRUIT
};

typedef struct {
    enum item type;
    point_t pos;
} item_t;

item_t fruit = {FRUIT, {}};
item_t shrink_fruit = {SHRINK_FRUIT, {}};
int score;
bool is_processing;

direction_t direction = NONE;

void generate_item(item_t *item);

void reset_game();

void start_game() {
    is_processing = true;
    reset_game();
}

void reset_game() {
    reset_snake();
    generate_item(&fruit);
    generate_item(&shrink_fruit);
    score = 0;
    direction = NONE;
}

bool check_fruit_pos(item_t item, struct points sp) {
    switch (item.type) {
        case FRUIT:
            if (POINTS_EQUAL(item.pos, shrink_fruit.pos))
                return false;
            break;
        case SHRINK_FRUIT:
            if (POINTS_EQUAL(item.pos, fruit.pos))
                return false;
            break;
        default:
            break;
    }
    for (int i = 0; i < sp.len; ++i) {
        if (POINTS_EQUAL(item.pos, sp.data[i]))
            return false;
    }
    return true;
}

void generate_item(item_t *item) {
    struct points sp = snake_points();
    do {
        item->pos.x = rand() % (WIDTH - 2) + 1;
        item->pos.y = rand() % (HEIGHT - 2) + 1;
    } while (!check_fruit_pos(*item, sp));
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
            is_processing = false;
            break;
    }
}

void update_score() {
    score = (snake_len() - 1) * 10;
}

void process_game() {
    direction_t prev_direction = direction;
    process_input();
    if (is_processing == false)
        return;

    if (snake_len() > 1 && direction == -prev_direction) {
        direction = prev_direction;
    }

    move_snake(direction);
    point_t head = snake_head();
    if (POINT_IS_WALL(head) == true) {
        reset_game();
        return;
    }

    struct points sp = snake_points();
    for (int i = 1; i < sp.len; ++i) {
        if (POINTS_EQUAL(head, sp.data[i]) == true) {
            reset_game();
            return;
        }
    }

    if (POINTS_EQUAL(head, fruit.pos) == true) {
        snake_eat_fruit();
        generate_item(&fruit);
        update_score();
    }

    if (POINTS_EQUAL(head, shrink_fruit.pos) == true) {
        snake_shrink();
        generate_item(&shrink_fruit);
        update_score();
    }
}

int game_score() {
    return score;
}

point_t game_fruit_pos() {
    return fruit.pos;
}

point_t game_shrink_fruit_pos() {
    return shrink_fruit.pos;
}

bool game_is_processing() {
    return is_processing;
}

direction_t game_direction() {
    return direction;
}
