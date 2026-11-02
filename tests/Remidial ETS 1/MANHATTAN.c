#include <stdio.h>
#include <math.h>

int main ()
{
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    int dis1 = fabs(x1 - x2);
    int dis2 = fabs(y1 - y2);
    int dis = dis1 + dis2;
    printf("%d", dis);
    return 0;
}
