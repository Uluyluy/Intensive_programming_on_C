#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);

double mean(int *a, int n);
double variance(int *a, int n);
int check(int *a, int n);

int main() {
    int n = 0;
    int data[NMAX];
    if (input(data, &n) == 0) {
        printf("%d", check(data, n));
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

double mean(int *a, int n) {
    float res = 0;
    for (int *p = a; p - a < n; p++) {
        res = res + *p;
    }
    return res / n;
}

double variance(int *a, int n) {
    float res = 0;
    for (int *p = a; p - a < n; p++) {
        res = res + (1. / n) * pow((*p - mean(a, n)), 2);
    }
    return res;
}

int check(int *a, int n) {
    int res = 0;

    for (int *p = a; p - a < n; p++) {
        if ((((*p) % 2) == 0) && (*p >= mean(a, n)) && ((*p) <= (mean(a, n) + 3 * sqrt(variance(a, n)))) &&
            ((*p) != 0) && (res == 0)) {
            res = *p;
        }
    }

    return res;
}
