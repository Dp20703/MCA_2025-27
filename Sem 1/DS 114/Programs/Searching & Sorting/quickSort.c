#include <stdio.h>


// find the pivot
int partition(int arr[], int beg, int end)
{
    int pivot = arr[beg];
    int left = beg + 1;
    int right = end;
    int temp;

    while (left <= right)
    {
        while (left <= right && arr[left] <= pivot)
            left++;

        while (arr[right] > pivot)
            right--;

        if (left < right)
        {
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }

    // Place pivot in correct position
    temp = arr[beg];
    arr[beg] = arr[right];
    arr[right] = temp;

    return right;
}

// quick sort function
void quickSort(int arr[], int beg, int end)
{
    int pivot;
    if (beg < end)
    {
        pivot = partition(arr, beg, end);
        quickSort(arr, beg, pivot - 1); // left half
        quickSort(arr, pivot + 1, end); // right half
    }
}

int main()
{
    int n;
    printf("\n Enter the number of elements in array (<= 100): ");
    scanf("%d", &n);

    int arr[n];
    printf("\n Enter the elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("\n Sorted Array elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }

    return 0;
}
