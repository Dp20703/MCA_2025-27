#include <stdio.h>
#define MAX 5

// BFS
void BFS(int adj[MAX][MAX], int start)
{
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;

    // enqueue start node
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear)
    {
        int curr = queue[front++];

        // print node
        printf("%c ", curr + 65);

        // visit neighbours
        for (int i = 0; i < MAX; i++)
        {
            if (adj[curr][i] && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int adj[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            scanf("%d", &adj[i][j]);

    BFS(adj, 0);

    return 0;
}
