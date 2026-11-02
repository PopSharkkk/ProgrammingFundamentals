#include <stdio.h>
#include <stdlib.h>

int upper(int arr[], int ans, int left, int right, int n)
{   
    int middle = (right + left) / 2;

    if (arr[n - 1] <= ans) return -1;
    if (left == right) return arr[left];
    if (arr[middle] <= ans) return upper(arr, ans, middle + 1, right, n);
    return upper(arr, ans, middle + 1, left, n);
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
    printf("%d\n", upper(arr, ans, 0, n - 1, n));
    return 0;
}