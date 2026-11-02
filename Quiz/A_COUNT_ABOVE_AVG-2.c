#include <stdio.h>


int main()
{
    int n;
    scanf("%d", &n);
    int array[n];
    int count = 0, sum = 0;
    int avg = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[n]);
        sum = sum + array[n];
    }
        avg = sum / n;

    for (int i = 0; i < n; i++)
    {
    if (array[i] > avg)
        {
            count = count + 1;
        }
    }

    printf("%d", count);

    return 0;

}
