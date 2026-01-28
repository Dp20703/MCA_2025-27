#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
int main()
{
    struct Node *head = NULL;
    struct Node *first = NULL;
    struct Node *second = NULL;

    // assign memeory
    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));

    // assign values
    head->data = 10;
    head->next = first;

    first->data = 20;
    first->next = second;

    second->data = 30;
    second->next = NULL;

    struct Node *temp = head;

    // while (temp != NULL)
    // {
    //     printf("%d ->", temp->data);
    //     temp = temp->next;
    // }
    // printf(" NULL");

    return 0;
}
