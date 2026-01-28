// 2.Postfix evaluation

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
int stack[MAX];
int top = -1;

void push(int val)
{
    stack[++top] = val;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[200];
    printf("Enter postfix expression (use spaces between numbers/operators):\n");
    fgets(exp, sizeof(exp), stdin); // read full line

    char *token = strtok(exp, " "); // split by spaces

    while (token != NULL)
    {
        // if the token is a number
        if (isdigit(token[0]))
        {
            push(atoi(token)); // convert string to int
        }
        else
        {
            int b = pop();
            int a = pop();
            switch (token[0])
            {
            case '+':
                push(a + b);
                break;
            case '-':
                push(a - b);
                break;
            case '*':
                push(a * b);
                break;
            case '/':
                push(a / b);
                break;
            default:
                printf("Invalid operator: %s\n", token);
                return 1;
            }
        }
        token = strtok(NULL, " "); // next part
    }

    printf("The result is: %d\n", pop());
    return 0;
}
// output
// Enter postfix expression (use spaces between numbers/operators):
// 5 6 2 + * 12 4 / -
// The result is: 37
