// Merging of two unsorted arrays [Page no:82]
// 11. Write a program to merge two unsorted arrays.
#include <stdio.h>
#include <conio.h>

int main()
{
    int arr1[10], arr2[10], arr3[20];
    int n1, n2, m, i, index = 0;
    printf("\n Enter the total elements in the array 1:");
    scanf("%d", &n1);

    printf("\n Enter value for array1:\n");
    for (int i = 0; i < n1; i++)
    {
        printf("\n arr1[%d]:", i);
        scanf("%d", &arr1[i]);
    }
    printf("\n Enter the total elements in the array 2:");
    scanf("%d", &n2);
    printf("\n Enter value for array2:\n");
    for (int i = 0; i < n2; i++)
    {
        printf("\n arr2[%d]:", i);
        scanf("%d", &arr2[i]);
    }
    m = n1 + n2;

    for (i = 0; i < n1; i++)
    {
        arr3[index] = arr1[i];
        index++;
    }
    for (i = 0; i < n2; i++)
    {
        arr3[index] = arr2[i];
        index++;
    }
    printf("\n After Merging array:\n");
    for (i = 0; i < m; i++)
    {
        printf("\n arr3[%d]: %d", i, arr3[i]);
    }
    getch();
    return 0;
}
