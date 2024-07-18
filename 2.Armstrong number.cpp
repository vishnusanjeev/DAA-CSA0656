#include <stdio.h>
#include <math.h>
int count_digits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}
int is_armstrong(int num) {
    int original_num, remainder, result = 0;
    int n = count_digits(num);

    original_num = num;
    while (original_num != 0) {
        remainder = original_num % 10;
        result += pow(remainder, n);
        original_num /= 10;
    }

    return (result == num);
}

int main() {
	printf("G.Vishnu Sanjeev (192210101)\n");
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    if (is_armstrong(num)) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }

    return 0;
}
