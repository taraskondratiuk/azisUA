#include <stdio.h>
#include "math.h"

#define X 1
#define Y 2

double ef(double epsilon, double sigma) {
    if (epsilon > 0) {
        return (sin(epsilon) + log(fabs(sigma)));
    } else {
        return (sin(epsilon) + sigma) /
                ((epsilon + 5) / (sigma * sigma - 2));
    }

}

double fi(int x, int y) {
    return (ef(x * x, sqrt(y)) - ef(((double) x + y) / (3 + x), sqrt(x))) /
           (ef(x, sqrt(y + x)) - ef(((double) y - x) / (3 + y), (double) y / 3));
}

int main() {
    printf("result : %f", fi(X, Y));
    return 0;
}