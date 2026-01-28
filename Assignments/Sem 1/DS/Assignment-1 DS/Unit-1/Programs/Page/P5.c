// 5. Write a program to compute the sum and mean of the elements of a two-dimensional array.

#include <stdio.h>

int main()
{
    int rows, cols;
    int arr[50][50];
    long long sum = 0;
    float mean;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    printf("Enter %d elements:\n", rows * cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
            sum += arr[i][j];
        }
    }

    mean = (float)sum / (rows * cols);

    printf("\nSum of all elements = %lld\n", sum);
    printf("Mean of all elements = %.2f\n", mean);

    return 0;
}

// output
// Enter number of rows: 2
// Enter number of columns: 3
// Enter 6 elements:
// arr[0][0] = 23
// arr[0][1] = 32
// arr[0][2] = 52
// arr[1][0] = 32
// arr[1][1] = 12
// arr[1][2] = 20

// Sum of all elements = 171
// Mean of all elements = 28.50