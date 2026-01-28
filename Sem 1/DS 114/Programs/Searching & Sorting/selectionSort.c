#include <stdio.h>

int smallestElement(int arr[], int k, int n)
{
    int pos = k;
    int smallest = arr[k];
    for (int i = k + 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
            pos = i;
        }
    }
    return pos;
}

void selectionSort(int arr[], int n)
{
    int temp, pos;
    for (int i = 0; i < n - 1; i++)
    {
        pos = smallestElement(arr, i, n);
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
}

int main()
{
    int n;
    printf("\n Enter the number of elements in array: ");
    scanf("%d", &n);

    int arr[n];
    printf("\n Enter the elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    printf("\n Sorted Array elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }

    return 0;
}
