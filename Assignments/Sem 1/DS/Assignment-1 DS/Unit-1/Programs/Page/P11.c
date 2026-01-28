// 11. Write a program to input the elements of a two-dimensional array. Then from this array, make two
// arrays—one that stores all odd elements of the two-dimensional array and the other that stores
// all even elements of the array.

#include <stdio.h>

int main()
{
    int rows, cols;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int arr[rows][cols];

    // Input elements
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int even[rows * cols], odd[rows * cols]; // max possible size
    int eCount = 0, oCount = 0;

    // Separate odd and even
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] % 2 == 0)
                even[eCount++] = arr[i][j];
            else
                odd[oCount++] = arr[i][j];
        }
    }

    // Print even elements
    printf("\nEven elements: ");
    for (int i = 0; i < eCount; i++)
    {
        printf("%d ", even[i]);
    }

    // Print odd elements
    printf("\nOdd elements: ");
    for (int i = 0; i < oCount; i++)
    {
        printf("%d ", odd[i]);
    }

    printf("\n");

    return 0;
}

// output
// Enter number of rows and columns: 3
// 3
// Enter elements of the matrix:
// 10
// 20
// 30
// 2
// 85
// 6
// 3
// 4
// 8

// Even elements: 10 20 30 2 6 4 8
// Odd elements: 85 3