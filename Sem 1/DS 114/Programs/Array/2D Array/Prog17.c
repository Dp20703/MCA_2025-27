// 17. Write a program to generate Pascal’s triangle.

#include <stdio.h>
int main()
{
    int arr[7][7] = {0}, i, j;
    arr[0][0] = arr[1][0] = arr[1][1] = 1;
    int row = 2, col;
    while (row < 7)
    {
        arr[row][0] = 1;
        for (col = 1; col <= row; col++)
        {
            arr[row][col] = arr[row - 1][col - 1] + arr[row - 1][col];
        }
        row++;
    }
    // printing
    for (i = 0; i < 7; i++)
    {
        // Print spaces before row
        for (j = 0; j < 7 - i - 1; j++)
        {
            printf("   "); // <-- This is the secret!
        }
        for (j = 0; j <= i; j++)
        {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}