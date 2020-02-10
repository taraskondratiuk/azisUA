#include <stdio.h>
#include <stdlib.h>

#define INTERVALS_ARR_SIZE 6

int min(int *l, const int *r) {
    double min = *l;
    for (int *i = l + 1; i < r; ++i) {
        if (min > *i) {
            min = *i;
        }
    }
    return min;
}

int max(int *l, const int *r) {
    int max = *l;
    for (int *i = l + 1; i < r; ++i) {
        if (max < *i) {
            max = *i;
        }
    }
    return max;
}

double avg(int *l, const int *r, int len) {
    int sum = 0;
    for (int *i = l; i < r; ++i) {
        sum += *i;
    }
    return (double) sum / len;
}

double avgSquareDeviation(int *l, const int *r, double avg, int len) {
    double sum = 0;
    for (int *i = l; i < r; ++i) {
        sum += *i - avg;
    }
    return sum / len;
}

int getInterval(int max, int min, int len) {
    return (max - min) / (len - 1);
}

void fillIntervalsArr(int *data, int dataLen, int *intervals, int intervalsLen) {
    int interval = getInterval(max(data, data + dataLen - 1), min(data, data + dataLen - 1), intervalsLen);
    int left = min(data, data + dataLen - 1);
    for (int j = 0; j < intervalsLen; ++j) {
        for (int i = 0; i < dataLen; ++i) {
            if (data[i] >= left && data[i] < left + interval) {
                intervals[j]++;
            }
        }
        left += interval;
    }
}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

double findMod(int *intervals, int intervalsLen, int min, int max) {
    //https://i.imgur.com/8wr4Nwy.png
    int maxIndex = 0;
    for (int i = 1; i < intervalsLen; ++i) {
        if (intervals[i] > maxIndex) {
            maxIndex = i;
        }
    }
    int x0 = min + (intervalsLen * maxIndex);
    int i = getInterval(max, min, intervalsLen);
    int f0 = intervals[maxIndex];
    int fprev = intervals[maxIndex - 1];
    int fnext = intervals[maxIndex + 1];

    return x0 + i * (((double) f0 - fprev) / (2 * f0 - fprev - fnext));
}

int findMedian(int *data, int dataLen) {
    //медиана - среднее значение в отосортированных даннх
    bubbleSort(data, dataLen);
    return data[dataLen / 2];
}

void printGistogram(int * intervals, int len) {
    printf("\ngistogram: \n");
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < intervals[i]; ++j) {
            printf("**");
        }
        printf("\n");
    }
}

int main() {
    int n = 1;
    int *a;
    a = (int *) malloc(sizeof(int));
    FILE *fd = fopen("../12v14.txt", "r");
    while (!feof(fd)) {
        fscanf(fd, "%d", &a[n - 1]);
        a = realloc(a, ++n * sizeof(int));
    }
    n--;
    int mn = min(&a[0], &a[n - 1]);
    int mx = max(&a[0], &a[n - 1]);
    int ag = avg(&a[0], &a[n - 1], n);
    printf("len: %d\n", n);
    printf("min: %d\n", mn);
    printf("max: %d\n", mx);
    printf("avg: %f\n", ag);
    printf("avg square deviation: %f\n", avgSquareDeviation(&a[0], &a[n - 1], ag, n));
    int intervals[INTERVALS_ARR_SIZE];
    for (int i = 0; i < INTERVALS_ARR_SIZE; ++i) {
        intervals[i] = 0;
    }
    fillIntervalsArr(a, n, intervals, INTERVALS_ARR_SIZE);
    printf("mod: %f\n", findMod(intervals, INTERVALS_ARR_SIZE, mn, mx));
    printf("median: %d\n", findMedian(a, n));
    printGistogram(intervals, INTERVALS_ARR_SIZE);
}