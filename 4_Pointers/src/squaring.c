#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n = 0;
    int data[NMAX];
    if (input(data, &n) == 0) {
        squaring(data, n);
        output(data, n);
    } else
        printf("n/a");

    return 0;
}

int input(int *a, int *n) {
    char ch;
    int res = 0;
    if ((scanf("%d%c", n, &ch) == 2) && ((ch == '\n') || (ch == EOF) || (ch == ' ')) && (*n <= NMAX) &&
        (*n > 0)) {
        for (int *p = a; p - a < *n; p++) {
            if (!(scanf("%d", p) == 1)) res = -1;
        }
    } else
        res = -1;

    return res;
}

void output(int *a, int n) {
    int *p = a;
    for (; p - a < n - 1; p++) {
        printf("%d ", *p);
    }
    printf("%d", *p);
}

void squaring(int *a, int n) {
    for (int *p = a; p - a < n; p++) {
        *p = (*p) * (*p);
    }
}
