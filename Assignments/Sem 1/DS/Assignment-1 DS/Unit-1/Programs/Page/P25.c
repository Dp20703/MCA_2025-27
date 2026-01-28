// 25. Write a program to read a floating pofloat array. Update the array to insert a new number at the specified location.

#include <stdio.h>

int main()
{
    float arr[100];
    int n, pos;
    float num;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d floating point numbers:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }

    printf("\nEnter new number to insert: ");
    scanf("%f", &num);

    printf("Enter position (0 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n)
    {
        printf("Invalid position!\n");
        return 1;
    }

    // Shift elements to the right
    for (int i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = num; // insert new number
    n++;            // increase size

    printf("\nArray after insertion:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i]);
    }

    return 0;
}

// output

// Enter number of elements: 3
// Enter 3 floating point numbers:
// 1.2
// 3.2
// 6.3

// Enter new number to insert: 66.99
// Enter position (0 to 3): 2

// Array after insertion:
// 1.20 3.20 66.99 6.30