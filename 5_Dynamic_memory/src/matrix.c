#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

static int input_matrix(int **matrix, int rows, int cols);
static void output_matrix(int **matrix, int rows, int cols);
static int method_static(void);
static int method_single_array(void);
static int method_pointer_array(void);
static int method_two_blocks(void);

int main(void) {
    int method;
    char ch;
    int result = 0;
    int error = 0;

    if (scanf("%d%c", &method, &ch) != 2 || method < 1 || method > 4 || (ch != '\n' && ch != ' ')) error = 1;
    if (!error) {
        if (method == 1) {
            result = method_static();
        } else if (method == 2) {
            result = method_single_array();
        } else if (method == 3) {
            result = method_pointer_array();
        } else if (method == 4) {
            result = method_two_blocks();
        } else {
            error = 1;
        }
    }
    if (!error && result != 0) error = 1;
    if (error) printf("n/a");

    return 0;
}

static int input_matrix(int **matrix, int rows, int cols) {
    int res = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((scanf("%d", &matrix[i][j]) != 1) && (res == 0)) {
                res = -1;
            }
        }
    }
    return res;
}

static void output_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j > 0) printf(" ");
            printf("%d", matrix[i][j]);
        }
        if (i < rows - 1) printf("\n");
    }
}

static int method_static(void) {
    int rows, cols;
    char ch;
    int res = 0;

    if (scanf("%d%c", &rows, &ch) != 2 || rows <= 0 || rows > MAX_SIZE || (ch != '\n' && ch != ' ')) {
        res = -1;
    }
    if (res == 0 &&
        (scanf("%d%c", &cols, &ch) != 2 || cols <= 0 || cols > MAX_SIZE || (ch != '\n' && ch != ' ')))
        res = -1;

    if (res == 0) {
        int matrix[MAX_SIZE][MAX_SIZE];
        int *ptrs[MAX_SIZE];
        for (int i = 0; i < rows; i++) {
            ptrs[i] = matrix[i];
        }

        if (input_matrix(ptrs, rows, cols) != 0) {
            res = -1;
        } else {
            output_matrix(ptrs, rows, cols);
        }
    }

    return res;
}

static int method_single_array(void) {
    int rows, cols;
    char ch;
    int res = 0;

    if (scanf("%d%c", &rows, &ch) != 2 || rows <= 0 || rows > MAX_SIZE || (ch != '\n' && ch != ' ')) res = -1;
    if (res == 0 &&
        (scanf("%d%c", &cols, &ch) != 2 || cols <= 0 || cols > MAX_SIZE || (ch != '\n' && ch != ' ')))
        res = -1;

    int **single_array_matrix = NULL;
    if (res == 0) {
        single_array_matrix = malloc(rows * cols * sizeof(int) + rows * sizeof(int *));
        if (single_array_matrix == NULL) res = -1;
    }

    if (res == 0) {
        int *ptr = (int *)(single_array_matrix + rows);
        for (int i = 0; i < rows; i++) {
            single_array_matrix[i] = ptr + cols * i;
        }

        if (input_matrix(single_array_matrix, rows, cols) != 0) {
            res = -1;
        } else {
            output_matrix(single_array_matrix, rows, cols);
        }
        free(single_array_matrix);
    }
    return res;
}

static int method_pointer_array(void) {
    int rows, cols, res = 0;
    char ch;

    if (scanf("%d%c", &rows, &ch) != 2 || rows <= 0 || rows > MAX_SIZE || (ch != '\n' && ch != ' ')) res = -1;
    if (res == 0 &&
        (scanf("%d%c", &cols, &ch) != 2 || cols <= 0 || cols > MAX_SIZE || (ch != '\n' && ch != ' ')))
        res = -1;

    int **pointer_array = NULL;
    if (res == 0) {
        pointer_array = malloc(rows * sizeof(int *));
        if (pointer_array == NULL) res = -1;
    }
    if (res == 0) {
        for (int i = 0; i < rows && res == 0; i++) {
            pointer_array[i] = malloc(cols * sizeof(int));
            if (pointer_array[i] == NULL) {
                for (int j = 0; j < i; j++) {
                    free(pointer_array[j]);
                }
                free(pointer_array);
                res = -1;
            }
        }
    }
    if (res == 0) {
        if (input_matrix(pointer_array, rows, cols) != 0) {
            res = -1;
        } else {
            output_matrix(pointer_array, rows, cols);
        }

        for (int i = 0; i < rows; i++) {
            free(pointer_array[i]);
        }
        free(pointer_array);
    }
    return res;
}

static int method_two_blocks(void) {
    int rows, cols, res = 0;
    char ch;
    if (scanf("%d%c", &rows, &ch) != 2 || rows <= 0 || rows > MAX_SIZE || (ch != '\n' && ch != ' ')) {
        res = -1;
    }
    if (res == 0 &&
        (scanf("%d%c", &cols, &ch) != 2 || cols <= 0 || cols > MAX_SIZE || (ch != '\n' && ch != ' '))) {
        res = -1;
    }
    int **pointer_array = NULL;
    int *values_array = NULL;
    if (res == 0) {
        pointer_array = malloc(rows * sizeof(int *));
        values_array = malloc(rows * cols * sizeof(int));
        if (pointer_array == NULL || values_array == NULL) {
            free(pointer_array);
            free(values_array);
            res = -1;
        }
    }
    if (res == 0) {
        for (int i = 0; i < rows; i++) {
            pointer_array[i] = values_array + cols * i;
        }

        if (input_matrix(pointer_array, rows, cols) != 0) {
            res = -1;
        } else {
            output_matrix(pointer_array, rows, cols);
        }
        free(values_array);
        free(pointer_array);
    }

    return res;
}