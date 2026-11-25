#include <stdio.h>
#include <math.h>

int main()
{
    int M, B;
    scanf("%d %d", &M, &B);

    int different = (M + B - abs(M - B)) / 2;
    int same = abs(M - B) / 2;

    printf("%d %d\n", different, same);
    return 0;
}