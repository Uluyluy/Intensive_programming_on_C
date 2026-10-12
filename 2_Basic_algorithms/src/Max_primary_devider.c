#include <math.h>
#include <stdio.h>

int div(int a, int b);

int mod(int a, int b);

int max_primary_div(int a);

int main() {
    int n;
    char ch;
    if ((scanf("%d%c", &n, &ch) == 2) && (ch == '\n')) {
        if (n == 0 || n == 1 || n == -1)
            printf("n/a");
        else {
            if (n < 0) n = -n;
            printf("%d", max_primary_div(n));
        }
    } else
        printf("n/a");

    return 0;
}

int div(int a, int b) {
    int count = 0;
    while (a >= b) {
        a = a - b;
        count++;
    }
    return count;
}

int mod(int a, int b) {
    while (a >= b) {
        a = a - b;
    }
    return a;
}

int max_primary_div(int n) {
    int res;
    if (mod(n, 2))
        res = 1;
    else
        res = 2;
    while (!mod(n, 2)) {
        n = div(n, 2);
    }
    int i;
    for (i = 3; i * i <= n; i += 2) {
        for (; !mod(n, i); n = div(n, i)) {
            res = i;
        }
    }
    if (res <= n) res = n;
    return res;
}
