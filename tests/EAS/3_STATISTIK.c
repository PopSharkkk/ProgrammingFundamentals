#include <stdio.h>

int min;
int max;

int main ()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    float avg;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            max = arr[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            min = arr[i + 1];
        }

    }
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    avg = sum / n;

    printf("%d\n", max);
    printf("%d\n", min);
    printf("%.2f", avg);

}
