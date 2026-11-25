#include <stdio.h>

int main()
{
    int n, div = 0, total = 0;
    scanf("%d", &n);
    while (n != -999)
    {
        div += 1;
        total += n;
        scanf("%d", &n);
    }
    float res = (div == 0) ? 0.0f : (float)total / div;
    printf("%.2f\n", res);

    return 0;
}
