#include <stdio.h>
#include <stdlib.h>

// simple node
struct node
{
    int data;
    struct node *next;
};

// queue
struct queue
{
    struct node *front;
    struct node *rear;
};

void create_queue(struct queue *);
struct queue *insert(struct queue *, int);
struct queue *delete(struct queue *);
struct queue *display(struct queue *);
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
            q = display(q);
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

// create empty queue
void create_queue(struct queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

// insert
struct queue *insert(struct queue *q, int val)
{
    // newNode
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    // if: empty queue
    if (q->front == NULL)
    {
        q->front = newNode;
        q->rear = newNode;
    }
    // else: there are elememets
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("\nInserted %d into the queue.", val);
    return q;
}

// delete
struct queue *delete(struct queue *q)
{
    // assign ptr node to front node of queue
    struct node *ptr = q->front;

    // if queue is empty
    if (ptr == NULL)
    {
        printf("\nUnderflow! Queue is empty.");
    }
    else
    {
        // delete ptr [q->front] and increment it.
        printf("\nDeleted value: %d", ptr->data);
        q->front = q->front->next;
        free(ptr);

        // if queue become empty
        if (q->front == NULL)
            q->rear = NULL; // reset when queue becomes empty
    }

    return q;
}

// display
struct queue *display(struct queue *q)
{
    // assign ptr node to front node of queue
    struct node *ptr = q->front;

    // if queue is empty
    if (ptr == NULL)
    {
        printf("\nUnderflow! Queue is empty.");
    }
    else
    {
        printf("\nQueue elements: ");
        while (ptr != NULL)
        {
            printf("%d-> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL");
    }

    return q;
}

// peek
int peek(struct queue *q)
{
    // if queue is empty
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
