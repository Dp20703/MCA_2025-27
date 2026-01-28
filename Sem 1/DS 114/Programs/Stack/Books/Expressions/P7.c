// 7. Write a program to evaluate a postfix expression
#include <stdio.h>
#include <ctype.h>

#define MAX 100
float st[MAX];
int top = -1;
float postfixEvaluation(char exp[]);
float pop(float st[]);
void push(float st[], float val);
int main()
{
    char exp[100];
    float val;
    printf("\n Enter postfix expression: ");
    gets(exp);
    // fgets(exp,sizeof(exp),stdin);
    val = postfixEvaluation(exp);
    printf("\n ans: %.2f", val);
    return 0;
}
float postfixEvaluation(char exp[])
{
    int i = 0;
    float op1, op2, value;
    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
        {
            push(st, (float)(exp[i] - '0'));
        }
        else
        {
            op2 = pop(st);
            op1 = pop(st);
            switch (exp[i])
            {
            case '+':
                value = op1 + op2;
                break;
            case '-':
                value = op1 - op2;
                break;
            case '*':
                value = op1 * op2;
                break;
            case '/':
                value = op1 / op2;
                break;
            case '%':
                value = (int)op1 % (int)op2;
                break;
            }
            push(st, value);
        }
        i++;
    }
    return (pop(st));
}

float pop(float st[])
{
    float val;
    if (top == -1)
    {
        printf("\n Stack underflow...");
        return -1;
    }
    else
    {
        val = st[top--];
    }
    return val;
}

void push(float st[], float val)
{
    if (top == MAX - 1)
    {
        printf("\n Stack overflow..");
    }
    else
    {
        st[++top] = val;
    }
}

// output:
// Enter postfix expression: 934*8+4/-
//  ans: 4.00