#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int input(int ***matrix, int *n, int *m);
void output(int **matrix, int n, int m);
int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result);
int transpose(int **matrix, int n, int m);
int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result);

int main(void) {
    int operation;
    char ch;
    int error = 0;

    if (scanf("%d%c", &operation, &ch) != 2 || operation < 1 || operation > 3 || (ch != '\n' && ch != ' ')) {
        error = 1;
    }

    if (error == 0 && operation == 1) {
        int n1 = 0, m1 = 0, n2 = 0, m2 = 0;
        int **mat1 = NULL, **mat2 = NULL, **res = NULL;
        int nr = 0, mr = 0, alloc_res = 0;

        if (input(&mat1, &n1, &m1) != 0) error = 1;
        if (!error && input(&mat2, &n2, &m2) != 0) error = 1;

        if (!error) res = malloc(n1 * sizeof(int *));
        if (!error && res == NULL) error = 1;
        for (int i = 0; !error && i < n1; i++) {
            res[i] = malloc(m1 * sizeof(int));
            if (res[i] == NULL) {
                error = 1;
            }
            alloc_res += (!error);
        }
        if (error && res != NULL) {
            for (int i = 0; i < alloc_res; i++) {
                free(res[i]);
            }
            free(res);
            res = NULL;
        }

        if (!error && sum(mat1, n1, m1, mat2, n2, m2, res, &nr, &mr) != 0) error = 1;
        if (!error) output(res, nr, mr);

        if (mat1) {
            for (int i = 0; i < n1; i++) free(mat1[i]);
            free(mat1);
        }
        if (mat2) {
            for (int i = 0; i < n2; i++) free(mat2[i]);
            free(mat2);
        }
        if (res) {
            for (int i = 0; i < n1; i++) free(res[i]);
            free(res);
        }
    } else if (error == 0 && operation == 2) {
        int n1 = 0, m1 = 0, n2 = 0, m2 = 0;
        int **mat1 = NULL, **mat2 = NULL, **res = NULL;
        int nr = 0, mr = 0, alloc_res = 0;

        if (input(&mat1, &n1, &m1) != 0) error = 1;
        if (!error && input(&mat2, &n2, &m2) != 0) error = 1;

        if (!error) res = malloc(n1 * sizeof(int *));
        if (!error && res == NULL) error = 1;
        for (int i = 0; !error && i < n1; i++) {
            res[i] = malloc(m2 * sizeof(int));
            if (res[i] == NULL) {
                error = 1;
            }
            alloc_res += (!error);
        }
        if (error && res != NULL) {
            for (int i = 0; i < alloc_res; i++) {
                free(res[i]);
            }
            free(res);
            res = NULL;
        }

        if (!error && mul(mat1, n1, m1, mat2, n2, m2, res, &nr, &mr) != 0) error = 1;
        if (!error) output(res, nr, mr);

        if (mat1) {
            for (int i = 0; i < n1; i++) free(mat1[i]);
            free(mat1);
        }
        if (mat2) {
            for (int i = 0; i < n2; i++) free(mat2[i]);
            free(mat2);
        }
        if (res) {
            for (int i = 0; i < n1; i++) free(res[i]);
            free(res);
        }
    } else if (error == 0 && operation == 3) {
        int n = 0, m = 0;
        int **mat = NULL;

        if (input(&mat, &n, &m) != 0) error = 1;
        if (!error && n != m) error = 1;
        if (!error && transpose(mat, n, m) != 0) error = 1;
        if (!error) output(mat, n, m);

        if (mat) {
            for (int i = 0; i < n; i++) free(mat[i]);
            free(mat);
        }
    } else if (error == 0) {
        error = 1;
    }

    if (error) printf("n/a");

    return 0;
}

int input(int ***matrix, int *n, int *m) {
    int res = 0;
    int allocated = 0;
    char ch;

    *matrix = NULL;

    if (scanf("%d%c", n, &ch) != 2 || *n <= 0 || *n > MAX_SIZE || (ch != '\n' && ch != ' ')) {
        res = -1;
    }
    if (res == 0 && (scanf("%d%c", m, &ch) != 2 || *m <= 0 || *m > MAX_SIZE || (ch != '\n' && ch != ' '))) {
        res = -1;
    }

    if (res == 0) {
        *matrix = malloc(*n * sizeof(int *));
        if (*matrix == NULL) {
            res = -1;
        }
    }

    for (int i = 0; res == 0 && i < *n; i++) {
        (*matrix)[i] = malloc(*m * sizeof(int));
        if ((*matrix)[i] == NULL) {
            res = -1;
        }
        allocated += (res == 0);
        for (int j = 0; res == 0 && j < *m; j++) {
            if (scanf("%d", &(*matrix)[i][j]) != 1) {
                res = -1;
            }
        }
    }

    if (res != 0 && *matrix != NULL) {
        for (int i = 0; i < allocated; i++) {
            free((*matrix)[i]);
        }
        free(*matrix);
        *matrix = NULL;
    }

    return res;
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j > 0) printf(" ");
            printf("%d", matrix[i][j]);
        }
        if (i < n - 1) printf("\n");
    }
}

int sum(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result) {
    int res = 0;

    if (n_first != n_second || m_first != m_second) {
        res = -1;
    }
    if (res == 0) {
        *n_result = n_first;
        *m_result = m_first;
        for (int i = 0; i < n_first; i++) {
            for (int j = 0; j < m_first; j++) {
                matrix_result[i][j] = matrix_first[i][j] + matrix_second[i][j];
            }
        }
    }

    return res;
}

int transpose(int **matrix, int n, int m) {
    int res = 0;

    if (n != m) {
        res = -1;
    }
    for (int i = 0; res == 0 && i < n; i++) {
        for (int j = i + 1; res == 0 && j < m; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    return res;
}

int mul(int **matrix_first, int n_first, int m_first, int **matrix_second, int n_second, int m_second,
        int **matrix_result, int *n_result, int *m_result) {
    int res = 0;

    if (m_first != n_second) {
        res = -1;
    }
    if (res == 0) {
        *n_result = n_first;
        *m_result = m_second;
    }
    for (int i = 0; res == 0 && i < n_first; i++) {
        for (int j = 0; res == 0 && j < m_second; j++) {
            matrix_result[i][j] = 0;
            for (int k = 0; k < m_first; k++) {
                matrix_result[i][j] += matrix_first[i][k] * matrix_second[k][j];
            }
        }
    }

    return res;
}