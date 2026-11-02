#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    while (n != 0)
    {
        printf("*");
        n = n - 1;
        break;
    }
    return 0;

}
