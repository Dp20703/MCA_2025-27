#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);

struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);

struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_before(struct node *);
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
        printf("\n 5 : Add a node before a given node");
        printf("\n 6 : Add a node after a given node");
        printf("\n 7 : Delete a node from the beginning");
        printf("\n 8 : Delete a node from the end");
        printf("\n 9 : Delete a node before a given node");
        printf("\n 10 : Delete a node after a given node");
        printf("\n 11 : Delete the entire list");
        printf("\n 12 : EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            head = create_ll(head);
            printf("\n Link List Created!...");
            break;
        case 2:
            head = display(head);
            break;
        case 3:
            head = insert_beg(head);
            break;
        case 4:
            head = insert_end(head);
            break;
        case 5:
            head = insert_before(head);
            break;
        case 6:
            head = insert_after(head);
            break;
        case 7:
            head = delete_beg(head);
            break;
        case 8:
            head = delete_end(head);
            break;
        case 9:
            head = delete_before(head);
            break;
        case 10:
            head = delete_after(head);
            break;
        case 11:
            head = delete_list(head);
            printf("\n Link List Deleted!...");
            break;
        case 12:
            printf("\n Bye bye");
            break;
        default:
            printf("\n Invalid option");
            break;
        }

    } while (option != 12);
    return 0;
}

struct node *create_ll(struct node *head)
{
    struct node *ptr, *newNode;
    int num;
    printf("\n Enter -1 to stop");
    printf("\n Enter value:");
    scanf("%d", &num);
    while (num != -1)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = num;
        if (head == NULL)
        {
            newNode->prev = NULL;
            newNode->next = NULL;
            head = newNode;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->prev = ptr;
            newNode->next = NULL;
        }
        printf("\n Enter value:");
        scanf("%d", &num);
    }
    return head;
}

struct node *display(struct node *head)
{
    if (head == NULL)
    {
        printf("\n List is empty");
        return head;
    }
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("\t %d ->", ptr->data);
        ptr = ptr->next;
    }
    printf(" NULL");
    return head;
}

struct node *insert_beg(struct node *head)
{
    struct node *newNode;
    int num;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter a value:");
    scanf("%d", &num);
    newNode->prev = NULL;
    newNode->data = num;
    newNode->next = head;

    head->prev = newNode;
    head = newNode;
    return head;
};

struct node *insert_end(struct node *head)
{
    struct node *newNode, *ptr;
    int num;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter a value:");
    scanf("%d", &num);
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->prev = ptr;
    newNode->data = num;
    newNode->next = NULL;

    return head;
};

struct node *insert_before(struct node *head)
{
    struct node *new_node, *ptr;
    int num, val;

    printf("\n Enter data: ");
    scanf("%d", &num);

    printf("\n Enter the value before which the data has to be inserted: ");
    scanf("%d", &val);

    // empty list
    if (head == NULL)
    {
        printf("\n Linked list is empty");
        return head;
    }

    // create node
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    ptr = head;

    // safe search
    while (ptr != NULL && ptr->data != val)
    {
        ptr = ptr->next;
    }

    // value not found
    if (ptr == NULL)
    {
        printf("\n Value not found!");
        free(new_node);
        return head;
    }

    // insert before first node
    if (ptr == head)
    {
        new_node->prev = NULL;
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return head;
    }

    // insert before middle node
    new_node->prev = ptr->prev;
    new_node->next = ptr;
    ptr->prev->next = new_node;
    ptr->prev = new_node;

    return head;
}

struct node *insert_after(struct node *head)
{
    struct node *new_node, *ptr;
    int num, val;

    printf("\n Enter data: ");
    scanf("%d", &num);

    printf("\n Enter the value after which the data has to be inserted: ");
    scanf("%d", &val);

    if (head == NULL)
    {
        printf("\n Linked list is empty");
        return head;
    }

    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;

    ptr = head;

    // safe search
    while (ptr != NULL && ptr->data != val)
    {
        ptr = ptr->next;
    }

    // value not found
    if (ptr == NULL)
    {
        printf("\n Value not found!");
        free(new_node);
        return head;
    }

    // insert after ptr
    new_node->prev = ptr;
    new_node->next = ptr->next;

    if (ptr->next != NULL)
    {
        ptr->next->prev = new_node;
    }

    ptr->next = new_node;

    return head;
}

struct node *delete_beg(struct node *head)
{
    if (head == NULL)
    {
        printf("\n Linked list is empty");
        return head;
    }

    struct node *ptr = head;
    head = head->next;

    head->prev = NULL;

    free(ptr);
    return head;
};
struct node *delete_end(struct node *head)
{
    struct node *ptr;

    if (head == NULL)
    {
        printf("\n Linked list is empty");
        return NULL;
    }

    ptr = head;

    // move to last node
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    // case: only one node
    if (ptr == head)
    {
        free(ptr);
        return NULL;
    }

    // case: more than one node
    ptr->prev->next = NULL;
    free(ptr);

    return head;
}

struct node *delete_before(struct node *head)
{
    struct node *ptr, *temp;
    int val;

    if (head == NULL)
    {
        printf("\n Linked list is empty");
        return head;
    }

    printf("\n Enter the value of node before which you want to delete: ");
    scanf("%d", &val);

    ptr = head;

    // SAFE search
    while (ptr != NULL && ptr->data != val)
    {
        ptr = ptr->next;
    }

    // value not found
    if (ptr == NULL)
    {
        printf("\n No value found!");
        return head;
    }

    // no node before (first node)
    if (ptr->prev == NULL)
    {
        printf("\n No node to delete!");
        return head;
    }

    temp = ptr->prev;

    // deleting first node
    if (temp == head)
    {
        head = delete_beg(head);
    }
    else
    {
        temp->prev->next = ptr;
        ptr->prev = temp->prev;
        free(temp);
    }

    return head;
}

struct node *delete_after(struct node *head)
{
    struct node *ptr, *temp;
    int val;

    if (head == NULL)
    {
        printf("\n Linked list is empty");
        return head;
    }

    printf("\n Enter the value of node after which you want to delete: ");
    scanf("%d", &val);

    ptr = head;

    // safe search
    while (ptr != NULL && ptr->data != val)
    {
        ptr = ptr->next;
    }

    // value not found
    if (ptr == NULL)
    {
        printf("\n No value found!");
        return head;
    }

    // no node after
    if (ptr->next == NULL)
    {
        printf("\n No node to delete after this value!");
        return head;
    }

    // delete node after ptr
    temp = ptr->next;
    ptr->next = temp->next;

    if (temp->next != NULL)
    {
        temp->next->prev = ptr;
    }

    free(temp);
    return head;
}

struct node *delete_list(struct node *head)
{
    if (head == NULL)
    {
        printf("\n Linked list is empty");
        return head;
    }
    while (head->next != NULL)
    {
        head = delete_beg(head);
    }
    free(head);
    return NULL;
};