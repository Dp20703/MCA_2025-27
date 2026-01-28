#include <stdio.h>
#define MAX 5

void DFS(int adj[MAX][MAX], int start)
{
    int visited[MAX] = {0};
    int stack[MAX];
    int top = -1;

    // push start node
    stack[++top] = start;

    while (top != -1)
    {
        int curr = stack[top--];

        // process only if not visited
        if (!visited[curr])
        {
            printf("%c -> ", curr + 65);
            visited[curr] = 1;

            // push neighbours in reverse order
            for (int i = MAX - 1; i >= 0; i--)
            {
                if (adj[curr][i] && !visited[i])
                {
                    stack[++top] = i;
                }
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

    printf("DFS Traversal: ");
    DFS(adj, 0);
    printf("\n");

    return 0;
}
