#include <stdio.h>

// merge the two sub sorted arrays:
void merge(int arr[], int beg, int mid, int end)
{
    int i = beg, j = mid + 1, index = beg;
    int temp[100]; // make sure n <= 100

    // merge two sorted parts into temp
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[index++] = arr[i++];
        }
        else
        {
            temp[index++] = arr[j++];
        }
    }

    // copy remaining elements from left part (if any)
    while (i <= mid)
    {
        temp[index++] = arr[i++];
    }

    // copy remaining elements from right part (if any)
    while (j <= end)
    {
        temp[index++] = arr[j++];
    }

    // copy temp array back to original array
    for (int k = beg; k < index; k++)
    {
        arr[k] = temp[k];
    }
}

// main merge sort function
void mergeSort(int arr[], int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergeSort(arr, beg, mid);     // left half
        mergeSort(arr, mid + 1, end); // right half
        merge(arr, beg, mid, end);    // merge them
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

    mergeSort(arr, 0, n - 1);

    printf("\n Sorted Array elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }

    return 0;
}
