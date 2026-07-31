#include <stdio.h>

int sumArray(int *ptr, int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum = sum + *(ptr + i);
    }

    return sum;
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = sumArray(arr, n);

    printf("Sum of all elements = %d\n", result);

    return 0;
}