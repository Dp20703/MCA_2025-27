// 10. Write a program to count the total number of non-zero elements in a two-dimensional array.
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
    int count = 0;

    printf("\nThe %d x %d Matrix is:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != 0)
            {
                count++;
            }
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("\nTotal number of non -zero elements: %d ", count);
    return 0;
}

// output
// Enter size of square matrix: 2
// Enter elements of 2x2 matrix:
// mat[0][0] = 1
// mat[0][1] = 0
// mat[1][0] = 10
// mat[1][1] = 0

// The 2 x 2 Matrix is:
// 1       0
// 10      0

// Total number of non -zero elements: 2