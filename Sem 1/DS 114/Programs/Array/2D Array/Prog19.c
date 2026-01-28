// 19. Write a program to read a 2D array marks which stores the marks of five students in three subjects.
// Write a program to display the highest marks in each subject.

#include <stdio.h>

int main()
{
    int marks[5][3], i, j, max_marks;

    // Input marks
    for (i = 0; i < 5; i++)
    {
        printf("\nEnter marks of student %d:\n", i + 1);
        for (j = 0; j < 3; j++)
        {
            printf("  Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
        }
    }

    // Find highest marks in each subject
    for (j = 0; j < 3; j++)
    {
        max_marks = -999;
        for (i = 1; i < 5; i++)
        {
            if (marks[i][j] > max_marks)
            {
                max_marks = marks[i][j];
            }
        }
        printf("\nHighest marks in subject %d = %d", j + 1, max_marks);
    }

    return 0;
}
