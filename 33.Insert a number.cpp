#include <stdio.h>

void insertNumber(int arr[], int n, int num, int pos) {
    for (int i = n; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = num;
}

int main() {
    int arr[100], n, num, pos;
     printf("G.Vishnu Sanjeev (192210101)\n");

    // Get array size from user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Get array elements from user
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the number to be inserted from user
    printf("Enter the number to be inserted: ");
    scanf("%d", &num);

    // Get the position at which the number should be inserted from user
    printf("Enter the position at which to insert the number: ");
    scanf("%d", &pos);

    // Insert the number at the specified position
    insertNumber(arr, n, num, pos);
    n++; // Increment the size of the array after insertion

    // Print the student information
   

    // Print the array after insertion
    printf("Array after insertion: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

