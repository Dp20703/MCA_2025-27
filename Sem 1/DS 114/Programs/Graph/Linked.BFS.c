#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// Node of adjacency list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create new node
struct Node *createNode(int v)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

void BFS(struct Node *adj[], int start)
{
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("\nBFS Traversal: ");

    while (front < rear)
    {
        int curr = queue[front++];

        printf("%c -> ", curr + 65);

        // visit neigbours
        struct Node *temp = adj[curr];
        while (temp != NULL)
        {
            if (!visited[temp->data])
            {
                queue[rear++] = temp->data;
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    int n, e, i, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    struct Node *adj[MAX] = {NULL};

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v):\n");
    for (i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);

        // u -> v
        struct Node *newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // v -> u (for undirected graph)
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(adj, start);

    return 0;
}
