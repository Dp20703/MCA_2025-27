// 3. Write a program to implement a circular queue.
#include <stdio.h>
#define MAX 10
int queue[MAX];
int front = -1, rear = -1;
void insert(void);
void display(void);
int delete(void);
int peek(void);
int main()
{
    int option;
    int val;
    do
    {
        printf("\n 1. Insert ");
        printf("\n 2. Delete ");
        printf("\n 3. Peek ");
        printf("\n 4. Display ");
        printf("\n 5. Exit ");
        printf("\nEnter option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            val = delete();
            if (val != -1)
            {
                printf("Deleted element : %d", val);
            }
            break;
        case 3:
            val = peek();
            if (val != -1)
            {
                printf("Front element : %d", val);
            }
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Bye bye");
            break;

        default:
            printf("\nInvalid option ");
            break;
        }
    } while (option != 5);

    return 0;
}

void insert()
{
    int val;
    printf("\nEnter element to be inserted ....");
    scanf("%d", &val);

    if (front == 0 && rear == MAX - 1)
    {
        printf("\n Overflow ");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = val;
    }
    else if (rear == MAX - 1 && front != 0)
    {
        rear = 0;
        queue[rear] = val;
    }
    else
    {
        rear++;
        queue[rear] = val;
    }
};
int delete()
{
    int value;
    // 1st condition for underflow
    if (front == -1 && rear == -1)
    {
        printf("\nUnderflow !");
        return -1;
    }

    // set value
    value = queue[front];

    // 2nd condition for last element
    if (front == rear)
    {
        front = rear = -1;
    }
    // 3rd condition
    else
    {
        // i. if the front is set to 0
        if (front == MAX - 1)
        {
            front = 0;
        }
        // ii. increment the front
        else
        {
            front++;
        }
    }
    return value;
};
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is empty !");
    }
    else
    {
        if (front < rear)
        {
            for (int i = front; i <= rear; i++)
            {
                printf("\t %d", queue[i]);
            }
        }
        else
        {
            for (int i = front; i < MAX; i++)
            {
                printf("\t %d", queue[i]);
            }
            for (int i = 0; i <= rear; i++)
            {
                printf("\t %d", queue[i]);
            }
        }
    }
};
int peek()
{
    if (front == -1 && rear == -1)
    {
        printf("\nUnderflow !");
        return -1;
    }
    else
    {
        return queue[front];
    }
};
