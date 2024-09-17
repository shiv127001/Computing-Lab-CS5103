// Write a program to implement the merge sort algorithm using the divide and conquer technique. The program should take an unsorted array of integers as input and output the sorted array.


#include <stdio.h>
#include <stdlib.h>

// Function to merge two halves of the array
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;  // Size of the left half
    int n2 = right - mid;     // Size of the right half

    // Temporary arrays to hold the two halves
    int* leftArr = (int*)malloc(n1 * sizeof(int));
    int* rightArr = (int*)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays
    for (i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // Merge the two halves back into arr
    i = 0;  // Initial index of left half
    j = 0;  // Initial index of right half
    k = left;  // Initial index of merged array
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr, if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr, if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // Free the temporary arrays
    free(leftArr);
    free(rightArr);
}

// Recursive function to implement Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Find the middle point

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Dynamically allocate memory for the array
    int* arr = (int*)malloc(n * sizeof(int));

    // Input the array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform merge sort
    mergeSort(arr, 0, n - 1);

    // Output the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
