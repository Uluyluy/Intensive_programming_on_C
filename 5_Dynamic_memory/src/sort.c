#include <stdio.h>
#include <stdlib.h>

int input(int *a, int n);
void output(int *a, int n);
void sort(int *a, int n);

int main(void) {
    int n;
    int error = 0;
    int *data = NULL;
    char ch;
    if (scanf("%d%c", &n, &ch) != 2 || n <= 0 || (ch != '\n' && ch != ' ')) {
        error = 1;
    }

    if (!error) {
        data = malloc(n * sizeof(int));
        if (data == NULL) {
            error = 1;
        }
    }

    if (!error) {
        if (input(data, n) == 0) {
            sort(data, n);
            output(data, n);
        } else {
            error = 1;
        }
    }
    if (error) {
        printf("n/a");
    }
    free(data);

    return 0;
}

int input(int *a, int n) {
    char ch;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (scanf("%d%c", &a[i], &ch) != 2) {
            res = -1;
        }
        if (i < n - 1) {
            if (ch != ' ' && ch != '\n') {
                res = -1;
            }
        } else {
            if (ch != '\n' && ch != EOF) {
                res = -1;
            }
        }
    }
    return res;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
}

void sort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}