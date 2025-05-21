// Design and implement C/C++ program to obtain the Topological ordering of vertices in a
// given digraph.

#include <stdio.h>
int cost[10][10], n, colsum[10];

void cal_colsum()
{
    for (int j = 0; j < n; j++)
    {
        colsum[j] = 0;
        for (int i = 0; i < n; i++)
            colsum[j] += cost[i][j];
    }
}

void source_removal()
{
    int i, j, k, select[10] = {0};
    printf("Topological ordering is: ");
    for (i = 0; i < n; i++)
    {
        cal_colsum();
        for (j = 0; j < n; j++)
        {
            if (select[j] == 0 && colsum[j] == 0)
                break;
        }
        printf("%d ", j);
        select[j] = 1;
        for (k = 0; k < n; k++)
            cost[j][k] = 0;
    }
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    source_removal();
    return 0;
}

// Output:
// Enter the number of vertices: 5
// Enter the cost matrix:
// 0   1   1   0   0
// 0   0   0   1   1
// 0   0   0   1   0
// 0   0   0   0   1
// 0   0   0   0   0
// Topological Ordering is: 01234