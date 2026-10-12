#include <math.h>
#include <stdio.h>

int main() {
    float x;
    float y;

    if (scanf("%f", &x) == 1) {
        if (x == 0) {
            printf("n/a");
        } else {
            y = 7 * pow(10, -3) * pow(x, 4) + ((22.8 * pow(x, 1 / 3) - pow(10, 3)) * x + 3) / (x * x / 2) -
                x * pow((10 + x), (2 / x)) - 1.01;
            printf("%.1lf", y);
        }
    } else {
        printf("n/a");
    }

    return 0;
}
