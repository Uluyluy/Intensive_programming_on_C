#include <stdio.h>

int fibonacci(int n);
int k(int n);

int main() {
    int n;
    char ch;

    if ((scanf("%d%c", &n, &ch) == 2) && (ch == '\n')) {
        if (n >= 0) {
            printf("%d", fibonacci(n));
        } else {
            n = -n;
            printf("%d", k(n + 1) * fibonacci(n));
        }

    } else
        printf("n/a");

    return 0;
}

int fibonacci(int n) {
    int res = 0;
    if (n <= 1) {
        res = n;
    }
    if (n >= 2) {
        res = fibonacci(n - 1) + fibonacci(n - 2);
    }
    return res;
}

int k(int n) {
    int res;
    if (n % 2 == 0) {
        res = 1;
    } else
        res = -1;
    return res;
}