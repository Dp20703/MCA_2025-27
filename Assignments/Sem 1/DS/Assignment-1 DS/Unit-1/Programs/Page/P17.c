// 17. Write a program that reads a matrix and displays the sum of the elements below the main diagonal.
// (Hint : Calculate the sum of elements Aij where i > j)

#include <stdio.h>

int main()
{
    int mat[10][10], r, c, i, j, sum = 0;

    // Input number of rows and columns
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    // Input matrix elements
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    // Calculate sum of elements below main diagonal (i > j)
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (i > j)
            {
                sum += mat[i][j];
            }
        }
    }

    // Display the matrix
    printf("\nMatrix is:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    // Print result
    printf("\nSum of elements below the main diagonal = %d\n", sum);

    return 0;
}

// output
// Enter number of rows and columns: 3
// 3
// Enter elements of the matrix:
// 1
// 2
// 3 
// 4
// 5
// 6
// 7
// 8
// 9

// Matrix is:
// 1       2       3
// 4       5       6
// 7       8       9

// Sum of elements below the main diagonal = 191