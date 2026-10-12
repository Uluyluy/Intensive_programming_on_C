#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void sort(int *a, int n);

int main() {
    int n = NMAX;
    int data[NMAX];
    if (input(data, &n) == 0) {
        sort(data, n);
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

void sort(int *a, int n) {
    int temp;
    for (int *p = a; p - a < n - 1; p++) {
        for (int *i = a; i - a < n - (p - a) - 1; i++) {
            if (*i >= *(i + 1)) {
                temp = *i;
                *i = *(i + 1);
                *(i + 1) = temp;
            }
        }
    }
}
