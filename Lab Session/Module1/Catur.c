#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[3], b[3];
    scanf("%s %s", a, b);

    int dx = abs(a[0] - b[0]);
    int dy = abs(a[1] - b[1]);

    int ada = 0;

    if ((dx == 1 && dy == 2) || (dx == 2 && dy == 1))
    {
        printf("KUDA");
        ada = 1;
    }

    if ((dx == 0 || dy == 0) && (dx != 0 || dy != 0))
    {
        if (ada)
            printf(" ");
        printf("BENTENG");
        ada = 1;
    }

    if (dx == dy && dx != 0)
    {
        if (ada)
            printf(" ");
        printf("GAJAH");
        ada = 1;
    }

    if (((dx == 0 || dy == 0) || (dx == dy)) && (dx != 0 || dy != 0))
    {
        if (ada)
            printf(" ");
        printf("RATU");
        ada = 1;
    }

    if (ada == 0)
    {
        printf("TIDAK ADA");
    }

    return 0;
}