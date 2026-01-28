#include <stdio.h>
#define MAX 5
void BFS(int adj[][MAX], int visited[], int start)
{
    // make a queue and set rear and front = -1
    int queue[MAX], rear = -1, front = -1;

    // insert start (0) into queue
    queue[++rear] = start;
    // mark start as visited ( visited[0] = 1 )
    visited[start] = 1;

    // loop all the nodes
    while (rear != front)
    {
        // remove element from the queue
        start = queue[++front];
        // print the character 0 + 65 = A
        printf("%c \t", start + 65);

        // Find Neighbour Nodes
        for (int i = 0; i < MAX; i++)
        {
            // if they have connection and not visited then
            if (adj[start][i] == 1 && visited[i] == 0)
            {
                //  push into queue and mark it visited
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
};
int main()
{
    int adj[MAX][MAX];      // adjancency matrix
    int visited[MAX] = {0}; // set 0 [ not visited ]

    // insert adjancency matrix's elements
    printf("\n Enter the adjancency matrix: ");
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
            scanf("%d", &adj[i][j]);
    }
    // call the BFS
    BFS(adj, visited, 0);

    return 0;
}

// 🧠 How BFS Works (Simple Explanation)

// Pick a starting node.

// Visit and put it in queue.

// Remove node from queue.

// Visit all its unvisited neighbors and put them in queue.

// Repeat until queue becomes empty.

// 👉 BFS uses Queue
// 👉 BFS is level-wise traversal
// 👉 BFS gives shortest path in unweighted graphs