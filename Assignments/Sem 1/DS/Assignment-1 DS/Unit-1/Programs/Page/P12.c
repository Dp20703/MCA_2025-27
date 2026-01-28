// 12. Write a program to read two floating point number
// arrays. Merge the two arrays and display the
// resultant array in reverse order.

#include <stdio.h>

int main()
{
    int n1, n2;

    // Input sizes
    printf("Enter size of first array: ");
    scanf("%d", &n1);

    printf("Enter size of second array: ");
    scanf("%d", &n2);

    float arr1[n1], arr2[n2], merged[n1 + n2];

    // Input first array
    printf("Enter elements of first array:\n");
    for (int i = 0; i < n1; i++)
    {
        scanf("%f", &arr1[i]);
        merged[i] = arr1[i]; // copy into merged
    }

    // Input second array
    printf("Enter elements of second array:\n");
    for (int i = 0; i < n2; i++)
    {
        scanf("%f", &arr2[i]);
        merged[n1 + i] = arr2[i]; // copy into merged
    }

    // Print merged array in reverse order
    printf("\nMerged array in reverse order:\n");
    for (int i = n1 + n2 - 1; i >= 0; i--)
    {
        printf("%.2f ", merged[i]);
    }

    printf("\n");

    return 0;
}

// output
// Enter size of first array: 3
// Enter size of second array: 2
// Enter elements of first array:
// 1.2
// 2.1
// 3.1
// Enter elements of second array:
// 5.6
// 9.6

// Merged array in reverse order:
// 9.60 5.60 3.10 2.10 1.20