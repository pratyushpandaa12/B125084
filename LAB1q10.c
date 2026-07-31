#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

int main() {
    int n, highest = 0;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student *s;

    s = (struct Student *)malloc(n * sizeof(struct Student));

    if (s == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &s[i].rollNo);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Marks: ");
        scanf("%f", &s[i].marks);

        if (s[i].marks > s[highest].marks) {
            highest = i;
        }
    }

    printf("\nStudent with Highest Marks:\n");
    printf("Roll Number : %d\n", s[highest].rollNo);
    printf("Name        : %s\n", s[highest].name);
    printf("Marks       : %.2f\n", s[highest].marks);

    free(s);

    return 0;
}