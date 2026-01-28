// 13. Write a program using pointers to interchange the second biggest and the second smallest number in
// the array.

#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    // Input elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Sort array (simple bubble sort)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Find second smallest and second largest positions
    int *secondSmall = &arr[1];     // second smallest
    int *secondLarge = &arr[n - 2]; // second largest

    // Swap using pointers
    swap(secondSmall, secondLarge);

    // Print final array
    printf("\nArray after interchanging second smallest and second largest:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// output
// Enter size of array: 5
// Enter 5 elements:
// 1
// 2
// 3
// 4
// 5

// Array after interchanging second smallest and second largest:
// 1 4 3 2 5