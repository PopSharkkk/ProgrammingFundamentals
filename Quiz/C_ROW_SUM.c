#include <stdio.h>

int main ()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int grid[n][m];
    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &grid[n][m]);

        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            printf("%d", grid[n][m]);

        }

    }
    return 0;
}
