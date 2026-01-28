// 23. Write a program to multiply two m ¥ n matrices

#include <stdio.h>

int main()
{
    int m, n, p;

    // Input dimensions
    printf("Enter number of rows for first matrix (m): ");
    scanf("%d", &m);
    printf("Enter number of columns for first matrix / rows for second matrix (n): ");
    scanf("%d", &n);
    printf("Enter number of columns for second matrix (p): ");
    scanf("%d", &p);

    int mat1[m][n], mat2[n][p], result[m][p];

    // Input first matrix
    printf("Enter elements of first matrix (%d x %d):\n", m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("mat1[%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    // Input second matrix
    printf("Enter elements of second matrix (%d x %d):\n", n, p);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            printf("mat2[%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    // Initialize result matrix to 0
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            result[i][j] = 0;
        }
    }

    // Multiply matrices
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < n; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // Display result matrix
    printf("\nResulting matrix (%d x %d):\n", m, p);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            printf("%6d", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
