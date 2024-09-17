// Write a program that takes two sorted arrays as inputs of length n1 and n2 . Your task is to merge  both the arrays into a single sorted array.

#include <stdio.h>

// Function to merge two sorted arrays
void mergeArrays(int arr1[], int n1, int arr2[], int n2, int merged[]) {
    int i = 0, j = 0, k = 0;

    // Traverse both arrays and merge them
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // If any elements left in arr1, add them to the merged array
    while (i < n1) {
        merged[k++] = arr1[i++];
    }

    // If any elements left in arr2, add them to the merged array
    while (j < n2) {
        merged[k++] = arr2[j++];
    }
}

int main() {
    int n1, n2;

    // Input the size of the first array
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);

    int arr1[n1];
    printf("Enter %d sorted elements for the first array:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    // Input the size of the second array
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);

    int arr2[n2];
    printf("Enter %d sorted elements for the second array:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Array to store the merged result
    int merged[n1 + n2];

    // Merge the two arrays
    mergeArrays(arr1, n1, arr2, n2, merged);

    // Output the merged sorted array
    printf("Merged Sorted Array: \n");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
