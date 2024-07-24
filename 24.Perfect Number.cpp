#include <stdio.h>

// Function to check if a number is perfect
int isPerfect(int num) {
    int sum = 0;

    // Find divisors and add them
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // Check if sum of divisors is equal to the number
    if (sum == num) {
        return 1; // True
    } else {
        return 0; // False
    }
}

int main() {
    int num;
    printf("G.Vishnu Sanjeev (192210101)\n");
    // Input number
    printf("Enter a number to check if it is a perfect number: ");
    scanf("%d", &num);

    // Check and print result
    if (isPerfect(num)) {
        printf("%d is a perfect number.\n", num);
    } else {
        printf("%d is not a perfect number.\n", num);
    }

    return 0;
}

