// 24. Write a program to delete all the duplicate entries from an array of n integers.

#include <stdio.h>

int main()
{
    int arr[100], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Remove duplicates
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                // shift elements left
                for (int k = j; k < n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                n--; // reduce size
                j--; // check again at same position
            }
        }
    }

    printf("\nArray after deleting duplicates:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

// output
// Enter number of elements: 5
// Enter 5 elements:
// 1
// 2
// 3
// 3
// 2

// Array after deleting duplicates:
// 1 2 3
