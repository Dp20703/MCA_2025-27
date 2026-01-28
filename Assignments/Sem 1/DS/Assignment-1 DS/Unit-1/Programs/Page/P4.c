// 4. Write a program that calculates the sum of squares of the elements.

#include <stdio.h>

int main()
{
    int arr[100], n;
    long long sum = 0; 

    printf("Enter number of elements (up to 100): ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        sum += (long long)arr[i] * arr[i]; // square and add
    }

    printf("\nSum of squares of elements = %lld\n", sum);

    return 0;
}

// output

// Enter number of elements (up to 100): 5
// Enter 5 elements:
// arr[0] = 1
// arr[1] = 2
// arr[2] = 3
// arr[3] = 4
// arr[4] = 5

// Sum of squares of elements = 55