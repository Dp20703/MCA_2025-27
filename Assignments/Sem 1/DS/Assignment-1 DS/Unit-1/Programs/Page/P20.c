// 20. Write a program that reads a square matrix of size n x n. Write a function int isSymmetric
// (int a[][], int n) that returns 1 if the matrix is symmetric.
//  (Hint: Array A is symmetric if Aij = Aji for all values of i and j)

// A symmetric matrix means it is equal to its transpose, i.e. A[i][j] == A[j][i]

#include <stdio.h>

// Function to check if matrix is symmetric
int isSymmetric(int arr[10][10], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != arr[j][i])
            {
                return 0;
            }
        }
    }
    return 1; // symmetric
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

    if (isSymmetric(a, n))
        printf("\nThe matrix is Symmetric.\n");
    else
        printf("\nThe matrix is NOT Symmetric.\n");

    return 0;
}
// output
// Enter size of square matrix (n x n): 3
// Enter elements of matrix:
// 1
// 2
// 3
// 2
// 4
// 5
// 3
// 5
// 6

// Matrix:
// 1 2 3
// 2 4 5
// 3 5 6

// The matrix is Symmetric.