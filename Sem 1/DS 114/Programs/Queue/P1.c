// 1. Write a program to implement a linear queue.
#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void insert(void);
int delete(void);
int peek(void);
void display(void);

int main()
{
    int option, value;

    do
    {
        printf("\n\n**** MAIN MENU ****");
        printf("\n1. Insert an element");
        printf("\n2. Delete an element");
        printf("\n3. Peek");
        printf("\n4. Display the queue");
        printf("\n5. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            value = delete();
            if (value == -1)
            {
                printf("Queue is empty. Nothing to delete.\n");
            }
            else
            {
                printf("Deleted element: %d\n", value);
            }
            break;
        case 3:
            value = peek();
            if (value == -1)
            {
                printf("Queue is empty.\n");
            }
            else
            {
                printf("Front element: %d\n", value);
            }
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Bye bye!\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
        }
    } while (option != 5);

    return 0;
}

void insert()
{
    int elem;
    printf("Enter element to be inserted: ");
    scanf("%d", &elem);

    if (rear == MAX - 1)
    {
        printf("Overflow! Can't insert element.\n");
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear++;
        }
        queue[rear] = elem;
        printf("Inserted element: %d\n", elem);
    }
}

int delete()
{
    if (front == -1 || front > rear)
    {
        printf("Underflow! Queue is empty.\n");
        return -1;
    }
    else
    {
        int val = queue[front];
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
        return val;
    }
}

int peek()
{
    if (front == -1 || front > rear)
    {
        printf("Underflow! Queue is empty.\n");
        return -1;
    }
    else
    {
        return queue[front];
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
