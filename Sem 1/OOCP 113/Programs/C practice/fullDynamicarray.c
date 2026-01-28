#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int n, newsize, i;

    printf("Enter number of elements you want to store: ");
    scanf("%d", &n);

    // allocate memory
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Index %d: ", i);
        scanf("%d", &arr[i]); // ❌ Removed extra space in format string
    }

    // print original array
    printf("Original array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // new size
    printf("Enter new size: ");
    scanf("%d", &newsize);

    // ❌ Incorrect: sizeof(newsize) gives only size of int (usually 4 bytes)
    // ✅ Correct: allocate space for `newsize` integers
    arr = (int *)realloc(arr, newsize * sizeof(int));
    if (arr == NULL)
    {
        printf("Reallocation failed!\n");
        return 1;
    }

    // Accept new elements only if size increased
    if (newsize > n)
    {
        printf("Enter %d new elements:\n", newsize - n);
        for (i = n; i < newsize; i++)
        {
            printf("Index %d: ", i);
            scanf("%d", &arr[i]);
        }
    }

    // print updated array
    printf("Updated array:\n");
    for (i = 0; i < newsize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // free memory
    free(arr);

    return 0;
}
