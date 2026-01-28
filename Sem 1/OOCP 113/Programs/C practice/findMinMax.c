#include <stdio.h>

void findMinMax(int arr[], int n, int *min, int *max)
{
    int *ptr = arr;
    *min = *max = *ptr;

    for (int i = 1; i < n; i++)
    {
        ptr++;
        if (*ptr < *min)
            *min = *ptr;
        if (*ptr > *max)
            *max = *ptr;
    }
}

int main()
{
    int arr[100], n;
    int min, max;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    findMinMax(arr, n, &min, &max);

    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    return 0;
}
