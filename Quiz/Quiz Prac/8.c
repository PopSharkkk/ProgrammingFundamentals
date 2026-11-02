#include <stdio.h>

int search(int arr[], int low, int high, int x, int n)
{
    if (low > high)
        return 0;
    int mid = (low + high) / 2;
    if (arr[mid] == x)
    {
        int count = 1;
        int i = mid - 1;
        while (i >= 0 && arr[i] == x)
        {
            count++;
            i--;
        }
        i = mid + 1;
        while (i < n && arr[i] == x)
        {
            count++;
            i++;
        }
        return count;
    }
    else if (x < arr[mid])
    {
        return search(arr, low, mid - 1, x, n);
    }
    else
    {
        return search(arr, mid + 1, high, x, n);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int x;
    scanf("%d", &x);
    printf("%d\n", search(arr, 0, n - 1, x, n));
    return 0;
}

