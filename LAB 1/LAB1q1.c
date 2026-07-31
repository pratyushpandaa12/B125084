#include <stdio.h>

void arrayStatistics(int arr[], int n) {
    int largest, smallest, sum = 0;
    float average;

    largest = smallest = arr[0];

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest)
            largest = arr[i];

        if (arr[i] < smallest)
            smallest = arr[i];

        sum += arr[i];
    }

    average = (float)sum / n;

    printf("Largest Element = %d\n", largest);
    printf("Smallest Element = %d\n", smallest);
    printf("Average = %.2f\n", average);
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

    arrayStatistics(arr, n);

    return 0;
}