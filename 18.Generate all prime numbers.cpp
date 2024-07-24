#include <stdio.h>
#include <stdbool.h>

void generatePrimes(int n) {
    bool prime[n + 1];
    for (int i = 0; i <= n; i++) {
        prime[i] = true;
    }

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    printf("Prime numbers up to %d are: ", n);
    for (int p = 2; p <= n; p++) {
        if (prime[p] == true) {
            printf("%d ", p);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("G.Vishnu Sanjeev (192210101)\n");
    printf("Enter the upper limit to generate prime numbers: ");
    scanf("%d", &n);

    generatePrimes(n);

    return 0;
}

