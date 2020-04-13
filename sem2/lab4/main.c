#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int **getMatrixCopy(int **matrix, int n, int m) {
    int **matrixCopy;
    matrixCopy = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        matrixCopy[i] = (int *) malloc(m * sizeof(int));
        for (int j = 0; j < m; ++j) {
            matrixCopy[i][j] = matrix[i][j];
        }
    }
    return matrixCopy;
}

int main() {
    char buf[255];
    char c;
    int i, n, m, k;
    int **matrix;
    FILE *fd = fopen("../12v14.txt", "r");

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
    matrix = (int **) malloc(n * sizeof(int *));
    matrix[n - 1] = (int *) malloc(m * sizeof(int));
    while (!feof(fd)) {
        fscanf(fd, "%d", &matrix[n - 1][k++]);
        if (k == m) {
            matrix = (int **) realloc(matrix, (++n) * sizeof(int *));
            matrix[n - 1] = (int *) malloc(m * sizeof(int));
            k = 0;
        }
    }
    if (k == 0) {
        free(matrix[n - 1]);
        n--;
    }
    printf("%d %d", n, m);
    int *sqaresRowsArr = (int *) malloc(n * sizeof(int));
    int *sqaresColsArr = (int *) malloc(m * sizeof(int));
    for (int j = 0; j < n; ++j) {
        int sumSqares = 0;
        for (int l = 0; l < m; ++l) {
            sumSqares += matrix[j][l] * matrix[j][l];
        }
        sqaresRowsArr[j] = sumSqares;
    }
    for (int j = 0; j < m; ++j) {
        int sumSqares = 0;
        for (int l = 0; l < n; ++l) {
            sumSqares += matrix[l][j] * matrix[l][j];
        }
        sqaresColsArr[j] = sumSqares;
    }

    printf("\nmatrix: \n");
    for (int j = 0; j < n; ++j) {
        for (int l = 0; l < m; ++l) {
            printf("%d ", matrix[j][l]);
        }
        printf("\n");
    }
    printf("sum sqares rows: \n");
    for (int i1 = 0; i1 < n; ++i1) {
        printf("%d ", sqaresRowsArr[i1]);
    }
    printf("\nsum sqares cols: \n");
    for (int i1 = 0; i1 < m; ++i1) {
        printf("%d ", sqaresColsArr[i1]);
    }

    int **matrixSortedRowsCopy = getMatrixCopy(matrix, n, m);
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (sqaresRowsArr[j] > sqaresRowsArr[j + 1]) {
                int *tempRow;
                tempRow = matrixSortedRowsCopy[j];
                matrixSortedRowsCopy[j] = matrixSortedRowsCopy[j + 1];
                matrixSortedRowsCopy[j + 1] = tempRow;

                int tempNum = sqaresRowsArr[j];
                sqaresRowsArr[j] = sqaresRowsArr[j + 1];
                sqaresRowsArr[j + 1] = tempNum;
            }
        }
    }

    printf("sum sqares rows sorted: \n");
    for (int i1 = 0; i1 < n; ++i1) {
        printf("%d ", sqaresRowsArr[i1]);
    }
    printf("\nmatrix by sum sqares rows sorted: \n");
    for (int j = 0; j < n; ++j) {
        for (int l = 0; l < m; ++l) {
            printf("%d ", matrixSortedRowsCopy[j][l]);
        }
        printf("\n");
    }

    int **matrixSortedColsCopy = getMatrixCopy(matrix, n, m);
    for (int i = 0; i < m - 1; ++i) {
        for (int j = 0; j < m - i - 1; ++j) {
            if (sqaresColsArr[j] > sqaresColsArr[j + 1]) {
                for (k = 0; k < n; ++k) {
                    int temp;
                    temp = matrixSortedColsCopy[k][j];
                    matrixSortedColsCopy[k][j] = matrixSortedColsCopy[k][j + 1];
                    matrixSortedColsCopy[k][j + 1] = temp;
                }

                int tempNum = sqaresRowsArr[j];
                sqaresRowsArr[j] = sqaresRowsArr[j + 1];
                sqaresRowsArr[j + 1] = tempNum;
            }
        }
    }

    printf("sum sqares cols sorted: \n");
    for (int i1 = 0; i1 < n; ++i1) {
        printf("%d ", sqaresColsArr[i1]);
    }
    printf("\nmatrix by sum sqares cols sorted: \n");
    for (int j = 0; j < n; ++j) {
        for (int l = 0; l < m; ++l) {
            printf("%d ", matrixSortedColsCopy[j][l]);
        }
        printf("\n");
    }

    int **matrixTranspered;
    matrixTranspered = (int **) malloc(m * sizeof(int *));
    for (int i = 0; i < m; ++i) {
        matrixTranspered[i] = (int *) malloc(n * sizeof(int));
        for (int j = 0; j < n; ++j) {
            matrixTranspered[i][j] = matrix[j][i];
        }
    }

    printf("\ntranspered matrix: \n");
    for (int j = 0; j < n; ++j) {
        for (int l = 0; l < m; ++l) {
            printf("%d ", matrixTranspered[j][l]);
        }
        printf("\n");
    }

    int **matrixSquare;
    matrixSquare = (int **) malloc((m * sizeof(int *)));
    for (int i = 0; i < n; ++i) {
        matrixSquare[i] = (int *) malloc(m * sizeof(int));
        for (int j = 0; j < n; ++j) {
            matrixSquare[i][j] = matrix[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m / 2; ++j) {
            int temp = matrixSquare[i][j];
            matrixSquare[i][j] = matrixSquare[i][m - j - 1];
            matrixSquare[i][m - j - 1] = temp;
        }
    }

    printf("\nmatrix around veritcal axle: \n");
    for (int j = 0; j < m; ++j) {
        for (int l = 0; l < m; ++l) {
            printf("%d ", matrixSquare[j][l]);
        }
        printf("\n");
    }
}