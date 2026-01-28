// 6. Write a program to convert an infix expression into its equivalent postfix notation.

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

char st[MAX];
int top = -1;

void push(char st[], char);
char pop(char st[]);
void InfixtoPostfix(char in[], char post[]);
int getPriority(char);

int main()
{
    char infix[100], postfix[100];
    printf("\nEnter any infix expression: ");
    gets(infix); // better to use fgets, but keeping gets for your format
    InfixtoPostfix(infix, postfix);
    printf("\nThe corresponding postfix expression is: ");
    puts(postfix);
    return 0;
}

// infix to postfix conversion
void InfixtoPostfix(char in[], char post[])
{
    int i = 0, j = 0;
    char temp;

    while (in[i] != '\0')
    {
        if (in[i] == '(')
        {
            push(st, in[i]);
            i++;
        }
        else if (in[i] == ')')
        {
            // Until stack empty or '(' found
            while ((top != -1) && st[top] != '(')
            {
                post[j] = pop(st);
                j++;
            }
            if (top == -1)
            {
                printf("\nInvalid Expression.....");
                exit(1);
            }
            temp = pop(st); // remove '('
            i++;
        }
        else if (isdigit(in[i]) || isalpha(in[i]))
        {
            post[j] = in[i];
            j++;
            i++;
        }
        else if (in[i] == '%' || in[i] == '+' || in[i] == '/' || in[i] == '-' || in[i] == '*')
        {
            while ((top != -1) && (st[top] != '(') &&
                   (getPriority(st[top]) >= getPriority(in[i])))
            {
                post[j] = pop(st);
                j++;
            }
            push(st, in[i]);
            i++;
        }
        else
        {
            printf("\nIncorrect element in expression: %c", in[i]);
            exit(1);
        }
    }
    while ((top != -1) && (st[top] != '('))
    {
        post[j] = pop(st);
        j++;
    }
    post[j] = '\0';
}

// getPriority
int getPriority(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// pop
char pop(char st[])
{
    char val = ' ';
    if (top == -1)
    {
        printf("\nStack underflow..");
    }
    else
    {
        val = st[top];
        top--;
    }
    return val;
}

// push
void push(char st[], char val)
{
    if (top == MAX - 1)
    {
        printf("\nStack overflow........");
    }
    else
    {
        top++;
        st[top] = val;
    }
}
