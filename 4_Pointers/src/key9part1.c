#include <stdio.h>

#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
long sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

int main() {
    int n = 0;
    char ch;
    int data[NMAX];
    int result[NMAX];

    if ((scanf("%d%c", &n, &ch) == 2) && ((ch == '\n') || (ch == EOF) || (ch == ' ')) && (n > 0)) {
        if ((input(data, &n) == 0) && (sum_numbers(data, n) / 10000000000 == 2)) {
            printf("%ld\n", sum_numbers(data, n) % 10000000000);
            output(result, find_numbers(data, n, sum_numbers(data, n) % 10000000000, result));
        } else
            printf("n/a");
    } else
        printf("n/a");

    return 0;
}

int input(int *a, int *n) {
    int res = 0;

    for (int *p = a; p - a < *n; p++) {
        if (!(scanf("%d", p) == 1)) res = -1;
    }

    return res;
}

long sum_numbers(int *buffer, int length) {
    int sum = 0;
    int flag = 1;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
            flag = 2;
        }
    }

    return 10000000000 * flag + sum;
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[count] = buffer[i];
            count++;
        }
    }
    return count;
}

void output(int *a, int n) {
    int *p = a;
    for (; p - a < n - 1; p++) {
        printf("%d ", *p);
    }
    printf("%d", *p);
}