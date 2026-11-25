#include <stdio.h>

int main()
{
    int n, i, delta;
    scanf("%d %d", &n, &i);
    delta = abs(n - i);
    printf("%d\n", delta);
    return 0;
}