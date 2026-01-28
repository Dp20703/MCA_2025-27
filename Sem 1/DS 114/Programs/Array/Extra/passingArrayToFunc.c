#include <stdio.h>
#include <conio.h>

void func(int num)
{
    printf("\n %d", num);
}

void func1(int *num)
{
    printf("\n %d", *num);
}

void displayArray(int arr[5])
{
    int i;
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        printf(" %d ", arr[i]);
    }
}
int main()
{
    int arr[5] = {11, 22, 3, 4, 5};
    // passing data value
    func(arr[3]);

    // passing address
    func1(&arr[3]);

    // passing entire array
    displayArray(arr);
    return 0;
}
