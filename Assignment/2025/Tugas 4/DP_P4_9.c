#include <stdio.h>

int main()
{
    int rows = 3;
    int cols = 2;
    int matrix[3][2];
    int transpose[2][3];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
            {
                return 1;
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%d", transpose[i][j]);
            if (j < rows - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}