// 15. Write a program that reads a matrix and displays
// the sum of its diagonal elements.

#include <stdio.h>

int main()
{
    int n;
    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    int mat[n][n];

    // Input matrix
    printf("Enter elements of %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    int sum = 0;

    // Sum of main diagonal
    for (int i = 0; i < n; i++)
    {
        sum += mat[i][i];
    }

    printf("Sum of diagonal elements = %d\n", sum);

    return 0;
}
// output

// Enter size of square matrix: 3
// Enter elements of 3x3 matrix:
// 1 2 3
// 4 5 6
// 7 8 9

// Sum of diagonal elements = 15
