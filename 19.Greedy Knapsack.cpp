#include <stdio.h>

void knapsackGreedy(int n, float weight[], float profit[], float capacity) {
    float x[20], totalProfit = 0;
    int i, j;
    float temp;

    // Sort items by profit/weight ratio
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if ((profit[i] / weight[i]) < (profit[j] / weight[j])) {
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    for (i = 0; i < n; i++) {
        if (weight[i] > capacity) {
            break;
        } else {
            x[i] = 1.0;
            totalProfit += profit[i];
            capacity -= weight[i];
        }
    }

    if (i < n) {
        x[i] = capacity / weight[i];
        totalProfit += x[i] * profit[i];
    }

    printf("The result vector is: ");
    for (i = 0; i < n; i++) {
        printf("%.2f ", x[i]);
    }
    printf("\nMaximum profit is: %.2f\n", totalProfit);
}

int main() {
    int n = 3;
    printf("G.Vishnu Sanjeev (192210101)");
    float weight[] = {10, 20, 30};
    float profit[] = {60, 100, 120};
    float capacity = 50;

    knapsackGreedy(n, weight, profit, capacity);
    return 0;
}

