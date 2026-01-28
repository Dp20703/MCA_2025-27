// 18. Write a program that reads a square matrix of size n x n. Write a function int isUpperTriangular (int a[][], int n) that returns 1 if the matrix is upper triangular.
//(Hint: Array A is upper triangular if Aij = 0 and i>j)


// An upper triangular matrix is one where all elements below the main diagonal are 0 (i > j)
#include <stdio.h>

// Function to check if matrix is upper triangular
int isUpperTriangular(int a[10][10], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
        { // check only below diagonal (i > j)
            if (a[i][j] != 0)
            {
                return 0; // not upper triangular
            }
        }
    }
    return 1; // upper triangular
}

int main()
{
    int a[10][10], n, i, j;

    printf("Enter size of square matrix (n x n): ");
    scanf("%d", &n);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Display matrix
    printf("\nMatrix is:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    // Check result
    if (isUpperTriangular(a, n))
        printf("\nThe matrix is Upper Triangular.\n");
    else
        printf("\nThe matrix is NOT Upper Triangular.\n");

    return 0;
}

// output

// Enter size of square matrix (n x n): 3
// Enter elements of the matrix:
// 1
// 2
// 3
// 0
// 1
// 1
// 0
// 0
// 2

// Matrix is:
// 1       2       3
// 0       1       1
// 0       0       2

// The matrix is Upper Triangular.