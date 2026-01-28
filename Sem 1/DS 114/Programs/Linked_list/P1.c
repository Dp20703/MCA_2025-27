// 1. Write a program to create a linked list and perform insertions and deletions of all cases.
// Write functions to sort and finally delete the entire list at once.

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
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);

struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);

struct node *sort_list(struct node *);

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
        printf("\n 5 : Add a node before a given node");
        printf("\n 6 : Add a node after a given node");
        printf("\n 7 : Delete a node from the beginning");
        printf("\n 8 : Delete a node from the end");
        printf("\n 9 : Delete a given node");
        printf("\n 10 : Delete a node after a given node");
        printf("\n 11 : Delete the entire list");
        printf("\n 12 : Sort the list");
        printf("\n 13 : EXIT");
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
            start = insert_before(start);
            break;
        case 6:
            start = insert_after(start);
            break;
        case 7:
            start = delete_beg(start);
            break;
        case 8:
            start = delete_end(start);
            break;
        case 9:
            start = delete_node(start);
            break;
        case 10:
            start = delete_after(start);
            break;
        case 11:
            start = delete_list(start);
            printf("\n Link List Deleted!...");
            break;
        case 12:
            start = sort_list(start);
            break;
        case 13:
            printf("\n Bye bye");
            break;
        default:
            printf("\n Invalid option");
            break;
        }
    } while (option != 13);
    return 0;
}

// create linked list
struct node *create_ll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter number : ");
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (start == NULL)
        {
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = NULL;
        }
        printf("\n Enter number : ");
        scanf("%d", &num);
    }
    return start;
}

// display
struct node *display(struct node *start)
{
    if (start == NULL)
    {
        printf("\n Underflow..");
        return start;
    }
    struct node *ptr;
    ptr = start;
    while (ptr != NULL)
    {
        printf("%d ->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    return start;
}

// insertion at begning
struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("\n Enter value:");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    return start;
}
// insertion at end
struct node *insert_end(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter value:");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    if (start == NULL) // handle empty list
    {
        start = new_node;
        return start;
    }
    ptr = start;
    // traverse till ptr->next= null
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    return start;
}
// insertion before a given node
struct node *insert_before(struct node *start)
{
    struct node *new_node, *ptr, *prevptr;
    int num, val;
    printf("\n Enter value:");
    scanf("%d", &num);
    printf("\n Enter the value before which the data has to be inserted :");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    // Case 1: empty list
    if (start == NULL)
    {
        printf("\n List is empty.");
        free(new_node);
        return start;
    }
    // Case 2: before first node
    if (start->data == val)
    {
        new_node->next = start;
        start = new_node;
        return start;
    }

    // Case 3: search in middle
    ptr = start;
    // traverse till ptr->data= val
    while (ptr->data != val && ptr != NULL)
    {
        prevptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("\n Value not found.");
        free(new_node);
    }
    else
    {
        prevptr->next = new_node;
        new_node->next = ptr;
    }
    return start;
}
// insertion after a given node
struct node *insert_after(struct node *start)
{
    struct node *new_node, *ptr, *prevptr;
    int num, val;
    printf("\n Enter value:");
    scanf("%d", &num);
    printf("\n Enter the value after which the data has to be inserted :");
    scanf("%d", &val);

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    ptr = start;
    prevptr = ptr;
    // traverse till prevptr->data= val
    while (prevptr->data != val)
    {
        prevptr = ptr;
        ptr = ptr->next;
    }
    prevptr->next = new_node;
    new_node->next = ptr;
    return start;
}

// deletion at begning
struct node *delete_beg(struct node *start)
{
    if (start == NULL)
    {
        printf("\n List is empty.");
        return start;
    }
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}
// deletion at ending
struct node *delete_end(struct node *start)
{
    if (start == NULL)
    {
        printf("\n List is empty.");
        return start;
    }
    if (start->next == NULL) // only one node
    {
        free(start);
        return NULL;
    }
    struct node *ptr, *prevptr;
    ptr = start;
    prevptr = ptr;
    while (ptr->next != NULL)
    {
        prevptr = ptr;
        ptr = ptr->next;
    }
    prevptr->next = NULL;
    free(ptr);
    return start;
}

// delete node
struct node *delete_node(struct node *start)
{
    struct node *ptr, *prevptr;
    int val;
    printf("\n Enter the value of node which has to be deleted:");
    scanf("%d", &val);
    ptr = start;
    if (ptr->data == val)
    {
        start = delete_beg(start);
        return start;
    }
    else
    {
        while (ptr->data != val)
        {
            prevptr = ptr;
            ptr = ptr->next;
        }
        prevptr->next = ptr->next;
        free(ptr);
        return start;
    }
}
// delete after a given node
struct node *delete_after(struct node *start)
{
    struct node *ptr, *prevptr;
    int val;
    printf("\n Enter the value after which the node has to be deleted:");
    scanf("%d", &val);
    ptr = start;
    prevptr = ptr;
    while (prevptr->data != val)
    {
        prevptr = ptr;
        ptr = ptr->next;
    }
    prevptr->next = ptr->next;
    free(ptr);
    return start;
}

// delete list
struct node *delete_list(struct node *start)
{
    struct node *ptr;
    if (start != NULL)
    {
        ptr = start;
        while (ptr != NULL)
        {
            printf("\n%d is to be deleted next ", ptr->data);
            start = delete_beg(ptr);
            ptr = start;
        }
    }
    return start;
}
// sort list
struct node *sort_list(struct node *start)
{
    if (start == NULL)
    {
        printf("\n Underflow..");
        return start;
    }
    struct node *ptr1, *ptr2;
    int temp;
    ptr1 = start;
    while (ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if (ptr1->data > ptr2->data)
            {
                int temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}