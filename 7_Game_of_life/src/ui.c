#define _DEFAULT_SOURCE
#include <ncurses.h>

#include "game_of_life.h"

void initNcurses(void) {
    initscr();
    cbreak();
    noecho();
    timeout(50);
    keypad(stdscr, TRUE);
    curs_set(0);
}

void cleanupNcurses(void) { endwin(); }

void handleInput(int *speed, int *is_running) {
    int ch = getch();

    if (ch != ERR) {
        if (ch == 'a' || ch == 'A') {
            if (*speed > 10) {
                *speed -= 10;
            }
        } else if (ch == 'z' || ch == 'Z') {
            if (*speed < 1000) {
                *speed += 10;
            }
        } else if (ch == ' ') {
            *is_running = 0;
        }
    }
}

void gameLoop(int **field, int rows, int cols) {
    int **nextField = createField(rows, cols);

    if (nextField != NULL) {
        int speed = 100;
        int isRunning = 1;
        while (isRunning == 1) {
            clear();
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    char symbol = (field[i][j] == 1) ? 'O' : '.';
                    mvaddch(i, j, symbol);
                }
            }
            mvprintw(rows, 0, "Speed: %d | [A] faster [Z] slower [Space] quit", speed);
            refresh();
            int inputCount = 0;
            while (inputCount < 5 && isRunning == 1) {
                handleInput(&speed, &isRunning);
                inputCount++;
            }
            if (isRunning == 1) {
                updateField(field, nextField, rows, cols);
                swapFields(&field, &nextField);
                napms(speed);
            }
        }
        freeField(nextField, rows);
    }
}