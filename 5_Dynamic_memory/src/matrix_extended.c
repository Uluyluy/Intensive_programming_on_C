#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

static int input_matrix(int **matrix, int rows, int cols);
static void output_matrix(int **matrix, int rows, int cols);
static void find_row_maxs(int **matrix, int rows, int cols, int *maxs);
static void find_col_mins(int **matrix, int rows, int cols, int *mins);
static int method_static(void);
static int method_single_array(void);
static int method_pointer_array(void);
static int method_two_blocks(void);

int main(void) {
    int method;
    char ch;
    int result = 0;
    int error = 0;

    if (scanf("%d%c", &method, &ch) != 2 || method < 1 || method > 4 || (ch != '\n' && ch != ' ')) {
        error = 1;
    }

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

    if (!error && result != 0) {
        error = 1;
    }

    if (error) {
        printf("n/a");
    }

    return 0;
}

static int input_matrix(int **matrix, int rows, int cols) {
    int res = 0;
    for (int i = 0; i < rows && res == 0; i++) {
        for (int j = 0; j < cols && res == 0; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
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
        printf("\n");
    }
}

static void find_row_maxs(int **matrix, int rows, int cols, int *maxs) {
    for (int i = 0; i < rows; i++) {
        maxs[i] = matrix[i][0];
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] > maxs[i]) {
                maxs[i] = matrix[i][j];
            }
        }
    }
}

static void find_col_mins(int **matrix, int rows, int cols, int *mins) {
    for (int j = 0; j < cols; j++) {
        mins[j] = matrix[0][j];
        for (int i = 1; i < rows; i++) {
            if (matrix[i][j] < mins[j]) {
                mins[j] = matrix[i][j];
            }
        }
    }
}

static void output_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", arr[i]);
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
        (scanf("%d%c", &cols, &ch) != 2 || cols <= 0 || cols > MAX_SIZE || (ch != '\n' && ch != ' '))) {
        res = -1;
    }

    if (res == 0) {
        int matrix[MAX_SIZE][MAX_SIZE];
        int *ptrs[MAX_SIZE];
        int row_maxs[MAX_SIZE];
        int col_mins[MAX_SIZE];

        for (int i = 0; i < rows; i++) {
            ptrs[i] = matrix[i];
        }

        if (input_matrix(ptrs, rows, cols) != 0) {
            res = -1;
        }

        if (res == 0) {
            output_matrix(ptrs, rows, cols);
            find_row_maxs(ptrs, rows, cols, row_maxs);
            find_col_mins(ptrs, rows, cols, col_mins);
            output_array(row_maxs, cols);
            printf("\n");
            output_array(col_mins, cols);
        }
    }

    return res;
}

static int method_single_array(void) {
    int rows, cols;
    char ch;
    int res = 0;

    if (scanf("%d%c", &rows, &ch) != 2 || rows <= 0 || rows > MAX_SIZE || (ch != '\n' && ch != ' ')) {
        res = -1;
    }
    if (res == 0 &&
        (scanf("%d%c", &cols, &ch) != 2 || cols <= 0 || cols > MAX_SIZE || (ch != '\n' && ch != ' '))) {
        res = -1;
    }

    int **single_array_matrix = NULL;
    int *row_maxs = NULL;
    int *col_mins = NULL;

    if (res == 0) {
        single_array_matrix = malloc(rows * cols * sizeof(int) + rows * sizeof(int *));
        row_maxs = malloc(rows * sizeof(int));
        col_mins = malloc(cols * sizeof(int));
        if (single_array_matrix == NULL || row_maxs == NULL || col_mins == NULL) {
            res = -1;
        }
    }

    if (res == 0) {
        int *ptr = (int *)(single_array_matrix + rows);
        for (int i = 0; i < rows; i++) {
            single_array_matrix[i] = ptr + cols * i;
        }

        if (input_matrix(single_array_matrix, rows, cols) != 0) {
            res = -1;
        }
    }

    if (res == 0) {
        output_matrix(single_array_matrix, rows, cols);
        find_row_maxs(single_array_matrix, rows, cols, row_maxs);
        find_col_mins(single_array_matrix, rows, cols, col_mins);
        output_array(row_maxs, cols);
        printf("\n");
        output_array(col_mins, cols);
    }

    free(col_mins);
    free(row_maxs);
    free(single_array_matrix);

    return res;
}

static int method_pointer_array(void) {
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
    int *row_maxs = NULL;
    int *col_mins = NULL;

    if (res == 0) {
        pointer_array = malloc(rows * sizeof(int *));
        row_maxs = malloc(rows * sizeof(int));
        col_mins = malloc(cols * sizeof(int));
        if (pointer_array == NULL || row_maxs == NULL || col_mins == NULL) {
            free(pointer_array);
            free(row_maxs);
            free(col_mins);
            res = -1;
        }
    }

    if (res == 0) {
        for (int i = 0; i < rows && res == 0; i++) {
            pointer_array[i] = malloc(cols * sizeof(int));
            if (pointer_array[i] == NULL) {
                for (int j = 0; j < i; j++) {
                    free(pointer_array[j]);
                }
                free(pointer_array);
                free(row_maxs);
                free(col_mins);
                res = -1;
            }
        }
    }

    if (res == 0) {
        if (input_matrix(pointer_array, rows, cols) != 0) {
            res = -1;
        }
    }

    if (res == 0) {
        output_matrix(pointer_array, rows, cols);
        find_row_maxs(pointer_array, rows, cols, row_maxs);
        find_col_mins(pointer_array, rows, cols, col_mins);
        output_array(row_maxs, cols);
        printf("\n");
        output_array(col_mins, cols);
    }

    for (int i = 0; i < rows; i++) {
        free(pointer_array[i]);
    }
    free(pointer_array);
    free(row_maxs);
    free(col_mins);

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
    int *row_maxs = NULL;
    int *col_mins = NULL;

    if (res == 0) {
        pointer_array = malloc(rows * sizeof(int *));
        values_array = malloc(rows * cols * sizeof(int));
        row_maxs = malloc(rows * sizeof(int));
        col_mins = malloc(cols * sizeof(int));
        if (pointer_array == NULL || values_array == NULL || row_maxs == NULL || col_mins == NULL) {
            free(pointer_array);
            free(values_array);
            free(row_maxs);
            free(col_mins);
            res = -1;
        }
    }

    if (res == 0) {
        for (int i = 0; i < rows; i++) {
            pointer_array[i] = values_array + cols * i;
        }

        if (input_matrix(pointer_array, rows, cols) != 0) {
            res = -1;
        }
    }

    if (res == 0) {
        output_matrix(pointer_array, rows, cols);
        find_row_maxs(pointer_array, rows, cols, row_maxs);
        find_col_mins(pointer_array, rows, cols, col_mins);
        output_array(row_maxs, cols);
        printf("\n");
        output_array(col_mins, cols);
    }

    free(col_mins);
    free(row_maxs);
    free(values_array);
    free(pointer_array);

    return res;
}