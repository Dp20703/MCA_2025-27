// 2. Write a program to implement a linked stack.

// 2️⃣ Linked Stack Using Pointer-to-Pointer Approach

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Function declarations
void push(struct Node **top, int value);
void pop(struct Node **top);
int peek(struct Node *top);
void display(struct Node *top);

int main()
{
    struct Node *top = NULL; // Stack is empty
    int choice, value;

    do
    {
        printf("\n--- Linked Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&top, value); // pass address of top
            break;
        case 2:
            pop(&top); // pass address of top
            break;
        case 3:
            value = peek(top);
            if (value != -1)
                printf("Top element: %d\n", value);
            else
                printf("Stack is empty\n");
            break;
        case 4:
            display(top);
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

// Push function
void push(struct Node **top, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top; // link old top
    *top = newNode;       // update top in main
    printf("%d pushed to stack\n", value);
}

// Pop function
void pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    struct Node *temp = *top;
    printf("The value being deleted is: %d\n", temp->data);
    *top = (*top)->next; // update top in main
    free(temp);
}

// Peek function
int peek(struct Node *top)
{
    if (top == NULL)
        return -1;
    return top->data;
}

// Display function
void display(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    struct Node *ptr = top;
    printf("Stack elements (top to bottom):\n");
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
