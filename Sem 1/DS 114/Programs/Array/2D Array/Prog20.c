// 20. Write a program to read and display a 3 ¥ 3 matrix.

#include <stdio.h>

int main()
{
    int mat[3][3];

    // Input matrix elements
    printf("Enter elements of 3x3 matrix:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    // Display matrix
    printf("\nThe 3x3 matrix is:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%4d", mat[i][j]); // formatted for alignment
        }
        printf("\n");
    }

    return 0;
}
