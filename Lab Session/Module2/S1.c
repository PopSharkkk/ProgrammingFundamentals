#include <stdio.h>

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);

    char input[105][105];

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            scanf(" %c", &input[i][j]);
        }
    }

    int R, C;
    scanf("%d %d", &R, &C);


    R--;
    C--;

    int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int k = 0; k < 8; k++)
    {
        int nr = R + dr[k];
        int nc = C + dc[k];


        if (nr >= 0 && nr < x && nc >= 0 && nc < y)
        {
            if (input[nr][nc] != 'x')
            {
                printf("no\n");
                return 0;
            }
        }
    }

    printf("yes\n");

    return 0;
}
