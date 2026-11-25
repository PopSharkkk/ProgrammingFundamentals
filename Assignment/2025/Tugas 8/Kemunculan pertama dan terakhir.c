#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int searchfirst(int arr[], int low, int high, int x)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == x)
    {
        if (mid == 0 || arr[mid - 1] != x)
        {
            return mid;
        }
        else
        {
            return searchfirst(arr, low, mid - 1, x);
        }
    }
    else if (x < arr[mid])
    {
        return searchfirst(arr, low, mid - 1, x);
    }
    else
    {
        return searchfirst(arr, mid + 1, high, x);
    }
    return -1;
}
int searchlast(int arr[], int low, int high, int x, int n)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == x)
    {
        if (mid == n - 1 || arr[mid + 1] != x)
        {
            return mid;
        }
        else
        {
            return searchlast(arr, mid + 1, high, x, n);
        }
    }
    else if (x < arr[mid])
    {
        return searchlast(arr, low, mid - 1, x, n);
    }
    else
    {
        return searchlast(arr, mid + 1, high, x, n);
    }
    return -1;
}

int main () {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int ans;
    scanf("%d", &ans);
    printf("%d %d\n", searchfirst(arr, 0, n - 1, ans), searchlast(arr, 0, n - 1, ans, n));
    return 0;   
}