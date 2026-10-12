#include <stdio.h>

int sum(int a, int b);

int diff(int a, int b);

int prod(int a, int b);

int int_div(int a, int b);

int main() {
    int a;
    int b;
    scanf("%d %d", &a, &b);
    if (b == 0) {
        printf("%d, %d, %d, n/a", sum(a, b), diff(a, b), prod(a, b));
    } else {
        printf("%d, %d, %d, %d", sum(a, b), diff(a, b), prod(a, b), int_div(a, b));
    }
    return 0;
}

int sum(int a, int b) { return (a + b); }

int diff(int a, int b) { return (a - b); }

int prod(int a, int b) { return (a * b); }

int int_div(int a, int b) { return (a / b); }
