#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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
    int answer = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == ans) {
            answer = i;
        }
    }
    printf("%d", ans);
    return 0;
    
}
