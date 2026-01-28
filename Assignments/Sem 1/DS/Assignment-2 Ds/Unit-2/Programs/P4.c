// 4. Write a program to check whether a number is palindrome or not using stack

#include <stdio.h>
#include <string.h>
#define max 10
char stack[max];
int top = -1;
void push(char c)
{
    if (top == max - 1)
    {
        printf("\n Stack overflow...");
    }
    else
    {
        stack[++top] = c;
    }
};
char pop()
{
    if (top == -1)
    {
        printf("\n Stack Underflow...");
        return '\0';
    }
    else
    {
        return stack[top--];
    }
};
int main()
{
    char num[max], rev[max];
    printf("\n Enter the number: ");
    scanf("%s", num);
    int n = strlen(num);
    for (int i = 0; i < n; i++)
    {
        push(num[i]);
    }
    for (int i = 0; i < n; i++)
    {
        rev[i] = pop();
    }
    rev[n] = '\0';

    if (strcmp(num, rev) == 0)
        printf("%s is a palindrome.\n", num);
    else
        printf("%s is not a palindrome.\n", num);

    return 0;
}

// output
// Enter the number: 12321
// 12321 is a palindrome.

// Enter the number: 12345
// 12345 is not a palindrome.
