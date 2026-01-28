// 2. Write a program that reads an array of 100
// integers. Display all the pairs of elements whose
// sum is 50.
#include <stdio.h>

int main()
{
    int arr[100];
    int n;

    printf("Enter number of elements (up to 100): ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    int found = 0;
    printf("\nPairs of elements whose sum is 50:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == 50)
            {
                printf("%d + %d = 50\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }

    if (!found)
    {
        printf("No pair found...\n");
    }

    return 0;
}
// output
// Enter number of elements (up to 100): 10
// Enter 10 elements:
// arr[0] = 10
// arr[1] = 20
// arr[2] = 30
// arr[3] = 40
// arr[4] = 10
// arr[5] = 2
// arr[6] = 48
// arr[7] = 45
// arr[8] = 10
// arr[9] = 5

// Pairs of elements whose sum is 50:
// 10 + 40 = 50
// 20 + 30 = 50
// 40 + 10 = 50
// 40 + 10 = 50
// 2 + 48 = 50
// 45 + 5 = 50