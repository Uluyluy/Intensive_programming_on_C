#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#define FIELD_ROWS 25
#define FIELD_COLS 80

int **createField(int rows, int cols);
void freeField(int **field, int rows);

void readInitialState(int **field, int rows, int cols);

int countNeighbors(int **field, int row, int col, int rows, int cols);
void updateField(int **current, int **next, int rows, int cols);
void swapFields(int ***current, int ***next);

void initNcurses(void);
void cleanupNcurses(void);
void handleInput(int *speed, int *isRunning);
void gameLoop(int **field, int rows, int cols);

#endif