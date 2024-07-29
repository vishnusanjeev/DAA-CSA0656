#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 4

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool next_permutation(int* x, int n) {
    int i = n - 2;
    while (i >= 0 && x[i] >= x[i + 1]) i--;
    if (i < 0) return false;

    int j = n - 1;
    while (x[j] <= x[i]) j--;

    swap(&x[i], &x[j]);

    for (int a = i + 1, b = n - 1; a < b; a++, b--) {
        swap(&x[a], &x[b]);
    }
    return true;
}

int calculateCost(int cost[N][N], int x[], int y[], int n) {
    int costSum = 0;
    for (int i = 0; i < n; i++) {
        costSum += cost[x[i]][y[i]];
    }
    return costSum;
}

void assignmentProblem(int cost[N][N]) {
    int minCost = INT_MAX;
    int x[N], y[N];

    // Initialize x and y arrays
    for (int i = 0; i < N; i++) {
        x[i] = i;
        y[i] = i;
    }

    // Generate all permutations of y and calculate the minimum cost
    do {
        int costSum = calculateCost(cost, x, y, N);
        if (costSum < minCost) {
            minCost = costSum;
        }
    } while (next_permutation(y, N));

    printf("Minimum assignment cost: %d\n", minCost);
}

int main() {
    printf("G.Vishnu Sanjeev (192210101)\n");
    int cost[N][N] = { {9, 2, 7, 8},
                       {6, 4, 3, 7},
                       {5, 8, 1, 8},
                       {7, 6, 9, 4} };

    assignmentProblem(cost);
    return 0;
}

