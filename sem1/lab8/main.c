#include <stdio.h>
#include "math.h"

#define X0 -2
#define DELTA 0.5
#define N 19
#define A 1
#define B 2
#define C 3
#define PI 3.14
#define E 2.71

double function1(double x) {
    return pow(sin((x * PI) / (A * B * C) + cos((x + A) * PI / B)), 1.0 / A);
}

double function2(double x) {
    return tan(x / (x * x + A * B * A * B));
}

double function3(double x) {
    return pow(E, (A * x - B * B) / B * C) * pow((x * x - A * B * B * B) / (C * C - 1), 1.0 / 3);
}

int main() {

    for (int i = 0; i < N; ++i) {
        double x = X0 + i * DELTA;
        double y;
        if (x < 0) {
            y = function1(x);
        } else if (x >= 0 && x <= 4) {
            y = function2(x);
        } else {
            y = function3(x);
        }

        printf("x = %.1f y = %f\n",x, y );

    }
    return 0;
}