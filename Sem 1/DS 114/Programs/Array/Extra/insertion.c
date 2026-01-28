#include <stdio.h>

int main()
{
    int arr[10] = {10, 20, 30, 40, 50}; // initial array
    int n = 5;                          // current size
    int pos, value;

    printf("Enter position (1 to %d): ", n + 1);
    scanf("%d", &pos);

    printf("Enter value to insert: ");
    scanf("%d", &value);

    // shift elements to the right
    for (int i = n; i >= pos; i--)
    {
        // arr[i] = arr[i - 1];
        arr[i + 1] = arr[i];
    }

    arr[pos - 1] = value; // insert value
    n++;                  // size increased

    printf("Array after insertion: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
