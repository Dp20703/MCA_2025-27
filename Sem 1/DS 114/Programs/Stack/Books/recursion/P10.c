// 10. Write a program to calculate the factorial of a given number.

#include <stdio.h>
int Fact(int);
int main()
{
    int num, fact;
    printf("\n Enter the num: ");
    scanf("%d", &num);
    fact = Fact(num);
    printf("\n Fact of %d is %d ", num, fact);
    return 0;
}
int Fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return (n * Fact(n - 1));
    }
}

// output
//  Enter the num: 6
//  Fact of 6 is 720