#include <stdio.h>
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;  
        }
        if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; 
}
int main() {
	printf("G Vishnu Sanjeev (192210101)\n");
    int n, target, result;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter target value to search: ");
    scanf("%d", &target);
    result = binarySearch(arr, n, target);
    if (result != -1) {
        printf("Target found at index: %d\n", result);
    } else {
        printf("Target not found in the array.\n");
    }
    return 0;
}
