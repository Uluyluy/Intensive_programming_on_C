#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void sort_doors(struct door* doors, int count);
void close_all_doors(struct door* doors, int count);
void print_doors(const struct door* doors, int count);

int main(void) {
    int result = 0;
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort_doors(doors, DOORS_COUNT);
    close_all_doors(doors, DOORS_COUNT);
    print_doors(doors, DOORS_COUNT);

    return result;
}

void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort_doors(struct door* doors, int count) {
    int i = 0;
    int swapped = 1;
    while (i < count - 1 && swapped == 1) {
        swapped = 0;
        int j = 0;
        while (j < count - i - 1) {
            if (doors[j].id > doors[j + 1].id) {
                struct door temp = doors[j];
                doors[j] = doors[j + 1];
                doors[j + 1] = temp;
                swapped = 1;
            }
            j++;
        }
        i++;
    }
}

void close_all_doors(struct door* doors, int count) {
    int i = 0;
    while (i < count) {
        doors[i].status = 0;
        i++;
    }
}

void print_doors(const struct door* doors, int count) {
    int i = 0;
    while (i < count) {
        printf("%d, %d\n", doors[i].id, doors[i].status);
        i++;
    }
}