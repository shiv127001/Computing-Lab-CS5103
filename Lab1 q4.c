//Write a program to multiply two matrices. Assume the input will always be in a compatible format for multiplying

#include <stdio.h>

#define MAX 100

// Function to multiply two matrices
void multiplyMatrices(int firstMatrix[MAX][MAX], int secondMatrix[MAX][MAX], int result[MAX][MAX], int row1, int col1, int row2, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

// Function to take input of matrix elements
void inputMatrix(int matrix[MAX][MAX], int row, int col) {
    printf("Enter elements of the matrix (%dx%d):\n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display the matrix
void displayMatrix(int matrix[MAX][MAX], int row, int col) {
    printf("Resultant Matrix (%dx%d):\n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int firstMatrix[MAX][MAX], secondMatrix[MAX][MAX], result[MAX][MAX];
    int row1, col1, row2, col2;

    // Input for the first matrix
    printf("Enter the number of rows and columns of the first matrix:\n");
    scanf("%d %d", &row1, &col1);

    // Input for the second matrix
    printf("Enter the number of rows and columns of the second matrix:\n");
    scanf("%d %d", &row2, &col2);

    // Check if multiplication is possible
    if (col1 != row2) {
        printf("Matrix multiplication is not possible. Column of the first matrix must equal the row of the second matrix.\n");
        return 1;
    }

    // Input matrices
    inputMatrix(firstMatrix, row1, col1);
    inputMatrix(secondMatrix, row2, col2);

    // Multiply the matrices
    multiplyMatrices(firstMatrix, secondMatrix, result, row1, col1, row2, col2);

    // Display the result
    displayMatrix(result, row1, col2);

    return 0;
}
