#include <stdlib.h>

#include "game_of_life.h"

int **createField(int rows, int cols) {
    int **field = NULL;
    int success = 1;

    field = malloc(rows * sizeof(int *));
    if (field == NULL) {
        success = 0;
    }

    if (success) {
        for (int i = 0; i < rows && success; i++) {
            field[i] = malloc(cols * sizeof(int));
            if (field[i] == NULL) {
                for (int j = 0; j < i; j++) {
                    free(field[j]);
                }
                free(field);
                field = NULL;
                success = 0;
            } else {
                for (int j = 0; j < cols; j++) {
                    field[i][j] = 0;
                }
            }
        }
    }
    return field;
}

void freeField(int **field, int rows) {
    if (field != NULL) {
        for (int i = 0; i < rows; i++) {
            free(field[i]);
        }
        free(field);
    }
}