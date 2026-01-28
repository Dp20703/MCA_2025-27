// 14. Write a program to interchange the largest and the smallest number in an array.
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

// Function to find the smallest element position
int smallestElementPos(int arr[], int n)
{
    int smallest = arr[0], pos = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
            pos = i;
        }
    }
    return pos;
}

// Function to find the largest element position
int largestElementPos(int arr[], int n)
{
    int largest = arr[0], pos = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
            pos = i;
        }
    }
    return pos;
}

// Function to interchange smallest and largest element
void interChange(int arr[], int n)
{
    int bigPos = largestElementPos(arr, n);
    int smallPos = smallestElementPos(arr, n);

    printf("\nSwapping largest element %d (at index %d) with smallest element %d (at index %d)\n",
           arr[bigPos], bigPos, arr[smallPos], smallPos);

    int temp = arr[bigPos];
    arr[bigPos] = arr[smallPos];
    arr[smallPos] = temp;
}

int main()
{
    int arr[10], n;

    printf("Enter the size of the array (max 10): ");
    scanf("%d", &n);

    readArray(arr, n);

    printf("\nBefore interchange:");
    printArray(arr, n);

    interChange(arr, n);

    printf("\nAfter interchange:");
    printArray(arr, n);

    return 0;
}
