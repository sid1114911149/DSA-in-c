#include <stdio.h>
int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;   
    int j = mid + 1;
    int k = left; 
    int invCount = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    return invCount;
}
int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    int mid, invCount = 0;
    if (left < right) {
        mid = (left + right) / 2;
        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);
        invCount += mergeAndCount(arr, temp, left, mid, right);
    }
    return invCount;
}
int countInversions(int arr[], int n) {
    int temp[n];
    return mergeSortAndCount(arr, temp, 0, n - 1);
}
int main() {
    int arr[] = {5, 3, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int inversionCount = countInversions(arr, n);
    printf("Number of inversions: %d\n", inversionCount);
    return 0;
}
