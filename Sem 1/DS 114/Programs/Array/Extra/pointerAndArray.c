#include <stdio.h>
int main()
{

    // int arr[] = {25, 2, 3, 4, 5};
    // printf("\n Address of array = %p %p %p", arr, &arr[0], &arr);

    // int *ptr = &arr[0];
    // printf("\nPrint the Address of first element :%d", ptr);
    // ptr++;
    // printf("\nPrint the Address of second element :%d", ptr);
    // printf("\nPrint the value of second element :%d", *ptr);
    // printf("\n Array 3\n");
    // int newarray[4] = {10, 20, 30, 40};
    // printf("%p\n", newarray);  // address of first element (&newarray[0])
    // printf("%p\n", &newarray); // address of whole array (type: int (*)[4])

    // modifies array elements using pointer
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr, i;
    ptr = &arr[2];
    *ptr = 30;
    *(ptr - 1) = 20;
    *(ptr + 1) = 40;
    for (i = 0; i < 5; i++)
    {
        printf(" %d ", arr[i]);
    }
    // subtraction of two pointer variables
    int *p1, *p2;
    p1 = arr;
    p2 = arr + 2;
    printf("\n arr: %p", arr);
    printf("\n arr+2: %p \n", arr + 2);
    printf("Sub:%d", p1 - p2);

    return 0;
}
