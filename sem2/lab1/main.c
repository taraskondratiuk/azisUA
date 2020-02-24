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

double *firstDerivative(const double *vals, int len) {
    double *res = (double *) malloc(len * sizeof(double));
    for (int i = 1; i < len - 1; ++i) {
        res[i] = (vals[i + 1] - vals[i - 1]) / (2 * DELTA_T);
    }
    res[0] = res[1];
    res[len - 1] = res[len - 2];

    FILE *firstDerivative = fopen("../first_derivative.txt", "w+");
    for (int j = 0; j < len; ++j) {
        fprintf(firstDerivative, "%le\n", res[j]);
    }
    return res;
}

double *secondDerivative(const double *vals, int len) {
    double *res = (double *) malloc(len * sizeof(double));
    for (int i = 2; i < len - 3; ++i) {
        res[i] = (vals[i - 2] - 2 * vals[i] + vals[i + 2]);
    }
    res[0] = res[2];
    res[1] = res[2];
    res[len - 1] = res[len - 3];
    res[len - 2] = res[len - 3];

    FILE *secondDerivative = fopen("../second_derivative.txt", "w+");
    for (int j = 0; j < len; ++j) {
        fprintf(secondDerivative, "%le\n", res[j]);
    }
    return res;
}

double *recursiveFilter(const double vals[], int len, double a1, double a2, double b0, double b1, double b2) {
    double *res = (double *) malloc(len * sizeof(double));
    FILE *filter = fopen("../filter.txt", "w+");
    int g = 3;
    for (int i = 0; i < g; i++) {
        res[i] = vals[i];
        fprintf(filter, "%le\n", res[i]);
    }
    for (int i = g; i < len; i++) {
        res[i] = -a1 * res[i - 1] - a2 * res[i - 2] + b0 * vals[i] + b1 * vals[i - 1] + b2 * vals[i - 2];
        fprintf(filter, "%le\n", res[i]);
    }
    return res;
}

void printMaximums(const double vals[], int len) {
    printf("\n");
    for (int i = 1; i < len - 1; ++i) {
        if (vals[i - 1] < vals[i] && vals[i + 1] < vals[i]) {
            printf("local minimum %le at index %d\n", vals[i], i);
        }
    }
}

void printIntersectionsWithLevel(const double vals[], int len, double level) {
    double T;
    for (int i = 1; i < len - 1; i++) {
        if (vals[i] == level) {
            printf("%.11f - intersection with level %.11f\n", i * DELTA_T, level);
        }
        if ((vals[i] < level && vals[i + 1] > level) || (vals[i] > level && vals[i + 1] < level)) {
            printf("%.11f - intersection with level %.11f\n", ((2 * i) + 1) * DELTA_T / 2, level);
        }
    }
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
    printf("%.11f\n", min(&a[0], &a[n - 1]));
    printf("%.11f\n", max(&a[0], &a[n - 1]));
    printf("%.11f\n", avg(&a[0], &a[n - 1], n));
    printf("%.11f\n", avgSquare(&a[0], &a[n - 1], n));
    double *firstDer = firstDerivative(&a[0], n);
    double *secondDer = secondDerivative(&a[0], n);
    double *recFilter = recursiveFilter(&a[0], n, -0.6559, 0.2487, 0.1482, 0.2964, 0.1482);

    printf("\nFirst derivative:\n");
    for (int i = 0; i < n; ++i) {
        printf("%.11f ", firstDer[i]);
    }
    printf("\nSecond derivative:\n");
    for (int i = 0; i < n; ++i) {
        printf("%.11f ", secondDer[i]);
    }
    printf("\nRecursive filter:\n");
    for (int i = 0; i < n; ++i) {
        printf("%.11f ", recFilter[i]);
    }
    printf("\n");
    printMaximums(&a[0], n);
    double level = -0.0001114828;
    printf("\n");
    printIntersectionsWithLevel(&a[0], n, level);
}
