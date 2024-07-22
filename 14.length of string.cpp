#include <stdio.h>
#include <string.h>

int main() {
	printf("G Vishnu Sanjeev (192210101)\n");
    char str[100];
    int length;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    length = strlen(str);
    printf("Length of the string: %d\n", length);
    return 0;
}
