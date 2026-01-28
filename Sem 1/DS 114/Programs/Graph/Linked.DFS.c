#include <stdio.h>
#include <stdlib.h>
#define MAX 5

// Node for adjacency list
struct Node
{
    int vertex;
    struct Node *next;
};

// Create new node
struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// DFS using Stack (Iterative)
void DFS(struct Node *adj[], int start)
{
    int visited[MAX] = {0};
    int stack[MAX], top = -1;

    stack[++top] = start;
    visited[start] = 1;

    printf("DFS Traversal: ");

    while (top != -1)
    {
        start = stack[top--]; // pop
        printf("%c -> ", start + 65);

        struct Node *temp = adj[start];
        while (temp != NULL)
        {
            if (!visited[temp->vertex])
            {
                stack[++top] = temp->vertex; // push
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    struct Node *adj[MAX];
    int n, v;

    // initialize
    for (int i = 0; i < MAX; i++)
        adj[i] = NULL;

    // Taking input as adjacency list
    printf("Enter adjacency list (enter -1 to stop):\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("Enter nodes connected to %c: ", i + 65);

        while (1)
        {
            scanf("%d", &v);
            if (v == -1) // stop for that vertex
                break;

            struct Node *newNode = createNode(v);
            newNode->next = adj[i];
            adj[i] = newNode;
        }
    }

    DFS(adj, 0); // start from node A (0)

    return 0;
}
