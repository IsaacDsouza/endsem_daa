#include <stdio.h>

void counting_sort(int A[], int n) {
    int i, j;
    int S[15], C[100];

    // Initialize count array to 0
    for (i = 0; i < 100; i++)
        C[i] = 0;

    // Count the occurrences of each element
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (A[i] < A[j])
                C[j]++;
            else if (i != j) // Increment only when A[i] < A[j] and i != j
                C[i]++;
        }
    }

    // Place the elements in sorted order using count array
    for (i = 0; i < n; i++)
        S[C[i]] = A[i];

    printf("The Sorted array is : ");
    for (i = 0; i < n; i++)
        printf("%d ", S[i]);
}

int main() {
    int n, A[15], i;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    printf("\nEnter the integers to be sorted:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    counting_sort(A, n);
    printf("\n");

    return 0;
}
