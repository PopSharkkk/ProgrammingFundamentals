#include <stdio.h>

int main()
{
    int second, minute, hour;
    scanf("%d", &second);

    hour = second / 3600;
    minute = (second % 3600) / 60;
    second = second % 60;
    printf("%d %d %d\n", hour, minute, second);
    return 0;
}