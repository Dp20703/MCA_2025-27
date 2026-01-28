#include <stdio.h>
#include <string.h>

#define MAX 100

/* Global stack */
char stack[MAX];
int top = -1;

/* Function declarations */
void push(char c);
char pop();
int isMatching(char open, char close);
int isValidExpression(char exp[]);

/* main function */
int main()
{
    char exp[MAX];

    printf("Enter an expression: ");
    gets(exp);
    // or
    // fgets(exp, MAX, stdin);

    /* remove newline character */
    // exp[strcspn(exp, "\n")] = '\0';

    if (isValidExpression(exp))
        printf("\nValid expression");
    else
        printf("\nInvalid expression");

    return 0;
}

// Main logic of bracket validation
// isValidExpression
int isValidExpression(char exp[])
{
    char temp;
    top = -1;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        /* Opening brackets → push */
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }

        /* Closing brackets → pop & check */
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (top == -1) // no opening bracket
                return 0;

            temp = pop();

            if (!isMatching(temp, exp[i]))
                return 0;
        }
    }

    /* Stack must be empty at end */
    if (top != -1)
        return 0;

    return 1;
}

// isMatching -> Checks correct bracket pair

int isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return 1;
    if (open == '{' && close == '}')
        return 1;
    if (open == '[' && close == ']')
        return 1;

    return 0;
}

//  push -> Insert element into stack
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

//  pop -> Remove element from stack
char pop()
{
    if (top == -1)
    {
        return '\0'; // safe return
    }
    return stack[top--];
}
