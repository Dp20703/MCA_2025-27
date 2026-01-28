// 7. Write a program that computes the sum of the
// elements that are stored on the main diagonal of a matrix using pointers.

// [ 1 2 3
//   2 3 4
//   3 5 8 ]
// sum of i i [row and colum sum]

// sum = 12

#include <stdio.h>

int main()
{
    int n;
    int mat[50][50];
    int sum = 0;

    printf("Enter size of square matrix (n x n): ");
    scanf("%d", &n);

    printf("Enter elements of %d x %d matrix:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("mat[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

    // Using pointers to compute diagonal sum
    for (int i = 0; i < n; i++)
    {
        sum += *(*(mat + i) + i);
    }

    printf("\nSum of main diagonal elements = %d\n", sum);

    return 0;
}

// output
// Enter size of square matrix (n x n): 3
// Enter elements of 3 x 3 matrix:
// mat[0][0] = 1
// mat[0][1] = 2
// mat[0][2] = 3
// mat[1][0] = 4
// mat[1][1] = 5
// mat[1][2] = 6
// mat[2][0] = 7
// mat[2][1] = 8
// mat[2][2] = 9

// Sum of main diagonal elements = 15
