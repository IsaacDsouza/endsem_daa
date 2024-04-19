#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n, int range) {
    // Initialize count array with zeros
    int count[range + 1];
    for (int i = 0; i <= range; i++) {
        count[i] = 0;
    }

    // Store count of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Modify count array to store actual position of elements
    for (int i = 1; i <= range; i++) {
        count[i] += count[i - 1];
    }

    // Create output array
    int output[n];
    for (int i = 0; i < n; i++) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements into original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int range = 8; // Range of values (maximum value in the array)

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    countingSort(arr, n, range);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
