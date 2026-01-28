// 8. Write a program to add two 3 x 3 matrix using
// pointers.

#include <stdio.h>

int main()
{
    int mat1[3][3], mat2[3][3], sum[3][3];
    int *p1, *p2, *p3;

    // Assign pointers
    p1 = &mat1[0][0];
    p2 = &mat2[0][0];
    p3 = &sum[0][0];

    // Input first matrix
    printf("Enter elements of first 3x3 matrix:\n");
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", (p1 + i));
    }

    // Input second matrix
    printf("Enter elements of second 3x3 matrix:\n");
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", (p2 + i));
    }

    // Add matrices using pointers
    for (int i = 0; i < 9; i++)
    {
        *(p3 + i) = *(p1 + i) + *(p2 + i);
    }

    // Display sum matrix
    printf("Resultant Matrix after Addition:\n");
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", *(p3 + i));
        if ((i + 1) % 3 == 0) // new line after every 3 elements
            printf("\n");
    }

    return 0;
}

// output

// Enter elements of first 3x3 matrix:
// 12
// 10
// 20
// 30
// 20
// 30
// 15
// 20
// 30
// Enter elements of second 3x3 matrix:
// 10
// 20
// 30
// 40
// 50
// 60
// 70
// 80
// 90
// Resultant Matrix after Addition:
// 22 30 50
// 70 70 90
// 85 100 120
