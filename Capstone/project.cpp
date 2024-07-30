#include <stdio.h>
#include <stdlib.h>

typedef struct FenwickTree {
    int size;
    int* tree;
} FenwickTree;

// Initialize a Fenwick Tree
FenwickTree* createFenwickTree(int size) {
    FenwickTree* ft = (FenwickTree*)malloc(sizeof(FenwickTree));
    ft->size = size;
    ft->tree = (int*)calloc(size + 1, sizeof(int));
    return ft;
}

// Update the Fenwick Tree
void update(FenwickTree* ft, int idx, int delta) {
    idx += 1;
    while (idx <= ft->size) {
        ft->tree[idx] += delta;
        idx += idx & -idx;
    }
}

// Query the Fenwick Tree
int query(FenwickTree* ft, int idx) {
    idx += 1;
    int sum = 0;
    while (idx > 0) {
        sum += ft->tree[idx];
        idx -= idx & -idx;
    }
    return sum;
}

// Free the memory used by the Fenwick Tree
void freeFenwickTree(FenwickTree* ft) {
    free(ft->tree);
    free(ft);
}

// Find the index of an element in an array
int findIndex(int* arr, int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1; // Should not happen in this problem as all values are present
}

int countGoodTriplets(int* nums1, int* nums2, int n) {
    // Create Fenwick Trees
    FenwickTree* bit_left = createFenwickTree(n);
    FenwickTree* bit_right = createFenwickTree(n);

    // Mapping nums2 values to their indices
    int* index_map = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        index_map[nums2[i]] = i;
    }

    // Step 3: Calculate the count of elements on the right for each element
    int* right_counts = (int*)calloc(n, sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        int idx2 = index_map[nums1[i]];
        right_counts[i] = query(bit_right, n - 1) - query(bit_right, idx2);
        update(bit_right, idx2, 1);
    }

    // Step 4: Calculate the count of elements on the left for each element
    int good_triplets = 0;
    for (int i = 0; i < n; i++) {
        int idx2 = index_map[nums1[i]];
        int left_count = query(bit_left, idx2 - 1);
        good_triplets += left_count * right_counts[i];
        update(bit_left, idx2, 1);
    }

    // Free the allocated memory
    freeFenwickTree(bit_left);
    freeFenwickTree(bit_right);
    free(right_counts);
    free(index_map);

    return good_triplets;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* nums1 = (int*)malloc(n * sizeof(int));
    int* nums2 = (int*)malloc(n * sizeof(int));

    printf("Enter elements of nums1: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums1[i]);
    }

    printf("Enter elements of nums2: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    printf("Number of good triplets: %d\n", countGoodTriplets(nums1, nums2, n));

    free(nums1);
    free(nums2);

    return 0;
}

