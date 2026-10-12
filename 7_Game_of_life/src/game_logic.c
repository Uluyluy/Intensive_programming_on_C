#include "game_of_life.h"

int countNeighbors(int **field, int row, int col, int rows, int cols) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i != 0 || j != 0) {
                int neighbor_row = (row + i + rows) % rows;
                int neighbor_col = (col + j + cols) % cols;
                count += field[neighbor_row][neighbor_col];
            }
        }
    }
    return count;
}

void updateField(int **current, int **next, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = countNeighbors(current, i, j, rows, cols);
            if (current[i][j] == 1) {
                next[i][j] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            } else {
                next[i][j] = (neighbors == 3) ? 1 : 0;
            }
        }
    }
}

void swapFields(int ***current, int ***next) {
    int **temp = *current;
    *current = *next;
    *next = temp;
}