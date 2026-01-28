// 5. Write a program to implement paranthesis checker

#include <stdio.h>
#include <string.h>
#define MAX 10
int stack[MAX];
int top = -1;
void push(char);
char pop();
int main()
{
    char exp[MAX];
    int flag = 1, temp;
    printf("\n Enter expression: ");
    // gets(exp);
    fgets(exp, MAX, stdin);
    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(exp[i]);
        }
        if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {

            temp = pop();
            if (top == -1)
            {
                flag = 0;
            }
            else
            {
                if (exp[i] == ')' && (temp == '{' || temp == '['))
                {
                    flag = 0;
                }
                if (exp[i] == ']' && (temp == '{' || temp == '('))
                {
                    flag = 0;
                }
                if (exp[i] == '}' && (temp == '[' || temp == '('))
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
        printf("\n Valid expression");
    else
        printf("\n Invalid expression");

    return 0;
}

void push(char c)
{
    if (top == MAX - 1)
    {
        printf("\nStack overflow...");
    }
    else
    {
        stack[++top] = c;
    }
}
char pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow...");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

// output:

// Enter expression: (A+B)*(C-D)
// Valid expression

// Enter expression: [A*(B+C)
// Invalid expression

// Enter expression: {A+[B*(C-D)]))
// Invalid expression
