#include <stdio.h>
#include <stdbool.h>
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
	printf("G.Vishnu Sanjeev (192210101)\n");
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    if (is_prime(num)) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}
