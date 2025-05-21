#include <stdio.h>
void warshal(int A[][10], int n)
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                A[i][j] = A[i][j] || (A[i][k] && A[k][j]);
}
int main()
{
    int n, adj[10][10];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &adj[i][j]);
    warshal(adj, n);
    printf("Transitive closure of the given graph is:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
    return 0;
}

// Output:
// Enter the number of vertices: 4
// Enter the adjacency matrix:
// 0   1   0   0
// 0   0   0   1
// 0   0   0   0
// 1   0   1   0
// Transitive Closure of the given graph is
// 1   1   1   1
// 1   1   1   1
// 0   0   0   0
// 1   1   1   1