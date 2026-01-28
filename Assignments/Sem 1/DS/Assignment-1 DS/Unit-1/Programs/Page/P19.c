// 19. Write a program that reads a square matrix of size n x n. Write a function int isLowerTriangular (int a[][], int n) that returns 1 if the matrix is lower triangular.
// (Hint: Array A is lower triangular if Aij = 0 and i<j)

#include <stdio.h>

// Function to check if matrix is lower triangular
int isLowerTriangular(int a[10][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) // check elements above main diagonal (i < j)
        {
            if (a[i][j] != 0)
                return 0; // not lower triangular
        }
    }
    return 1; // lower triangular
}

int main()
{
    int a[10][10], n;

    printf("Enter size of square matrix (n x n): ");
    scanf("%d", &n);

    printf("Enter elements of matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nMatrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    if (isLowerTriangular(a, n))
        printf("\nThe matrix is Lower Triangular.\n");
    else
        printf("\nThe matrix is NOT Lower Triangular.\n");

    return 0;
}

// output
// Enter size of square matrix (n x n): 3
// Enter elements of matrix:
// 1
// 0
// 0
// 3
// 3
// 0
// 1
// 1
// 1

// Matrix:
// 1 0 0
// 3 3 0
// 1 1 1

// The matrix is Lower Triangular.