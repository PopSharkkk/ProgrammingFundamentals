#include <stdio.h>

int triangle (int n)
{
    if (n == 1)
        return 1;
    else
        return n + triangle(n - 1);
}

int main ()
{
    int n;
    scanf("%d", &n);
    int result = triangle(n);
    printf("%d", result);

    return 0;
}
