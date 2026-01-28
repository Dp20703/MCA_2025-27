#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
};

void create_queue(struct queue *);
void display(struct queue *);
struct queue *insert(struct queue *, int);
struct queue *delete(struct queue *);
int peek(struct queue *);

int main()
{
    int val, option;
    struct queue *q;

    // ✅ Allocate memory for queue structure
    q = (struct queue *)malloc(sizeof(struct queue));
    create_queue(q);

    do
    {
        printf("\n\n--- Queue Menu ---\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nEnter the number to insert in the queue: ");
            scanf("%d", &val);
            q = insert(q, val);
            break;

        case 2:
            q = delete(q);
            break;

        case 3:
            val = peek(q);
            if (val != -1)
                printf("\nFront value in queue: %d", val);
            break;

        case 4:
            display(q);
            break;

        case 5:
            printf("\nBye bye!\n");
            break;

        default:
            printf("\nInvalid option!");
        }

    } while (option != 5);

    return 0;
}

void create_queue(struct queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

struct queue *insert(struct queue *q, int val)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;

    if (q->front == NULL) // empty queue
    {
        q->front = newNode;
        q->rear = newNode;
        newNode->next = newNode; // circular link
    }
    else
    {
        newNode->next = q->front;
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("\nInserted %d into the queue.", val);
    return q;
}

struct queue *delete(struct queue *q)
{
    struct node *ptr;

    if (q->front == NULL)
    {
        printf("\n Queue is empty:");
        return q;
    }

    ptr = q->front;

    // Only one node
    if (q->front == q->rear)
    {
        printf("\n Deleted value %d from the queue.", ptr->data);
        q->front = q->rear = NULL;
        free(ptr);
    }
    else
    {
        printf("\n Deleted value %d from the queue.", ptr->data);
        q->front = q->front->next;
        q->rear->next = q->front;
        free(ptr);
    }
    return q;
}

void display(struct queue *q)
{
    struct node *ptr;

    if (q->front == NULL)
    {
        printf("\n Queue is empty:");
        return;
    }

    ptr = q->front;
    do
    {
        printf("\t %d ->", ptr->data);
        ptr = ptr->next;
    } while (ptr != q->front);

    printf("(back to front)");
}

int peek(struct queue *q)
{
    if (q->front == NULL)
    {
        printf("\nQueue is empty.");
        return -1;
    }
    else
    {
        return q->front->data;
    }
}
