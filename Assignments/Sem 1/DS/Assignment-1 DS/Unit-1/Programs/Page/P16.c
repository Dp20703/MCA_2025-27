// 16. Write a program that reads a matrix and displays the sum of the elements above the main diagonal. (Hint: Calculate the sum of elements Aij where i<j)

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

    // Sum of elements above main diagonal
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            sum += mat[i][j];
        }
    }

    printf("Sum of elements above main diagonal = %d\n", sum);

    return 0;
}

// output
// Enter size of square matrix: 3
// Enter elements of 3x3 matrix:
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// Sum of elements above main diagonal = 11