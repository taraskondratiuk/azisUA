#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DELTA_T 0.1

double min(double *l, const double *r) {
    double min = *l;
    for (double *i = l + 1; i < r; ++i) {
        if (min > *i) {
            min = *i;
        }
    }
    return min;
}

double max(double *l, const double *r) {
    double max = *l;
    for (double *i = l + 1; i < r; ++i) {
        if (max < *i) {
            max = *i;
        }
    }
    return max;
}

double avg(double *l, const double *r, int len) {
    double sum = 0;
    for (double *i = l; i < r; ++i) {
        sum += *i;
    }
    return sum / len;
}

double avgSquare(double *l, double *r, int len) {
    double sumOfSquares = 0;
    for (double *i = l; i < r; ++i) {
        sumOfSquares += (*i * *i);
    }
    return sqrt(sumOfSquares / len);
}

double *firstDerivativeArr(const double vals[], int len) {
    double *res = (double *) malloc(len * sizeof(double));
    for (int i = 1; i < len - 1; ++i) {
        res[i] = (vals[i + 1] - vals[i - 1]) / (2 * DELTA_T);
    }
    res[0] = res[1];
    res[len - 1] = res[len - 2];
    return res;
}

double *secondDerivativeArr(const double vals[], int len) {
    double *res = (double *) malloc(len * sizeof(double));
    for (int i = 2; i < len - 3; ++i) {
        res[i] = (vals[i - 2] - 2 * vals[i] + vals[i + 2]);
    }
    res[0] = res[2];
    res[1] = res[2];
    res[len - 1] = res[len - 3];
    res[len - 2] = res[len - 3];
    return res;
}

int main() {
    int n = 1;
    double *a;
    a = (double *) malloc(sizeof(double));
    FILE *fd = fopen("../11v14.txt", "r");
    while (!feof(fd)) {
        fscanf(fd, "%le", &a[n - 1]);
        a = realloc(a, ++n * sizeof(double));
    }
    n--;
//    for (int i = 0; i < n; ++i) {
    printf("%.11f\n", min(&a[0], &a[n - 1]));
    printf("%.11f\n", max(&a[0], &a[n - 1]));
    printf("%.11f\n", avg(&a[0], &a[n - 1], n));
    printf("%.11f\n", avgSquare(&a[0], &a[n - 1], n));
//    }
}


