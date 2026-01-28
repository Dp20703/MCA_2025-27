#include <stdio.h>

int main()
{
    int arr[] = {11, 22, 25, 32, 56, 83, 100};
    // int length = sizeof(arr) / sizeof(arr[0]);
    int num = 100;
    int beg = 0;
    int end = 6;
    int mid;

    while (beg <= end)
    {
        mid = (beg + end) / 2;

        if (arr[mid] == num)
        {
            printf("Got the element %d at %dth position", num, mid + 1);
            break;
        }
        else if (arr[mid] > num)
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
    }

    // If the loop ends and the number wasn’t found
    printf("Element %d not found!", num);

    return 0;
}
