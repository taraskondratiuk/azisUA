#include <stdio.h>
#include <stdlib.h>

#define N 10

int main() {
    int arr[N][N];

    printf("initial array :\n\n");

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            arr[i][j] = rand() % 100;
            printf("%.2d ", arr[i][j]);
        }
        printf("\n");
    }

//bubble sort

    for (int column = 0; column < N; ++column) {
        for (int k = 0; k < N - 1; ++k) {
            for (int i = 0; i < N - k - 1; ++i) {
                if (arr[i][column] > arr[i + 1][column]) {
                    int temp = arr[i][column];
                    arr[i][column] = arr[i + 1][column];
                    arr[i + 1][column] = temp;
                }
            }
        }
    }

    printf("\nsorted array :\n\n");

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%.2d ", arr[i][j]);
        }
        printf("\n");
    }


    return 0;
}