#include <stdio.h>
#include <string.h>
#include <ctype.h>
int is_palindrome(char str[]) {
    int length = strlen(str);
    int left = 0, right = length - 1;
    while (left < right) {
        char leftChar = tolower(str[left]);
        char rightChar = tolower(str[right]);
        if (!isalnum(leftChar)) {
            left++;
        } else if (!isalnum(rightChar)) {
            right--;
        } else {
            if (leftChar != rightChar) {
                return 0; 
            }
            left++;
            right--;
        }
    }
    return 1; 
}
int main() {
	printf("G.Vishnu Sanjeev (192210101)\n");
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    if (is_palindrome(str)) {
        printf("\"%s\" is a palindrome.\n", str);
    } else {
        printf("\"%s\" is not a palindrome.\n", str);
    }
    return 0;
}
