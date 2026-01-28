// 13. Write a program to print the Fibonacci series using recursion.

#include <stdio.h>
int Fib(int);
int main()
{
    int num, res;
    printf("\n Enter the number of terms: ");
    scanf("%d", &num);
    printf("Fibonacci series\n");
    for (int i = 0; i < num; i++)
    {
        res = Fib(i);
        printf("%d ", res);
    }

    return 0;
}
int Fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return (Fib(n - 1) + Fib(n - 2));
}

// output
// Enter the number of terms: 5
// Fibonacci series
// 0 1 1 2 3