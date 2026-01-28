#include <stdio.h>
#include <ctype.h>
#define MAX 100

float st[MAX];
int top = -1;

void push(float[], float);
float pop(float[]);
float evalPostfix(char[]);

int main()
{
    char exp[MAX];
    float val;

    printf("\nEnter postfix expression (no spaces, single digits): ");
    scanf("%s", exp);

    val = evalPostfix(exp);
    printf("\nThe value of expression: %.2f", val);

    return 0;
}

void push(float st[], float val)
{
    if (top == MAX - 1)
        printf("\nStack overflow...");
    else
        st[++top] = val;
}

float pop(float st[])
{
    if (top == -1)
    {
        printf("\nStack underflow...");
        return -1;
    }
    return st[top--];
}

float evalPostfix(char exp[])
{
    int i = 0;
    float op1, op2, val;

    top = -1; // ✅ reset stack

    while (exp[i] != '\0')
    {
        if (isdigit((unsigned char)exp[i]))
        {
            push(st, (float)(exp[i] - '0'));
        }
        else if (exp[i] == '+' || exp[i] == '-' ||
                 exp[i] == '*' || exp[i] == '/' || exp[i] == '%')
        {
            op2 = pop(st);
            op1 = pop(st);

            switch (exp[i])
            {
            case '+':
                val = op1 + op2;
                break;
            case '-':
                val = op1 - op2;
                break;
            case '*':
                val = op1 * op2;
                break;
            case '/':
                val = op1 / op2;
                break;
            case '%':
                val = (int)op1 % (int)op2;
                break;
            }
            push(st, val);
        }
        i++;
    }
    return pop(st);
}
