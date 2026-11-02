#include <stdio.h>

int main()
{
    int n, total = 0;
    scanf("%d", &n);
    int temp[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", temp[n]);
        total =+ temp[n];
    }
    for (int i = 0; i < temp[n]; i++)
    {
        if (temp[n] > (total / n))
        {
            printf("%d", temp[n]);
        }
    }
    return 0;
}
