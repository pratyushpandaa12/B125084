#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }

    printf("\nElements are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }

    free(arr);

    return 0;
}