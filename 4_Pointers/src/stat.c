#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);

int max(int *a, int n);
int min(int *a, int n);

double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n = 0;
    int data[NMAX];
    if (input(data, &n) == 0) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
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
    printf("\n");
}

int max(int *a, int n) {
    int *p = a;
    int max = *p;
    for (; p - a < n; p++) {
        if (*p > max) max = *p;
    }
    return max;
}

int min(int *a, int n) {
    int *p = a;
    int min = *p;
    for (; p - a < n; p++) {
        if (*p < min) min = *p;
    }
    return min;
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

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
    printf("%d %d %.6f %.6f", max_v, min_v, mean_v, variance_v);
}