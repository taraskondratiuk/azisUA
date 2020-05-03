#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n, int *ops, int *mem) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            (*ops)++;
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int partition(int arr[], int low, int high, int *ops) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        (*ops)++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int *ops, int *mem) {
    if (low < high) {
        int pi = partition(arr, low, high, ops);
        quickSort(arr, low, pi - 1, ops, mem);
        quickSort(arr, pi + 1, high, ops, mem);
    }
}

int getNextGap(int gap) {
    gap = (gap * 10) / 13;

    if (gap < 1) {
        return 1;
    }
    return gap;
}

void combSort(int a[], int n, int *ops, int *mem) {
    int gap = n;

    int swapped = 1;
    while (gap != 1 || swapped == 1) {
        gap = getNextGap(gap);

        swapped = 0;

        for (int i = 0; i < n - gap; i++) {
            (*ops)++;
            if (a[i] > a[i + gap]) {
                swap(&a[i], &a[i + gap]);
                swapped = 1;
            }
        }
    }
}

void gnomeSort(int arr[], int n, int *ops, int *mem) {
    int index = 0;

    while (index < n) {
        (*ops)++;
        if (index == 0) {
            index++;
        }
        (*ops)++;
        if (arr[index] >= arr[index - 1]) {
            index++;
        } else {
            swap(&arr[index], &arr[index - 1]);
            index--;
        }
    }
}

void insertionSort(int arr[], int n, int *ops, int *mem) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            (*ops)++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {

    FILE *f = fopen("../16v14.txt", "r");

    int bufferLength = 255;
    char buffer[bufferLength];
    for (int i = 0; i < bufferLength; ++i) {
        buffer[i] = '\0';
    }
    int numsFromFile1[1728];
    int numsFromFile2[1728];
    int numsFromFile3[1728];
    int numsFromFile4[1728];
    int numsFromFile5[1728];

    int i = 0;
    while (fgets(buffer, bufferLength, f)) {
        char *num = strtok(buffer, " \n");

        while (num != NULL) {
            numsFromFile1[i] = atoi(num);
            numsFromFile2[i] = atoi(num);
            numsFromFile3[i] = atoi(num);
            numsFromFile4[i] = atoi(num);
            numsFromFile5[i] = atoi(num);

            i++;
            num = strtok(NULL, " \n");
        }
    }


    int ascArr1[1728];
    int ascArr2[1728];
    int ascArr3[1728];
    int ascArr4[1728];
    int ascArr5[1728];

    int descArr1[1728];
    int descArr2[1728];
    int descArr3[1728];
    int descArr4[1728];
    int descArr5[1728];

    int onesZerosArr1[1728];
    int onesZerosArr2[1728];
    int onesZerosArr3[1728];
    int onesZerosArr4[1728];
    int onesZerosArr5[1728];

    for (int j = 0; j < 1728; ++j) {
        ascArr1[j] = j;
        ascArr2[j] = j;
        ascArr3[j] = j;
        ascArr4[j] = j;
        ascArr5[j] = j;
    }
    for (int k = 0; k < 1728; ++k) {
        descArr1[1728 - k] = k;
        descArr2[1728 - k] = k;
        descArr3[1728 - k] = k;
        descArr4[1728 - k] = k;
        descArr5[1728 - k] = k;
    }
    for (int l = 0; l < 1728; ++l) {
        onesZerosArr1[l]= l % 2 == 0 ? 0 : 1;
        onesZerosArr2[l]= l % 2 == 0 ? 0 : 1;
        onesZerosArr3[l]= l % 2 == 0 ? 0 : 1;
        onesZerosArr4[l]= l % 2 == 0 ? 0 : 1;
        onesZerosArr5[l]= l % 2 == 0 ? 0 : 1;
    }

    int *operationsP1;
    int *operationsP2;
    int *operationsP3;
    int *operationsP4;
    int operations = 0;
    operationsP1 = &operations;
    operationsP2 = &operations;
    operationsP3 = &operations;
    operationsP4 = &operations;

    int *additionalMemoryP1;
    int *additionalMemoryP2;
    int *additionalMemoryP3;
    int *additionalMemoryP4;
    int  additionalMemory = 0;
    additionalMemoryP1 = &additionalMemory;
    additionalMemoryP2 = &additionalMemory;
    additionalMemoryP3 = &additionalMemory;
    additionalMemoryP4 = &additionalMemory;

    printf("\n\nbubble sort\n");
    bubbleSort(ascArr1, 1728, operationsP1, additionalMemoryP1);
    printf("\nascending arr operations: %d additional memory: %d", *operationsP1, *additionalMemoryP1);

    bubbleSort(descArr1, 1728, operationsP2, additionalMemoryP2);
    printf("\ndescending arr operations: %d additional memory: %d", *operationsP2, *additionalMemoryP2);

    bubbleSort(numsFromFile1, 1728, operationsP3, additionalMemoryP3);
    printf("\nfile arr operations: %d additional memory: %d", *operationsP3, *additionalMemoryP3);

    bubbleSort(onesZerosArr1, 1728, operationsP4, additionalMemoryP4);
    printf("\nones and zeros arr operations: %d additional memory: %d", *operationsP4, *additionalMemoryP4);

    operationsP1 = &operations;
    operationsP2 = &operations;
    operationsP3 = &operations;
    operationsP4 = &operations;

    additionalMemoryP1 = &additionalMemory;
    additionalMemoryP2 = &additionalMemory;
    additionalMemoryP3 = &additionalMemory;
    additionalMemoryP4 = &additionalMemory;

    printf("\n\nquick sort\n");
    quickSort(ascArr2, 0, 1727, operationsP1, additionalMemoryP1);
    printf("\nascending arr operations: %d additional memory: %d", *operationsP1, *additionalMemoryP1);

    quickSort(descArr2, 0, 1727, operationsP2, additionalMemoryP2);
    printf("\ndescending arr operations: %d additional memory: %d", *operationsP2, *additionalMemoryP2);

    quickSort(numsFromFile2, 0, 1727, operationsP3, additionalMemoryP3);
    printf("\nfile arr operations: %d additional memory: %d", *operationsP3, *additionalMemoryP3);

    quickSort(onesZerosArr2, 0, 1727, operationsP4, additionalMemoryP4);
    printf("\nones and zeros arr operations: %d additional memory: %d", *operationsP4, *additionalMemoryP4);

    operationsP1 = &operations;
    operationsP2 = &operations;
    operationsP3 = &operations;
    operationsP4 = &operations;

    additionalMemoryP1 = &additionalMemory;
    additionalMemoryP2 = &additionalMemory;
    additionalMemoryP3 = &additionalMemory;
    additionalMemoryP4 = &additionalMemory;

    printf("\n\ncomb sort\n");
    combSort(ascArr3, 1728, operationsP1, additionalMemoryP1);
    printf("\nascending arr operations: %d additional memory: %d", *operationsP1, *additionalMemoryP1);

    combSort(descArr3, 1728, operationsP2, additionalMemoryP2);
    printf("\ndescending arr operations: %d additional memory: %d", *operationsP2, *additionalMemoryP2);

    combSort(numsFromFile3, 1728, operationsP3, additionalMemoryP3);
    printf("\nfile arr operations: %d additional memory: %d", *operationsP3, *additionalMemoryP3);

    combSort(onesZerosArr3, 1728, operationsP4, additionalMemoryP4);
    printf("\nones and zeros arr operations: %d additional memory: %d", *operationsP4, *additionalMemoryP4);

    operationsP1 = &operations;
    operationsP2 = &operations;
    operationsP3 = &operations;
    operationsP4 = &operations;

    additionalMemoryP1 = &additionalMemory;
    additionalMemoryP2 = &additionalMemory;
    additionalMemoryP3 = &additionalMemory;
    additionalMemoryP4 = &additionalMemory;

    printf("\n\ngnome sort\n");
    gnomeSort(ascArr4, 1728, operationsP1, additionalMemoryP1);
    printf("\nascending arr operations: %d additional memory: %d", *operationsP1, *additionalMemoryP1);

    gnomeSort(descArr4, 1728, operationsP2, additionalMemoryP2);
    printf("\ndescending arr operations: %d additional memory: %d", *operationsP2, *additionalMemoryP2);

    gnomeSort(numsFromFile4, 1728, operationsP3, additionalMemoryP3);
    printf("\nfile arr operations: %d additional memory: %d", *operationsP3, *additionalMemoryP3);

    gnomeSort(onesZerosArr4, 1728, operationsP4, additionalMemoryP4);
    printf("\nones and zeros arr operations: %d additional memory: %d", *operationsP4, *additionalMemoryP4);


    operationsP1 = &operations;
    operationsP2 = &operations;
    operationsP3 = &operations;
    operationsP4 = &operations;

    additionalMemoryP1 = &additionalMemory;
    additionalMemoryP2 = &additionalMemory;
    additionalMemoryP3 = &additionalMemory;
    additionalMemoryP4 = &additionalMemory;

    printf("\n\ninsertion sort\n");
    insertionSort(ascArr5, 1728, operationsP1, additionalMemoryP1);
    printf("\nascending arr operations: %d additional memory: %d", *operationsP1, *additionalMemoryP1);

    insertionSort(descArr5, 1728, operationsP2, additionalMemoryP2);
    printf("\ndescending arr operations: %d additional memory: %d", *operationsP2, *additionalMemoryP2);

    insertionSort(numsFromFile5, 1728, operationsP3, additionalMemoryP3);
    printf("\nfile arr operations: %d additional memory: %d", *operationsP3, *additionalMemoryP3);

    insertionSort(onesZerosArr5, 1728, operationsP4, additionalMemoryP4);
    printf("\nones and zeros arr operations: %d additional memory: %d", *operationsP4, *additionalMemoryP4);


    return 0;
}