//Implement a function in C that returns a pointer and also complete the full program

#include <stdio.h>
#include <stdlib.h>

// Function that returns a pointer to the result of adding two integers
int* addNumbers(int a, int b) {
    // Dynamically allocate memory for the result
    int* result = (int*)malloc(sizeof(int));
    if (result == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Store the sum in the allocated memory
    *result = a + b;
    return result;  // Return the pointer to the result
}

int main() {
    int num1, num2;

    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Call the function and get the result pointer
    int* result = addNumbers(num1, num2);

    // Check if memory allocation was successful and display the result
    if (result != NULL) {
        printf("The sum of %d and %d is: %d\n", num1, num2, *result);
        free(result);  // Free the allocated memory after use
    }

    return 0;
}
