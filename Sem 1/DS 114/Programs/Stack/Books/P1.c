// 1. Write a program to perform Push, Pop, and Peek operations on a stack.

#include <stdio.h>
#define MAX 5
int top = -1;
int stack[MAX];

void display(void);
void push(void);
int pop(void);
int peek(void);
int isEmpty(void);

int main()
{
    int choice, val;

    do
    {
        printf("\n---- Stack Menu ----\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            val = pop();
            if (val != -1)
                printf("\n Popped element: %d", val);
            break;
        case 3:
            val = peek();
            if (val != -1)
                printf("\n Top element: %d", val);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}

void display()
{
    if (isEmpty())
    {
        printf("\n Stack is Empty");
    }
    else
    {
        printf("\n... Displaying stack elements (Top to Bottom): ...\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int peek()
{
    if (isEmpty())
    {
        printf("\n Stack is Empty");
        return -1;
    }
    else
    {
        return stack[top];
    }
}

int pop()
{
    if (isEmpty())
    {
        printf("\n Stack is Empty");
        return -1;
    }
    return stack[top--];
}

void push()
{
    int val;
    printf("\n Enter the element to be inserted: ");
    scanf("%d", &val);

    if (isFull())
    {
        printf("\n Stack is full");
    }
    else
    {
        stack[++top] = val;
        printf("%d pushed successfully", val);
    }
}

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == MAX - 1;
}
