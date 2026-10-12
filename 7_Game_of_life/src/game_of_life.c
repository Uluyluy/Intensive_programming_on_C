#include "game_of_life.h"

#include <stdio.h>

int main() {
    int **field = createField(FIELD_ROWS, FIELD_COLS);
    int result = 0;

    if (field != NULL) {
        readInitialState(field, FIELD_ROWS, FIELD_COLS);
        (void)freopen("/dev/tty", "r", stdin);

        initNcurses();
        gameLoop(field, FIELD_ROWS, FIELD_COLS);
        cleanupNcurses();

        freeField(field, FIELD_ROWS);
    } else {
        result = 1;
    }

    return result;
}
