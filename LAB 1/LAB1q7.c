#include <stdio.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

int main() {
    struct Student s[5];
    float sum = 0, average;
    int highest = 0;

    printf("Enter details of 5 students:\n");

    for (int i = 0; i < 5; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &s[i].rollNo);

        printf("Enter Name: ");
        scanf("%s", s[i].name);

        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);

        sum += s[i].marks;

        if (s[i].marks > s[highest].marks) {
            highest = i;
        }
    }

    average = sum / 5;

    printf("\nStudent with Highest Marks:\n");
    printf("Roll Number : %d\n", s[highest].rollNo);
    printf("Name        : %s\n", s[highest].name);
    printf("Marks       : %.2f\n", s[highest].marks);

    printf("\nAverage Marks of the Class = %.2f\n", average);

    return 0;
}