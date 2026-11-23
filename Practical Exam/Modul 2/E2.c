#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        char project[1001];
        scanf("%s", &project);

        int visited[26] = {0};
        int aman = 1;

        visited[project[0] - 'A'] = 1;

        for (int i = 1; i < n; i++)
        {
            if (project[i] != project[i - 1])
            {
                if (visited[project[i] - 'A'])
                {
                    aman = 0;
                    break;
                }
                visited[project[i] - 'A'] = 1;
            }
        }

        if (aman)
        {
            printf("AMAN\n");
        }
        else
        {
            printf("SKORS\n");
        }
    }

    return 0;
}
