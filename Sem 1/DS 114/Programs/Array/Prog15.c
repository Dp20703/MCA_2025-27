// 15. Write a program to display an array of given numbers.

#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int *ptr1, *ptr2;

    ptr1 = arr;     // arr → address of first element → &arr[0]
    ptr2 = &arr[7]; // address of last element

    while (ptr1 <= ptr2) // loop until ptr1 crosses ptr2
    {
        printf(" %d ", *ptr1); // print value at ptr1
        ptr1++;                // move pointer to next element
    }

    return 0;
}
