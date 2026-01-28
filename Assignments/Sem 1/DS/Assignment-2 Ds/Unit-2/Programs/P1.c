// 1.Covert infix to postfix

// 🔹 Infix vs Postfix

// Infix: Operators between operands
// 👉 Example: A + B * C

// Postfix: Operators after operands
// 👉 Example: A B C * +

#include <stdio.h>
#include <ctype.h> // for isalnum
#include <string.h>

#define MAX 100
char stack[MAX];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; i < strlen(infix); i++)
    {
        char c = infix[i];

        if (isalnum(c))
        {
            // Operand → add to postfix
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            // Pop until '('
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }
        else
        {
            // Operator
            while (top != -1 && precedence(stack[top]) >= precedence(c))
            {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    // Pop remaining operators
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // Null terminate string
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
// output
// Enter infix expression: A+B*C
// Postfix Expression: ABC*+