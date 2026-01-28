#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char);
char pop();
int main()
{
    char exp[MAX], temp;
    int flag = 1;
    printf("\n Enter an expression:..");
    gets(exp);

    //
    for (int i = 0; i < strlen(exp); i++)
    {

        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }

        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (top == -1)
            {
                flag = 0;
            }
            else
            {
                temp = pop();
                if (exp[i] == ')' && (temp == '{' || temp == '['))
                {
                    flag = 0;
                }
                if (exp[i] == '}' && (temp == '(' || temp == '['))
                {
                    flag = 0;
                }
                if (exp[i] == ']' && (temp == '{' || temp == '('))
                {
                    flag = 0;
                }
            }
        }
    }

    if (top >= 0)
    {
        flag = 0;
    }

    if (flag == 1)
        printf("\n Valid expression..");
    else
    {
        printf("\n Invalid expression...");
    }

    return 0;
}

// push
void push(char c)
{
    if (top == MAX - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        stack[++top] = c;
    }
}

// pop
char pop()
{
    if (top == -1)
    {
        return '\0'; // safe return
    }
    return stack[top--];
}
