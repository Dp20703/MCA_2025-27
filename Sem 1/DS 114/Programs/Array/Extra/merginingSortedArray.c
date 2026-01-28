// Merging of two sorted arrays
// 12. Write a program to merge two sorted arrays [Page no:84]

#include <stdio.h>
#include <conio.h>

int main()
{
    int arr1[10], arr2[10], arr3[20];
    int i, index = 0, n1, n2, m;
    int first = 0, sec = 0;
    // Input n1:
    printf("\n Enter total elements in array1:");
    scanf("%d", &n1);
    printf("\n Enter value of array1:\n");
    for (i = 0; i < n1; i++)
    {
        printf("\n arr1[%d]:", i);
        scanf("%d", &arr1[i]);
    }

    printf("\n Enter elements in array2:");
    scanf("%d", &n2);
    printf("\n Enter value of array2:\n");
    for (i = 0; i < n2; i++)
    {
        printf("\n arr2[%d]:", i);
        scanf("%d", &arr2[i]);
    }
    m = n1 + n2;

    // merging array:
    while (first < n1 && sec < n2)
    {
        if (arr1[first] < arr2[sec])
        {
            arr3[index] = arr1[first];
            first++;
        }
        else
        {
            arr3[index] = arr2[sec];
            sec++;
        }
        index++;
    }
    // // if the array1 is over and array2 have elements:
    // if (first == n1)
    // {
    //     while (sec < n2)
    //     {
    //         arr3[index] = arr2[sec];
    //         sec++;
    //         index++;
    //     }
    // }
    // // if the array2 is over and array1 have elements:
    // if (sec == n2)
    // {
    //     while (first < n1)
    //     {
    //         arr3[index] = arr1[first];
    //         first++;
    //         index++;
    //     }
    // }

    // or sortend way [merge remining elements]
    while (first < n1)
    {
        arr3[index++] = arr1[first++];
    }
    while (sec < n2)
    {
        arr3[index++] = arr2[sec++];
    }

    // printing merged array:
    printf("\n Printing merged array:\n");
    for (i = 0; i < m; i++)
    {
        printf("\n arr3[%d]= %d ", i, arr3[i]);
    }
    printf("\n Press enter to exit....\n");
    getch();
    return 0;
}