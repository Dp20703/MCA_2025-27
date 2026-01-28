// 9. Write a program that computes the product of the
// elements that are stored on the diagonal above the
// main diagonal.

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
            printf("mat[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    // Compute product of elements above main diagonal
    int product = 1, found = 0;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n)
        {
            product *= mat[i][i + 1];
            found = 1;
        }
    }

    if (found)
        printf("Product of elements above main diagonal = %d\n", product);
    else
        printf("No elements above main diagonal (matrix too small)\n");

    return 0;
}

// output
// Enter size of square matrix: 3
// Enter elements of 3x3 matrix:
// mat[0][0] = 10
// mat[0][1] = 20
// mat[0][2] = 30
// mat[1][0] = 20
// mat[1][1] = 20
// mat[1][2] = 30
// mat[2][0] = 1022
// mat[2][1] = 220
// mat[2][2] = 3020
// Product of elements above main diagonal = 600