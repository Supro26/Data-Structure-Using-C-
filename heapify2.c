#include <stdio.h>
#include <stdlib.h>
int c = 0;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left   = 2*i + 1;
    int right  = 2*i + 2;

    if (left < n) {
        c++;
        if (arr[left] > arr[largest])
            largest = left;
    }

    if (right < n) {
        c++;
        if (arr[right] > arr[largest])
            largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        c++;
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);

    for (int i = n - 1; i > 0; i--) {
        c++;
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Original array : ");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array   : ");
    printArray(arr, n);

    printf("Time Complexity is : %d\n", c);
    return 0;
}