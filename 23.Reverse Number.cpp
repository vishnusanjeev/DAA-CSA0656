#include <stdio.h>

int reverseNumber(int num) {
    int rev = 0;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num = num / 10;
    }
    return rev;
}

int main() {
    int num = 12345;
    printf("G.Vishnu sanjeev (192210101)\n");
    printf("Reverse of %d is %d\n", num, reverseNumber(num));
    return 0;
}

