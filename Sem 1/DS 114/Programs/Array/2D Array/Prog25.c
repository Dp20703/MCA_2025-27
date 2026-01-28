// 25. Write a program to read and display a 3 X 3 matrix. [ using pointer ]

#include <stdio.h>

void display(int (*)[3]);
int main()
{
    int mat[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Enter element %d %d ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    display(mat);

    return 0;
}

void display(int (*mat)[3])
{
    int i, j;
    printf("\n The elements of the matrix are");
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
            printf("\t %d", *(*(mat + i) + j));
    }
}