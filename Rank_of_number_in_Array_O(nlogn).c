#include <stdio.h>
#include <stdlib.h>
#define M 1000
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
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
int quickselect(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low]; 
    }
    int pivot_index = low + rand() % (high - low + 1);
    swap(&arr[pivot_index], &arr[high]); 

    int pivot = partition(arr, low, high);
    if (pivot == k) {
        return arr[pivot];
    } else if (pivot > k) {
        return quickselect(arr, low, pivot - 1, k);
    } else {
        return quickselect(arr, pivot + 1, high, k);
    }
}
int find_ith_smallest(int arr[], int n, int i) {
    if (i < 1 || i > n) {
        printf("Error: i must be between 1 and %d.\n", n);
        exit(EXIT_FAILURE);
    }
    return quickselect(arr, 0, n - 1, i - 1);
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
    int result = find_ith_smallest(arr, n, i);
    printf("The %d-th smallest element is %d\n", i, result);

    return 0;
}
