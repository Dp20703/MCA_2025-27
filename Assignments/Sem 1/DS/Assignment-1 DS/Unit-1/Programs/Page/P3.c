// 3. Write a program to interchange the second element with the second last element.

#include <stdio.h>

int main()
{
    int arr[100], n, temp;

    printf("Enter number of elements (up to 100): ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nBefore interchange:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Swap 2nd (index 1) with 2nd last (index n-2)
    if (n >= 2)
    {
        temp = arr[1];
        arr[1] = arr[n - 2];
        arr[n - 2] = temp;
    }

    printf("\n\nAfter interchange:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
// output
// Enter number of elements (up to 100): 5
// Enter 5 elements:
// arr[0] = 1
// arr[1] = 2
// arr[2] = 3
// arr[3] = 4
// arr[4] = 5

// Before interchange:
// 1 2 3 4 5

// After interchange:
// 1 4 3 2 5