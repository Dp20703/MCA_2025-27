// 4. Write a program to reverse a list of given numbers.

#include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int val)
{
    if (top == MAX - 1)
    {
        printf("\nStack Overflow!");
    }
    else
    {
        stack[++top] = val;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow!");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int main()
{
    int arr[MAX], n, i;

    printf("\nEnter number of elements (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX)
    {
        printf("Error: number exceeds maximum size %d\n", MAX);
        return 0;
    }

    printf("\nEnter %d values: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Push all elements into stack
    for (i = 0; i < n; i++)
    {
        push(arr[i]);
    }

    // Pop all elements back into array (reverses order)
    for (i = 0; i < n; i++)
    {
        arr[i] = pop();
    }

    printf("\nReversed list: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

// output
// Enter number of elements(max 10) : 10

// Enter 10 values : 20 1 2 3 4 5 132 2 22 23

// Reversed list : 23 22 2 132 5 4 3 2 1 20