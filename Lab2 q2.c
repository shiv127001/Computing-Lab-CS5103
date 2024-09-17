//  Write a C program that sorts an array using pointers, ensuring the program can handle dynamic memory allocation for an array of size taken as input. You can use any sorting algorithm.

#include <stdio.h>
#include <stdlib.h>

// Function to perform Bubble Sort using pointers
void bubbleSort(int* arr, int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                // Swap the elements using pointers
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main() {
    int* arr;
    int n, i;

    // Input size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input the array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);  // Using pointer arithmetic to access array elements
    }

    // Sort the array using bubble sort
    bubbleSort(arr, n);

    // Output the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}
