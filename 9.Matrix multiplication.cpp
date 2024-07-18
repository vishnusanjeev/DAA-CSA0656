#include <stdio.h>
void multiply_matrices(int firstMatrix[][10], int secondMatrix[][10], int result[][10], int row1, int col1, int row2, int col2) {
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < col1; ++k) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}
void print_matrix(int matrix[][10], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
	printf("G.Vishnu Sanjeev (192210101)\n");
    int row1, col1, row2, col2;
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &row1, &col1);
    int firstMatrix[10][10];
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col1; ++j) {
            scanf("%d", &firstMatrix[i][j]);
        }
    }
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &row2, &col2);
    if (col1 != row2) {
        printf("Error! Column of the first matrix must be equal to row of the second matrix.\n");
        return -1;
    }
    int secondMatrix[10][10];
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < row2; ++i) {
        for (int j = 0; j < col2; ++j) {
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    int result[10][10];
    multiply_matrices(firstMatrix, secondMatrix, result, row1, col1, row2, col2);
    printf("Resulting matrix:\n");
    print_matrix(result, row1, col2);

    return 0;
}
