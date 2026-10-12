#include <stdio.h>

#define NMAX 10

int input(int *a, int *n, int *c);
void output(int *a, int n);
void cycle_shift(int *a, int n, int c);

int main() {
    int n = 0;
    int c = 0;
    int data[NMAX];

    if (input(data, &n, &c) == 0) {
        cycle_shift(data, n, c);
        output(data, n);
    } else {
        printf("n/a");
    }

    return 0;
}

int input(int *a, int *n, int *c) {
    char ch;
    int res = 0;

    if (scanf("%d%c", n, &ch) != 2 || ch != '\n' || *n <= 0 || *n > NMAX) {
        res = -1;
    }

    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            res = -1;
        }
    }

    if (scanf("%d%c", c, &ch) != 2 || (ch != '\n' && ch != EOF)) {
        if (!(ch == '\n')) {
            res = -1;
        }
    }

    return res;
}

void output(int *a, int n) {
    int *p = a;
    for (; p - a < n - 1; p++) {
        printf("%d ", *p);
    }
    printf("%d", *p);
}

void cycle_shift(int *a, int n, int c) {
    int shift = ((c % n) + n) % n;

    if (!(shift == 0)) {
        int temp[NMAX];

        for (int i = 0; i < shift; i++) {
            temp[i] = a[i];
        }

        for (int i = 0; i < n - shift; i++) {
            a[i] = a[i + shift];
        }
        for (int i = 0; i < shift; i++) {
            a[n - shift + i] = temp[i];
        }
    }
}