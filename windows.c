#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define HEIGHT 20
#define WIDTH 50

#define SLEEP_TIME 50000e

#define SNAKE_CH "0"
#define BORDER_CH "#"
#define FRUIT_CH "*"

typedef enum {
    TRUE,
    FALSE
} bool_t;

typedef struct {
    int x;
    int y;
} point_t;

typedef enum {
    NONE,
    LEFT,
    BOTTOM,
    RIGHT,
    TOP
} direction_t;

bool_t game_over;
point_t snake_pos, fruit_pos;
int score;
direction_t direction;

// Function to generate the fruit
// within the boundary
void reset_game() {
    game_over = FALSE;

    // Stores height and width
    snake_pos.x = WIDTH / 2;
    snake_pos.y = HEIGHT / 2;
    do {
        fruit_pos.x = rand() % 20;
    } while (fruit_pos.x == 0);

    do {
        fruit_pos.y = rand() % 20;
    } while (fruit_pos.y == 0);
    score = 0;
}

// Function to draw the boundaries
void draw() {
    system("cls");
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (x == 0 || x == WIDTH - 1 ||
                y == 0 || y == HEIGHT - 1) {
                printf(BORDER_CH);
            } else {
                if (x == snake_pos.x && y == snake_pos.y)
                    printf(SNAKE_CH);
                else if (x == fruit_pos.x && y == fruit_pos.y)
                    printf(FRUIT_CH);
                else
                    printf(" ");
            }
        }
        printf("\n");
    }

    printf("score = %d\n", score);
    printf("press X to quit the game");
}

// Function to take the input
void input() {
    if (kbhit()) {
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
            case 'x':
                game_over = TRUE;
                break;
        }
    }
}

// Function for the logic behind
// each movement
void snake_logic() {
    usleep(SLEEP_TIME);
    switch (direction) {
        case TOP:
            --snake_pos.y;
            break;
        case LEFT:
            --snake_pos.x;
            break;
        case BOTTOM:
            ++snake_pos.y;
            break;
        case RIGHT:
            ++snake_pos.x;
            break;
        default:
            break;
    }

    // Hit the borders
    if (snake_pos.x <= 0 || snake_pos.x >= WIDTH - 1 ||
        snake_pos.y <= 0 || snake_pos.y >= WIDTH - 1)
        game_over = TRUE;

    // Eat fruit
    if (snake_pos.x == fruit_pos.x && snake_pos.y == fruit_pos.y) {
        do {
            fruit_pos.x = rand() % 20;
        } while (fruit_pos.x == 0);

        do {
            fruit_pos.y = rand() % 20;
        } while (fruit_pos.y == 0);
        score += 10;
    }
}

int main() {
    setup();

    while (game_over == FALSE) {
        draw();
        input();
        logic();
    }

    return 0;
}
