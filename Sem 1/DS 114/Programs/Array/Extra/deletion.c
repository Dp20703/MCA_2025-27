// 9. Write a program to delete a number from a given location in an array [Page no:81]

#include <stdio.h>
#include <conio.h>
// int main()
// {
//     int i, n, pos, arr[10];
//     printf("\n Enter the number of elements in the array : ");
//     scanf("%d", &n);
//     for (i = 0; i < n; i++)
//     {
//         printf("\n arr[%d] = ", i);
//         scanf("%d", &arr[i]);
//     }
//     printf("\nEnter the position from which the number has to be deleted : ");
//     scanf("%d", &pos);

//     // Delete element by position:
//     for (i = pos; i < n - 1; i++)
//     {
//         arr[i] = arr[i + 1];
//     }
//     n--;

//     printf("\n The array after deletion is : ");
//     for (i = 0; i < n; i++)
//     {
//         printf("\n arr[%d] = %d", i, arr[i]);
//     }
//     printf("\n Press enter to exit....");
//     getch();
//     return 0;
// }

// 10. Write a program to delete a number from an array that is already sorted in ascending order

int main()
{
    int i, n, j, num, arr[10];
    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\n arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the number to be deleted : ");
    scanf("%d", &num);

    // delete by num:
    for (i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            for (j = i; j < n - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
        }
    }
    n--;

    printf("\n The array after deletion is : ");
    for (i = 0; i < n; i++)
    {
        printf("\n arr[%d] = %d", i, arr[i]);
    }
    printf("\n Press enter to exit....");
    getch();
    return 0;
}
