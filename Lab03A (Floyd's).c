// Design and implement C/C++ Program to solve All-Pairs Shortest Paths problem
// using Floyd’s algorithm.

#include <stdio.h>
int min(int a, int b)
{
    return (a < b ? a : b);
}
void floyd(int D[][10], int n)
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
}
int main()
{
    int n, cost[10][10];
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);
    floyd(cost, n);
    printf("All pair shortest path:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d ", cost[i][j]);
        printf("\n");
    }
    return 0;
}

// Output:
// Enter the number of vertices: 4
// Enter the cost matrix:
// 999 8   4   999
// 999 999 1   999
// 4   999 999 999
// 999 2   9   999
// All pair shortest path
// 8   8   4   999
// 5   13  1   999
// 4   12  8   999
// 7   2   3   999