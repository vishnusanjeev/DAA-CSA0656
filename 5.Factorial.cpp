#include <stdio.h>
unsigned long long factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
		printf("G.Vishnu Sanjeev (192210101)\n");
    int num;
    unsigned long long result;
    printf("Enter an integer: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        result = factorial(num);
        printf("Factorial of %d is %llu\n", num, result);
    }

    return 0;
}
