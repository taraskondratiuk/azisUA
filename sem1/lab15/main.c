#include <stdio.h>
#include "functions.h"

#define DIM_X 4
#define DIM_Y 6

int main() {
    printf("Hello, World!\n");

    int arr[DIM_X][DIM_Y];

    printNumAndAvgEvenElements(fillArrWithRandomNums, &arr[0][0], DIM_X, DIM_Y);
    return 0;
}