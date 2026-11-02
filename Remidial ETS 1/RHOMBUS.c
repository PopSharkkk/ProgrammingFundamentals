#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n + 1; i++)
    {
        printf("%d", n);
        if (n != 0)
        {
            n = n - 1;
        }

        for (int j = 0; j > n ; j--)
        {
            printf("%d", n);
        }
    }

    return 0;
}
