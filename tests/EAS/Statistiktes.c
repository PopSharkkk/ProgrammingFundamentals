#include <stdio.h>

int main ()
{
    int n; scanf("%d", &n);
    int min, max, sum = 0, arr[n];
    float average;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }

    average = sum / n;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            max = arr[i];
        }
        if (arr[i + 1] > arr[i])
        {
            min = arr[i];
        }
    }
    printf("%d\n%d\n%.2f", max, min, average);
}
