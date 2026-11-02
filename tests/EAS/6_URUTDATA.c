#include <stdio.h>

int bubbleSort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[j];
        while (j > key && arr[j] > key)
        {
            key = arr [j - 1];
        }
    }
    return 0;
}

int main ()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d", bubbleSort(arr, n));
    }

    return 0;
}
