// 22. Write a program to illustrate the use of a pointer that points to a 2D array.

#include <stdio.h>

int main()
{
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int (*ptr)[3]; // pointer to an array of 3 integers
    ptr = arr;     // points to the first row of arr

    printf("Matrix elements using pointer:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // *(ptr + i) → row i
            // *(*(ptr + i) + j) → element at row i, col j
            printf("%d ", *(*(ptr + i) + j));
        }
        printf("\n");
    }

    return 0;
}


// output
// Matrix elements using pointer:
// 1 2 3 
// 4 5 6
// 7 8 9