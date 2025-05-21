// Design and implement C/C++ Program to find Minimum Cost Spanning Tree of a given
// connected undirected graph using Prim’s algorithm.

#include <stdio.h>
int ne = 1, min_cost = 0;
void main()
{
    int n, i, j, min, cost[20][20], a, u, b, v, source, visited[20];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    printf("Enter the root node: ");
    scanf("%d", &source);
    visited[source] = 1;
    printf("\nMinimum cost spanning tree is\n");
    while (ne < n)
    {
        min = 999;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    if (visited[i] == 0)
                        continue;
                    else
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        if (visited[u] == 0 || visited[v] == 0)
        {
            printf("\nEdge %d\t(%d -> %d) = %d\n", ne++, a, b, min);
            min_cost = min_cost + min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\nMinimum cost = %d\n", min_cost);
}

// Output:
// Enter the number of nodes: 4
// Enter the cost matrix:
// 999  1   5   2
// 1    999 999 999
// 5    999 999 3
// 2    999 3   999
// Enter the root node: 1
// Edge 1 (1->2) = 1
// Edge 2 (1->4) = 2
// Edge 3 (4->3) = 3
// Minimum Cost = 6