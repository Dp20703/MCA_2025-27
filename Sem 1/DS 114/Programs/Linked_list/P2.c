// 2. Write a program to create a circular linked list. Perform insertion and deletion at the beginning
// and end of the list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;

struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
int main()
{
    int option;
    do
    {
        printf("\n\n * ****MAIN MENU * ****");
        printf("\n 1 : Create a list");
        printf("\n 2 : Display the list");
        printf("\n 3 : Add a node at the beginning");
        printf("\n 4 : Add a node at the end");
        printf("\n 5 : Delete a node from the beginning");
        printf("\n 6 : Delete a node from the end");
        printf("\n 7 : Delete a node after a given node");
        printf("\n 8 : Delete the entire list");
        printf("\n 9 : EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = create_ll(start);
            printf("\n Link List Created!...");
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = insert_beg(start);
            break;
        case 4:
            start = insert_end(start);
            break;
        case 5:
            start = delete_beg(start);
            break;
        case 6:
            start = delete_end(start);
            break;
        case 7:
            start = delete_after(start);
            break;
        case 8:
            start = delete_list(start);
            printf("\n Link List Deleted!...");
            break;
        case 9:
            printf("\n Bye bye");
            break;
        default:
            printf("\n Invalid option");
            break;
        }
    } while (option != 9);
    return 0;
}
struct node *create_ll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n enter -1 to end");
    printf("\nEnter the data: ");
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (start == NULL)
        {
            new_node->next = new_node;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != start)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = start;
        }
        printf("\n Enter the data: ");
        scanf("%d", &num);
    }
    return start;
};
struct node *display(struct node *start)
{
    if (start == NULL)
    {
        printf("Linked list is empty\n");
        return start;
    }
    struct node *ptr = start;

    while (ptr->next != start)
    {
        printf("\t %d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\t %d", ptr->data);
    return start;
};
struct node *insert_beg(struct node *start)
{

    struct node *new_node, *ptr;
    int num;
    printf("\n Enter data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = start;
    start = new_node;
    return start;
};
struct node *insert_end(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = start;
    return start;
};
struct node *delete_beg(struct node *start)
{

    if (start == NULL)
    {
        printf("Linked list is empty\n");
        return start;
    }

    struct node *ptr;
    ptr = start;
    while (ptr->next != start)
    {
        ptr = ptr->next;
    }
    ptr->next = start->next;
    free(start);
    start = ptr->next;
    return start;
};
struct node *delete_end(struct node *start)
{
    if (start == NULL)
    {
        printf("Linked list is empty\n");
        return start;
    }

    // 🔴 SINGLE NODE CASE
    if (start->next == start)
    {
        free(start);
        return NULL;
    }

    struct node *ptr, *prevptr;
    ptr = start;
    while (ptr->next != start)
    {
        prevptr = ptr;
        ptr = ptr->next;
    }
    prevptr->next = ptr->next;
    free(ptr);
    return start;
};
struct node *delete_after(struct node *start)
{

    if (start == NULL)
    {
        printf("Linked list is empty\n");
        return start;
    }

    struct node *ptr, *prevptr;
    int val;
    ptr = start;
    prevptr = ptr;
    printf("\n Enter the value after which the node has to be deleted:");
    scanf("%d", &val);
    while (prevptr->data != val)
    {
        prevptr = ptr;
        ptr = ptr->next;
    }
    prevptr->next = ptr->next;
    if (ptr == start)
        start = prevptr->next;
    free(ptr);
    return start;
};
struct node *delete_list(struct node *start)
{
    if (start == NULL)
    {
        printf("Linked list is empty\n");
        return start;
    }

    struct node *ptr;
    ptr = start;
    while (ptr->next != start)
    {
        start = delete_end(start);
    }
    free(start);
    return NULL;
};