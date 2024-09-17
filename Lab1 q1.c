//Write a program to implement a basic calculator that takes two inputs, ‘A’ and ‘B,’ and performs operations such as addition, subtraction, multiplication, and division

#include <stdio.h>

// Function to perform addition
float add(float a, float b) {
    return a + b;
}

// Function to perform subtraction
float subtract(float a, float b) {
    return a - b;
}

// Function to perform multiplication
float multiply(float a, float b) {
    return a * b;
}

// Function to perform division
float divide(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error! Division by zero is not allowed.\n");
        return 0;
    }
}

int main() {
    float A, B;
    char operator;

    // Take input for two numbers
    printf("Enter two numbers (A and B): ");
    scanf("%f %f", &A, &B);

    // Input the operation to be performed
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);  // Note the space before %c to avoid reading newline characters

    // Perform the appropriate operation based on the operator input
    switch (operator) {
        case '+':
            printf("Result: %.2f\n", add(A, B));
            break;
        case '-':
            printf("Result: %.2f\n", subtract(A, B));
            break;
        case '*':
            printf("Result: %.2f\n", multiply(A, B));
            break;
        case '/':
            printf("Result: %.2f\n", divide(A, B));
            break;
        default:
            printf("Invalid operator! Please use one of +, -, *, or /.\n");
    }

    return 0;
}
