#include <stdio.h>
#include <limits.h>
int max(int a, int b, int c) {
    if (a >= b && a >= c) return a;
    else if (b >= a && b >= c) return b;
    else return c;
}
int maxCrossingSum(int arr[], int left, int mid, int right) {
    int sum = 0;
    int leftSum = INT_MIN;
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }
    sum = 0;
    int rightSum = INT_MIN;
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        if (sum > rightSum) {
            rightSum = sum;
        }
    }
    return leftSum + rightSum;
}
int maxSubArraySum(int arr[], int left, int right) {
    if (left == right) {
        return arr[left];
    }
    int mid = (left + right) / 2;
    int maxLeftSum = maxSubArraySum(arr, left, mid);
    int maxRightSum = maxSubArraySum(arr, mid + 1, right);
    int maxCrossSum = maxCrossingSum(arr, left, mid, right);
    return max(maxLeftSum, maxRightSum, maxCrossSum);
}
int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubArraySum(arr, 0, n - 1);
    printf("Maximum subarray sum is: %d\n", maxSum);
    return 0;
}
