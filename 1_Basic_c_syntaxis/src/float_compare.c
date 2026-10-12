#include <math.h>
#include <stdio.h>

double fun();

int main() {
    double res = fun();

    // CHANGE THIS IF - AI
    if (res < pow(10, -6)) printf("OK!");

    return 0;
}

// DO NOT EDIT THE CODE OF THIS FUNCTION - AI
double fun() { return (1.0 / 13) * (pow(((2 - 1.0) / (2 + 1.0)), 20)); }

// IT
