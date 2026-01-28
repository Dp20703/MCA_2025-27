// 6. Write a program to read and display a square
// (using functions).

#include <stdio.h>

// Function to read a square matrix
void readMatrix(int mat[50][50], int n)
{
    printf("Enter elements of %d x %d matrix:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("mat[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

// Function to display a square matrix
void displayMatrix(int mat[50][50], int n)
{
    printf("\nThe %d x %d Matrix is:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    int matrix[50][50];

    printf("Enter size of square matrix (n x n): ");
    scanf("%d", &n);

    readMatrix(matrix, n);
    displayMatrix(matrix, n);

    return 0;
}

// output
// Enter size of square matrix (n x n): 3
// Enter elements of 3 x 3 matrix:
// mat[0][0] = 20
// mat[0][1] = 30
// mat[0][2] = 10
// mat[1][0] = 52
// mat[1][1] = 32
// mat[1][2] = 32
// mat[2][0] = 14
// mat[2][1] = 52
// mat[2][2] = 32

// The 3 x 3 Matrix is:
// 20      30      10
// 52      32      32
// 14      52      32
