// Design and implement C/C++ program to solve 0/1 Knapsack Problem using Dynamic
// Programming method.

#include <stdio.h>
int n, m, p[10], w[10];

int max(int a, int b)
{
    return (a > b ? a : b);
}

void knapsack()
{
    int V[10][10], i, j;

    for (i = 0; i <= n; i++)
        for (j = 0; j <= m; j++)
            if (i == 0 || j == 0)
                V[i][j] = 0;
            else if (j < w[i])
                V[i][j] = V[i - 1][j];
            else
                V[i][j] = max(V[i - 1][j], p[i] + V[i - 1][j - w[i]]);
    
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
            printf("%d ", V[i][j]);
        printf("\n");
    }
    
    printf("Items included are: ");
    while (n > 0)
    {
        if (V[n][m] != V[n - 1][m])
        {
            printf("%d ", n);
            m = m - w[n];
        }
        n--;
    }
}

int main()
{
    int i;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weights of n items: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    printf("Enter the prices of n items: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    printf("Enter the capacity of Knapsack: ");
    scanf("%d", &m);
    knapsack();
    
    return 0;
}

Output:
Enter the number of items: 4
Enter the weights of 4 items: 7 3 4 5
Enter the prices of 4 items: 42 12 40 25
Enter the capacity of the knapsack: 10
0   0   0   0   0   0   0   0   0   0   0
0   0   0   0   0   0   0   42  42  42  0
0   0   0   12  12  12  12  42  42  42  0
0   0   0   12  40  40  40  52  52  52  0
0   0   0   12  40  40  40  52  52  65  65