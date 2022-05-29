#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "data_structures.h"
#include "game.h"
#include "snake.h"

void draw() {
    system("cls");

    struct points sp = snake_points();

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {

            if (x == 0 || x == WIDTH - 1 ||
                y == 0 || y == HEIGHT - 1) {
                printf(BORDER_CH);
            } else {
                bool_t snake_flag = FALSE;
                for (int i = 0; i < sp.len; ++i) {
                    if (x == sp.data[i].x && y == sp.data[i].y) {
                        printf(SNAKE_CH);
                        snake_flag = TRUE;
                    }
                }
                if (x == game_fruit_pos().x && y == game_fruit_pos().y)
                    printf(FRUIT_CH);
                else if (snake_flag == FALSE)
                    printf(" ");
            }

        }
        printf("\n");
    }

    printf("score = %d\n", game_score());
    printf("press W A S D to control snake\n");
    printf("press R to restart the game\n");
    printf("press Q to quit the game\n");
}

int main() {
    start_game();
    while (game_is_processing() == TRUE) {
        draw();
        usleep(REFRESH_TIME);
        process_game();
    }

    return 0;
}
