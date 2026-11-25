#include <stdio.h>

int main()
{
    int N;

    if (scanf("%d", &N) != 1)
    {
        return 1;
    }

    int arr[100];
    int max_val, min_val;

    for (int i = 0; i < N; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            return 1;
        }

        if (i == 0)
        {
            max_val = arr[i];
            min_val = arr[i];
        }
        else
        {
            if (arr[i] > max_val)
            {
                max_val = arr[i];
            }
            if (arr[i] < min_val)
            {
                min_val = arr[i];
            }
        }
    }

    int selisih = max_val - min_val;

    printf("%d\n", selisih);

    return 0;
}