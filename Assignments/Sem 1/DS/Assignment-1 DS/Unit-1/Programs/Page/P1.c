// 1. Consider an array MARKS[20][5] which stores the
// marks obtained by 20 students in 5 subjects. Now
// write a program to
// (a) find the average marks obtained in each
// subject.
// (b) find the average marks obtained by every
// student.
// (c) find the number of students who have scored
// below 50 in their average.
// (d) display the scores obtained by every student.

#include <stdio.h>

int main()
{
    int student = 20;
    int subject = 5;
    int marks[student][subject];

    // Input marks
    printf("Enter marks of students:\n");
    for (int i = 0; i < student; i++)
    {
        printf("\n--- Student %d ---\n", i + 1);
        for (int j = 0; j < subject; j++)
        {
            printf("Enter marks for Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
        }
    }

    // (a) find the average marks obtained in each subject.
    // Average marks for each subject
    printf("\nAverage marks in each subject:\n");
    for (int j = 0; j < subject; j++)
    {
        int sum = 0;
        for (int i = 0; i < student; i++)
        {
            sum += marks[i][j];
        }
        printf("Subject %d Average = %.2f\n", j + 1, (float)sum / student);
    }

    // (b) find the average marks obtained by every student.
    // Average marks for each student
    printf("\nAverage marks of each student:\n");
    int below50count = 0;
    for (int i = 0; i < student; i++)
    {
        int total = 0;
        for (int j = 0; j < subject; j++)
        {
            total += marks[i][j];
        }
        float avg = (float)total / subject;
        printf("Student %d Average = %.2f\n", i + 1, avg);

        // (c) find the number of students who have scored below 50 in their average.
        // (c) Check if avg < 50
        if (avg < 50)
            below50count++;
    }

    printf("\nNumber of students below 50 average: %d\n", below50count);

    // (d) Display all marks
    printf("\nMarks of each student:\n");
    for (int i = 0; i < student; i++)
    {
        printf("Student %d: ", i + 1);
        for (int j = 0; j < subject; j++)
        {
            printf("%d ", marks[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// output:
// Marks of each student:
// Student 1: 69 98 87 89 45
// Student 2: 82 98 65 45 52
// Student 3: 98 89 87 89 84