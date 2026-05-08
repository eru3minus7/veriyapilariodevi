#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[SIZE], copy[SIZE];
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1001;
        copy[i] = arr[i];
    }

    clock_t start, end;
    start = clock();
    insertionSort(arr, SIZE);
    end = clock();
    printf("Insertion Sort süresi: %f saniye\n", (double)(end-start)/CLOCKS_PER_SEC);

    start = clock();
    selectionSort(copy, SIZE);
    end = clock();
    printf("Selection Sort süresi: %f saniye\n", (double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}
