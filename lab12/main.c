#include <stdio.h>
#include <stdlib.h>


#define N 8

int main() {
    int arr[N][N];

    printf("initial array :\n");

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            arr[i][j] = rand() % 100;
            printf("%.2d ", arr[i][j]);
        }
        printf("\n");
    }

    int minVal = arr[0][0];
    int minIndex = 0;



    for (int k = 1; k < N; ++k) {
        if (arr[k][k] < minVal) {
            minVal = arr[k][k];
            minIndex = k;
        }
    }

    printf("\nlast minimal element : %d\n", minVal);



    for (int row = minIndex; row < N - 1; ++row) {
        for (int m = 0; m < N; ++m) {
            arr[row][m] = arr [row+1][m];
        }
    }


    for (int col = minIndex; col < N - 1; ++col) {
        for (int m = 0; m < N; ++m) {
            arr[m][col] = arr [m][col + 1];
        }
    }

    printf("\nresult array :\n");


    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            printf("%.2d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}