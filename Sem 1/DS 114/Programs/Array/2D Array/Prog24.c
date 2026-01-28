// 24. Write a program to fill a square matrix with value zero on the diagonals, 1 on the upper
// right triangle, and –1 on the lower left triangle

// output
//  0 1
// -1 0

#include <stdio.h>
void readFunc(int mat[5][5], int r);
void display(int mat[5][5], int r);
int main()
{
    int mat[5][5];
    int r;
    printf("Enter number of rows/columns: ");
    scanf("%d", &r);
    readFunc(mat, r);
    display(mat, r);
    return 0;
}
void readFunc(int mat[5][5], int r)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if (i == j)
            {
                mat[i][j] = 0;
            }
            else if (i > j)
            {
                mat[i][j] = -1;
            }
            else
            {
                mat[i][j] = 1;
            }
        }
    }
}

void display(int mat[5][5], int r)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            printf("\t %d", mat[i][j]);
        }
        printf("\n");
    }
}
