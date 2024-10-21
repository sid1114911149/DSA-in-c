#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define M 1000
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high, int pivot) {
    int pivot_index;
    for (int i = low; i <= high; i++) {
        if (arr[i] == pivot) {
            pivot_index = i;
            break;
        }
    }
    swap(&arr[pivot_index], &arr[high]);
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
int findMedian(int arr[], int low, int n) {
    for (int i = low; i < low + n - 1; i++) {
        for (int j = i + 1; j < low + n; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
    return arr[low + n / 2];
}
int medianOfMediansSelect(int arr[], int low, int high, int i) {
    if (low == high) {
        return arr[low];
    }
    int n = high - low + 1;
    int numMedians = (n + 4) / 5; 
    int *medians = (int *)malloc(numMedians * sizeof(int));

    for (int j = 0; j < numMedians; j++) {
        int groupSize = (j == numMedians - 1) ? (n % 5) : 5;
        if (groupSize == 0) groupSize = 5;
        medians[j] = findMedian(arr, low + j * 5, groupSize);
    }
    int medianOfMedians = medianOfMediansSelect(medians, 0, numMedians - 1, numMedians / 2);
    free(medians);
    int pivotIndex = partition(arr, low, high, medianOfMedians);
    if (pivotIndex == i) {
        return arr[pivotIndex];
    } else if (pivotIndex > i) {
        return medianOfMediansSelect(arr, low, pivotIndex - 1, i);
    } else {
        return medianOfMediansSelect(arr, pivotIndex + 1, high, i);
    }
}
int findIthSmallest(int arr[], int n, int i) {
    if (i < 1 || i > n) {
        printf("Error: i must be between 1 and %d.\n", n);
        exit(EXIT_FAILURE);
    }
    return medianOfMediansSelect(arr, 0, n - 1, i - 1);
}
int main() {
    int arr[M],n,i;
    printf("Enter the number of elements in the array:");
    scanf("%d",&n);
    printf("enter the elements of the array:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the rank of the element to find:");
    scanf("%d",&i);
    int result = findIthSmallest(arr, n, i);
    printf("The %d-th smallest element is %d\n", i, result);

    return 0;
}
