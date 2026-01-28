// 13. Write a program to read an array of n numbers and then find the smallest number.

#include <stdio.h>

// Function to read array elements
void readArray(int arr[], int n)
{
    printf("\nEnter %d array elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
}

// Function to print array elements
void printArray(int arr[], int n)
{
    printf("\nArray elements are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

// Function to find the smallest element
int smallestElement(int arr[], int n)
{
    int smallest = arr[0];
    for (int i = 1; i < n; i++)
    { // Start from 1
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    return smallest;
}

int main()
{
    int arr[10], n;

    printf("Enter the size of the array (max 10): ");
    scanf("%d", &n);

    readArray(arr, n);
    printArray(arr, n);

    printf("\nSmallest element in the array is: %d\n", smallestElement(arr, n));

    return 0;
}
