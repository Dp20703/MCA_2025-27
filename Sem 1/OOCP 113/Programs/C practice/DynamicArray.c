#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory not allocated!\n");
        return 1;
    }

    // Input values into the array
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Print the values
    printf("You entered:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    // Input extra elements
    int newsize;
    printf("\nEnter new size: ");
    scanf("%d", &newsize);

    int *temp = (int *)realloc(arr, newsize * sizeof(int));
    if (temp == NULL)
    {
        printf("Reallocation failed!\n");
        free(arr);
        return 1;
    }
    arr = temp;

    // Input new values
    printf("Enter %d more integers:\n", newsize - n);
    for (i = n; i < newsize; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Print all values
    printf("Final array:\n");
    for (i = 0; i < newsize; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
