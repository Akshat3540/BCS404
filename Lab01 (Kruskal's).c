//Design and implement C/C++ program to find Minimum Cost Spanning Tree of a given
//connected undirected graph using Kruskal’s algorithm.

#include <stdio.h>

int ne = 1, min_cost = 0;

void main() {
    int n, i, j, w, min, a, u, b, v;
    int cost[20][20], parent[20];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);

    for (i = 1; i <= n; i++)
        parent[i] = 0;

    printf("\nThe edges of the spanning tree are:\n");

    while (ne < n) {
        min = 999;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        while (parent[u])
            u = parent[u];
        while (parent[v])
            v = parent[v];

        if (u != v) {
            printf("Edge %d\t(%d -> %d) = %d\n", ne++, a, b, min);
            min_cost += min;
            parent[v] = u;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", min_cost);
}

// Output:
// Enter the number of vertices: 6
// Enter the cost matrix:
// 999 3 999 999 6 5
// 3 999 1 999 999 4
// 999 1 999 6 999 4
// 999 999 6 999 8 5
// 6 999 999 8 999 2
// 5 4 4 5 2 999
// The edges of spanning tree are
// Edge 1
// (2->3)=1
// Edge 2 (5->6)=2
// Edge 3 (1->2)=3
// Edge 4 (2->6)=4 Edge 5 (4->6)=5
// Minimum cost=15
