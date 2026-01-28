#include <stdio.h>

void insertionSort(int arr[], int n)
{
    int temp, j;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i]; // pick the element
        j = i - 1;

        while (j >= 0 && temp < arr[j]) // shift elements right
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp; // place element at correct position
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

    insertionSort(arr, n);

    printf("\n Sorted Array elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }

    return 0;
}
