// 12. Write a program to calculate exp(x, y) using recursive functions.
#include <stdio.h>
int exp(int, int);
int main()
{
    int num1, num2, res;
    printf("\n Enter the two numbers: ");
    scanf("%d %d", &num1, &num2);
    res = exp(num1, num2);
    printf("\n RESULT = %d", res);
    return 0;
}
int exp(int x, int y)
{
    if (y == 0)
        return 1;
    else
        return x * exp(x, y - 1);
}
// Output
// Enter the two numbers : 3 4
// RESULT = 81