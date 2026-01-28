// 9. Write a program to evaluate a prefix expression.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int st[10];   // stack to hold operands and results
int top = -1; // top index of the stack

int pop();          // function to remove top element from stack
void push(int);     // function to add element to stack
int get_type(char); // function to check if char is operator or operand

int main()
{
    char prefix[10]; // array to store prefix expression
    int len, val, op1, op2, res;

    printf("\nEnter prefix expression:");
    // gets(prefix);       // read prefix expression (unsafe, but works for small inputs)
    fgets(prefix, sizeof(prefix), stdin);

    len = strlen(prefix); // find length of expression

    // Loop from right to left because prefix is evaluated backwards
    for (int i = len - 1; i >= 0; i--)
    {
        switch (get_type(prefix[i]))
        {
        case 0:                    // operand
            val = prefix[i] - '0'; // convert char digit to int (e.g. '3' → 3)
            push(val);             // push operand onto stack
            break;

        case 1:          // operator
            op2 = pop(); // get second operand
            op1 = pop(); // get first operand

            // Apply operator on operands
            switch (prefix[i])
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                res = op1 / op2;
                break;
            }
            push(res); // push result back to stack
            break;
        }
    }

    // Final result will be the only value left in stack
    printf("\n RESULT = %d", st[0]);

    return 0;
}

// Function to pop value from stack
int pop()
{
    return (st[top--]);
}

// Function to push value onto stack
void push(int value)
{
    st[++top] = value;
}

// Function to check if a character is operator or operand
int get_type(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
    {
        return 1; // operator
    }
    return 0; // operand
}
