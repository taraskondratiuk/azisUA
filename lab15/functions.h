#include <stdlib.h>
#include <stdio.h>

void fillArrWithRandomNums(int *arr, int dimX, int dimY) {
    for (int i = 0; i < dimX; ++i) {
        for (int j = 0; j < dimY; ++j) {
            *((arr + i * dimY) + j) = rand() % 100;
        }
    }
}

void printArr(int *arr, int dimX, int dimY) {
    for (int i = 0; i < dimX; ++i) {
        for (int j = 0; j < dimY; ++j) {
            printf("%.2d ", *((arr + i * dimY) + j));
        }
        printf("\n");
    }
}

void printNumAndAvgEvenElements(void (*funcFillArr)(int *, int, int), int *arr, int dimX, int dimY) {
    (*funcFillArr)(arr, dimX, dimY);

    int numEven = 0;
    double avgEven = 0.0;

    for (int i = 0; i < dimX; ++i) {
        for (int j = 0; j < dimY; ++j) {
            int element = *((arr + i * dimY) + j);
            if (element % 2 == 0) {
                numEven++;
                avgEven = (avgEven * (numEven - 1) + element) / numEven;
            }
        }
    }

    printf("\nArray : \n");
    printArr(arr, dimX, dimY);

    printf("\nNumber of even numbers : %d, Average of even numbers : %f", numEven, avgEven);

}