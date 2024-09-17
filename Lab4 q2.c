/*Write a program to implement the Quick Sort algorithm. However, the process of
pivot selection be as follows:
● Before selecting the pivot, check if the subarray contains the prime
number. If it does, select the smallest prime number as pivot.
● If there are no prime numbers, and the subarray size is odd, select the
middle element as the pivot.
● If the subarray size is even, then select the element ar index n/2 -1 as
pivot
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Function to find the smallest prime number in the subarray
int findSmallestPrime(int arr[], int left, int right) {
    int smallestPrime = -1;
    for (int i = left; i <= right; i++) {
        if (isPrime(arr[i])) {
            if (smallestPrime == -1 || arr[i] < smallestPrime) {
                smallestPrime = arr[i];
            }
        }
    }
    return smallestPrime;
}

// Function to partition the array using the custom pivot
int partition(int arr[], int left, int right) {
    int pivot;
    int pivotIndex;

    // Find the pivot based on the rules
    int smallestPrime = findSmallestPrime(arr, left, right);
    if (smallestPrime != -1) {
        pivot = smallestPrime;
        for (int i = left; i <= right; i++) {
            if (arr[i] == pivot) {
                pivotIndex = i;
                break;
            }
        }
    } else {
        int size = right - left + 1;
        if (size % 2 == 1) {
            pivotIndex = left + size / 2;
        } else {
            pivotIndex = left + (size / 2 - 1);
        }
        pivot = arr[pivotIndex];
    }

    // Swap the pivot to the end of the array
    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[right];
    arr[right] = temp;

    // Partition the array
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pi = partition(arr, left, right);
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
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
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input the array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform quick sort
    quickSort(arr, 0, n - 1);

    // Output the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
