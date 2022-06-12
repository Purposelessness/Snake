#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include <stdbool.h>

#include "data_structures.h"
#include "game.h"
#include "snake.h"

void hide_cursor()
{
    HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(console_handle, &info);
}

void draw() {
    COORD coord = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    struct points sp = snake_points();

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {

            if (x == 0 || x == WIDTH - 1 ||
                y == 0 || y == HEIGHT - 1) {
                printf(BORDER_CH);
            } else {
                bool snake_flag = false;
                for (int i = 0; i < sp.len; ++i) {
                    if (x == sp.data[i].x && y == sp.data[i].y) {
                        printf(SNAKE_CH);
                        snake_flag = true;
                    }
                }
                if (x == game_fruit_pos().x && y == game_fruit_pos().y)
                    printf(FRUIT_CH);
                else if (x == game_shrink_fruit_pos().x && y == game_shrink_fruit_pos().y)
                    printf(SHRINK_FRUIT_CH);
                else if (snake_flag == false)
                    printf(" ");
            }

        }
        printf("\n");
    }

    printf("score = %d\n", game_score());
    printf("press W A S D to control snake\n");
    printf("press R to restart the game\n");
    printf("press Q to quit the game\n");
//    printf("(%d %d), (%d %d)\n", game_fruit_pos().x, game_fruit_pos().y, game_shrink_fruit_pos().x,
//           game_shrink_fruit_pos().y);
}

int main() {
    hide_cursor();
    start_game();
    while (game_is_processing() == true) {
        draw();
        usleep(REFRESH_TIME);
        process_game();
    }

    return 0;
}
