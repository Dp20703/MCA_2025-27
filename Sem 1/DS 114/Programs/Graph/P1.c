// 1. Write a program to create a graph of n vertices using an adjacency list.Also write the code to read and print its information and finally to delete the graph

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char vertex;
    struct Node *next;
};

struct Node *gnode;
void displayGraph(struct Node *adj[], int n);
void deleteGraph(struct Node *adj[], int n);
void createGraph(struct Node *adj[], int n);
int main()
{
    struct Node *adj[10];
    int i, n;

    printf("\n Enter the number of nodes in G ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        adj[i] = NULL;
    }
    createGraph(adj, n);
    printf("\n The Graph is : ");
    displayGraph(adj, n);

    deleteGraph(adj, n);

    return 0;
}

void createGraph(struct Node *adj[], int total_nodes)
{

    struct Node *newNode, *last;
    int n, val;
    for (int i = 0; i < total_nodes; i++)
    {
        last = NULL;
        printf("\n Enter the neighbours of %d : ", i + 1);
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            printf("\n Enter the neighbour %d of %d: ", j + 1, i + 1);
            scanf("%d", &val);
            newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->vertex = val;
            newNode->next = NULL;
            if (adj[i] == NULL)
            {
                adj[i] = newNode;
            }
            else
            {
                last->next = newNode;
            }
            last = newNode;
        }
    }
}

void displayGraph(struct Node *adj[], int total_nodes)
{
    struct Node *ptr;
    for (int i = 0; i < total_nodes; i++)
    {
        ptr = adj[i];
        printf("\n The neighbours of node %d are:", i + 1);
        while (ptr != NULL)
        {
            printf("\t %d", ptr->vertex);
            ptr = ptr->next;
        }
    }
}
void deleteGraph(struct Node *adj[], int total_nodes)
{
    struct Node *ptr, *temp;
    for (int i = 0; i <= total_nodes; i++)
    {
        ptr = adj[i];

        while (ptr != NULL)
        {
            temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
        adj[i] = NULL;
    }
}