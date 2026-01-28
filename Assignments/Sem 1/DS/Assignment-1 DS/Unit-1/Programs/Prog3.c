// 3. Write a program to perform insertion and deletion in the array at start of array, end of array and middle of array.

#include <stdio.h>

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int insertAt(int arr[], int size, int capacity, int element, int pos)
{
    if (size >= capacity)
    {
        printf("Array is full, cannot insert.\n");
        return size;
    }
    if (pos < 0 || pos > size)
    {
        printf("Invalid position.\n");
        return size;
    }
    // Shift elements right
    for (int i = size - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = element;
    return size + 1;
}

int deleteAt(int arr[], int size, int pos)
{
    if (size <= 0)
    {
        printf("Array is empty, cannot delete.\n");
        return size;
    }
    if (pos < 0 || pos >= size)
    {
        printf("Invalid position.\n");
        return size;
    }
    // Shift elements left
    for (int i = pos; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}

int main()
{
    int capacity = 100; // max size of array
    int arr[100] = {10, 20, 30, 40, 50};
    int size = 5;

    printf("Original array: ");
    printArray(arr, size);

    // Insert at start
    size = insertAt(arr, size, capacity, 5, 0);
    printf("After inserting 5 at start: ");
    printArray(arr, size);

    // Insert at middle
    int mid = size / 2;
    size = insertAt(arr, size, capacity, 25, mid);
    printf("After inserting 25 at middle: ");
    printArray(arr, size);

    // Insert at end
    size = insertAt(arr, size, capacity, 60, size);
    printf("After inserting 60 at end: ");
    printArray(arr, size);

    // Delete at start
    size = deleteAt(arr, size, 0);
    printf("After deleting at start: ");
    printArray(arr, size);

    // Delete at middle
    mid = size / 2;
    size = deleteAt(arr, size, mid);
    printf("After deleting at middle: ");
    printArray(arr, size);

    // Delete at end
    size = deleteAt(arr, size, size - 1);
    printf("After deleting at end: ");
    printArray(arr, size);

    return 0;
}
// output
// Original array: 10 20 30 40 50
// After inserting 5 at start: 5 10 20 30 40 50
// After inserting 25 at middle: 5 10 20 25 30 40 50
// After inserting 60 at end: 5 10 20 25 30 40 50 60
// After deleting at start: 10 20 25 30 40 50 60
// After deleting at middle: 10 20 25 40 50 60
// After deleting at end: 10 20 25 40 50