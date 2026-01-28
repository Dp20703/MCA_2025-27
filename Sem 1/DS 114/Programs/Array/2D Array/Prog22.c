// 22. Write a program to input two m x n matrices and then calculate the sum of their
//     corresponding elements and store it in a third m X n matrix.

#include <stdio.h>
#include <conio.h>
int main()
{
    int i, j;
    int rows1, cols1, rows2, cols2, rows_sum, cols_sum;
    int mat1[5][5], mat2[5][5], sum[5][5];
    // clrscr();
    printf("\n Enter the number of rows in the first matrix : ");
    scanf("%d", &rows1);
    printf("\n Enter the number of columns in the first matrix : ");
    scanf("%d", &cols1);
    printf("\n Enter the number of rows in the second matrix : ");
    scanf("%d", &rows2);
    printf("\n Enter the number of columns in the second matrix : ");
    scanf("%d", &cols2);
    if (rows1 != rows2 || cols1 != cols2)
    {
        printf("\n Number of rows and columns of both matrices must be equal");
        // getch();
        // exit();
        return 0;
    }
    rows_sum = rows1;
    cols_sum = cols1;
    printf("\n Enter the elements of the first matrix ");
    for (i = 0; i < rows1; i++)
    {
        for (j = 0; j < cols1; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("\n Enter the elements of the second matrix ");
    for (i = 0; i < rows2; i++)
    {
        for (j = 0; j < cols2; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }
    for (i = 0; i < rows_sum; i++)
    {
        for (j = 0; j < cols_sum; j++)
            sum[i][j] = mat1[i][j] + mat2[i][j];
    }
    printf("\n The elements of the resultant matrix are ");
    for (i = 0; i < rows_sum; i++)
    {
        printf("\n");
        for (j = 0; j < cols_sum; j++)
            printf("\t %d", sum[i][j]);
    }
    return 0;
}