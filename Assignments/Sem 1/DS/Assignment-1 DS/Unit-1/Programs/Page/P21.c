// 21. Write a program to calculate XA + YB where A and B are matrices and X = 2 and Y = 3.

#include <stdio.h>

int main()
{
    int A[10][10], B[10][10], R[10][10];
    int X = 2, Y = 3;
    int m, n;

    printf("Enter the number of rows and columns of matrices: ");
    scanf("%d %d", &m, &n);

    printf("\nEnter elements of Matrix A:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter elements of Matrix B:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    // Calculate R = X*A + Y*B
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            R[i][j] = X * A[i][j] + Y * B[i][j];
        }
    }

    printf("\nResultant Matrix (2A + 3B):\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }

    return 0;
}
// output
// Enter the number of rows and columns of matrices: 3
// 3

// Enter elements of Matrix A:
// 1
// 2
// 3
// 4
// 6
// 6
// 7
// 8
// 9

// Enter elements of Matrix B:
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9

// Resultant Matrix (2A + 3B):
// 5 10 15
// 20 27 30
// 35 40 45