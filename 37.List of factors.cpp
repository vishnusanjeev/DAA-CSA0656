#include <stdio.h>

void printFactors(int n) {
    printf("Factors of %d are: ", n);
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;
     printf("G.Vishnu Sanjeev (192210101)\n"); 
    printf("Enter the number:\n");
    scanf("%d",&n);
    printFactors(n);
    return 0;
}

