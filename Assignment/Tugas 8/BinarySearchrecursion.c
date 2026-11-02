#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int binarySearch(int arr[], int first, int last, int target)
{
    if (first > last)
    {
        return -1; // if not found
    }

    int middle = (first + last) / 2;

    if (arr[middle] == target)
    {
        return middle;
    }
    else if (arr[middle] < target)
    {
        return binarySearch(arr, middle + 1, last, target);
    }
    else
    {
        return binarySearch(arr, first, middle - 1, target);
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

    int ans;
    scanf("%d", &ans);

    int result = binarySearch(arr, 0, n - 1, ans);

    printf("%d\n", result);

    return 0;
}
