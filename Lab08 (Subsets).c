// Design and implement C/C++ program to find a subset of a given set S={S1, S2, ..., Sn} 
// of n positive integers whose sum is equal to a given positive integer d.

#include <stdio.h>

#define MAX 10

int s[MAX], x[MAX], d, count;

void sumofsub(int p, int k, int r)
{
    int i;
    x[k] = 1;
    if ((p + s[k]) == d)
    {
        printf("subset = %d\n", ++count);
        for (i = 0; i <= k; i++)
            if (x[i] == 1)
                printf("%d ", s[i]);
        printf("\n");
    }
    else if (p + s[k] + s[k + 1] <= d)
        sumofsub(p + s[k], k + 1, r - s[k]);
    if ((p + r - s[k] >= d) && (p + s[k + 1] <= d))
    {
        x[k] = 0;
        sumofsub(p, k + 1, r - s[k]);
    }
}

int main()
{
    int n, sum = 0;
    printf("\nEnter the n value:");
    scanf("%d", &n);
    printf("\nEnter the set in increasing order:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
        sum = sum + s[i];
    }

    printf("Enter the sum :");
    scanf("%d", &d);
    if ((sum < d) || s[0] > d)
        printf("No Subset possible\n");
    else
        sumofsub(0, 0, sum);
}

// Output:
// Enter the number of elements: 5
// Enter the elements in increasing order: 1 2 3 4 5
// Enter the sum: 10
// Subset=1
// 1 2 3 4
// Subset=2
// 1 4 5
// Subset=3
// 2 3 5