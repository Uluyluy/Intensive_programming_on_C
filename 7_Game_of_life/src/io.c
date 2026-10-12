#include <ncurses.h>
#include <stdio.h>

#include "game_of_life.h"

void readInitialState(int **field, int rows, int cols) {
    int reading = 1;

    for (int i = 0; i < rows && reading; i++) {
        for (int j = 0; j < cols && reading; j++) {
            int value = 0;
            if (scanf("%1d", &value) == 1) {
                field[i][j] = (value == 1) ? 1 : 0;
            } else {
                reading = 0;
            }
        }
    }
}