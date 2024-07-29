#include <stdio.h>
#include <stdlib.h>

void subset_sum(int s[], int t[], int s_size, int t_size, int sum, int ite, int const target_sum) {
    if (target_sum == sum) {
        for (int i = 0; i < t_size; i++)
            printf("%d ", t[i]);
        printf("\n");
        return;
    }
    for (int i = ite; i < s_size; i++) {
        t[t_size] = s[i];
        subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
    }
}

void generateSubsets(int s[], int size, int target_sum) {
    int* tuplet_vector = (int*)malloc(size * sizeof(int));
    if (tuplet_vector == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);
    free(tuplet_vector);
}

int main() {
    int size, target;
     printf("G.Vishnu Sanjeev (192210101)\n");

    // Get the number of elements in the set
    printf("Enter the number of elements in the set: ");
    scanf("%d", &size);

    int* set = (int*)malloc(size * sizeof(int));
    if (set == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Get the elements of the set from the user
    printf("Enter the elements of the set: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &set[i]);
    }

    // Get the target sum from the user
    printf("Enter the target sum: ");
    scanf("%d", &target);

    // Generate and print subsets
    generateSubsets(set, size, target);

    // Free allocated memory
    free(set);

    return 0;
}

