#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float getMachineEpsylon(float e) {
    float e1;

    do {
        e /= 2.0f;
        e1 = e + 1.0f;
    } while (e1 > 1.0);

    return e;
}

int main() {
    float a1 = (float) 1 / 3;
    float b1 = (float) 1 / 33;
    float c1 = (float) 1 / 333;
    float d1 = (float) 1 / 3333;
    float e1 = (float) 1 / 33333;

    long double a2 = (long double) 1 / 3;
    long double b2 = (long double) 1 / 33;
    long double c2 = (long double) 1 / 333;
    long double d2 = (long double) 1 / 3333;
    long double e2 = (long double) 1 / 33333;

    long double resa = (long double) a1 - a2;
    long double resb = (long double) b1 - b2;
    long double resc = (long double) c1 - c2;
    long double resd = (long double) d1 - d2;
    long double rese = (long double) e1 - e2;

    float a3 = 0;
    float b3 = 0;
    float c3 = 0;
    float d3 = 0;

    for (int i = 0; i < 10; ++i) {
        a3 += .1f;
    }
    for (int i = 0; i < 100; ++i) {
        b3 += .01f;
    }
    for (int i = 0; i < 1000; ++i) {
        c3 += .001f;
    }
    for (int i = 0; i < 1000000; ++i) {
        d3 += .0000001f;
    }

    float *values = (float *) malloc(sizeof(float) * 10000);

    for (int j = 0; j < 10000; ++j) {
        values[j] = (float) 1 / (j + 1) * pow(-1, j);
    }

    float a5 = 0;
    float b5 = 0;
    float c5 = 0;
    float d5 = 0;
    for (int k = 0; k < 10000; ++k) {
        a5 += values[k];
    }
    for (int k = 9999; k >= 0; --k) {
        b5 += values[k];
        if (k % 2 != 0) {
            values[k] = -values[k];
        }
    }
    float c51 = 0;
    float c52 = 0;
    for (int k = 0; k < 10000; k += 2) {
        c51 += values[k];
    }
    for (int k = 1; k < 10000; k += 2) {
        c52 += values[k];
    }
    c5 = c51 - c52;
    float d51 = 0;
    float d52 = 0;
    for (int k = 9998; k >= 0; k -= 2) {
        d51 += values[k];
    }
    for (int k = 9999; k >= 0; k -= 2) {
        d52 += values[k];
    }
    d5 = d51 - d52;

    float epsylon = getMachineEpsylon(0.1f);

    return 0;
}