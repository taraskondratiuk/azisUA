#include <stdio.h>
#include <stdlib.h>


float **getMatrixFromFile(char *path, float **matrix, int *dim);
float **getDiagonalMatrix(float **matrix, int *dim);

int main(int argc, char *argv[]) {
    float **matrix = NULL;
    int *dim = malloc(sizeof(int));
    matrix = getMatrixFromFile(argv[1], matrix, dim);

    printf("input matrix:\n");
    for (int k = 0; k < *dim; ++k) {
        for (int i = 0; i < *dim + 1; ++i) {
            printf("%.2f ", matrix[k][i]);
        }
        printf("\n");
    }
    getDiagonalMatrix(matrix, dim);

    printf("\n\ndiagonal matrix:\n");
    for (int k = 0; k < *dim; ++k) {
        for (int i = 0; i < *dim + 1; ++i) {
            printf("%.2f ", matrix[k][i]);
        }
        printf("\n");
    }

    float roots[*dim + 1];
    roots[*dim - 1] = matrix[*dim - 1][*dim];
    for (int i = *dim - 2; i >= 0; i--) {
        roots[i] = matrix[i][*dim];
        for (int j = i + 1; j < *dim; j++) {
            roots[i] -= matrix[i][j] * roots[j];
        }
    }

    printf("\n\nresult:\n");
    for (int i = 0; i < *dim; i++){
        printf("x%d: %.2f\n", i + 1, roots[i]);
    }

    free(matrix);
}

float **getMatrixFromFile(char *path, float **matrix, int *dim) {
    char buf[255];
    char c;
    int i, n, m, k;

    FILE *fd = fopen(path, "r");

    fgets(buf, 255, fd);
    i = 0;
    k = 0;
    m = 0;
    do {
        c = buf[i++];
        if ((c > 47 && c < 58) || c == 43 || c == 45 || c == 46) {
            if (!k) {
                k = 1;
                m++;
            }
        } else k = 0;
    } while (i < 255 && c > 0);
    rewind(fd);
    n = 1;
    k = 0;
    matrix = (float **) malloc(n * sizeof(float *));
    matrix[n - 1] = (float *) malloc(m * sizeof(float));
    while (!feof(fd)) {
        fscanf(fd, "%f", &matrix[n - 1][k++]);
        if (k == m) {
            matrix = (float **) realloc(matrix, (++n) * sizeof(float *));
            matrix[n - 1] = (float *) malloc(m * sizeof(float));
            k = 0;
        }
    }
    if (k == 0) {
        free(matrix[n - 1]);
        n--;
    }
    *dim = n;
    return matrix;
}

float **getDiagonalMatrix(float **matrix, int *dim) {
    float tmp;
    for (int i = 0; i < *dim; i++) {
        tmp = matrix[i][i];
        for (int j = *dim; j >= i; j--) {
            matrix[i][j] /= tmp;
        }
        for (int j = i + 1; j < *dim; j++) {
            tmp = matrix[j][i];
            for (int k = *dim; k >= i; k--) {
                matrix[j][k] -= tmp * matrix[i][k];
            }
        }
    }
    return matrix;
}
