#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d" , &arr[i]);
    }
    int ans; 
    scanf ("%d", &ans);

    int first = 0, last = n-1, middle, found = -1;

    while (first <= last)
    {
        middle =  (first + last) / 2;
        if (arr[middle] == ans)
        {
            printf("%d", middle);
            break;
        }
        else if (arr[middle] < ans )
        { 
            first = middle + 1;
        }
        else 
        {
            last = middle - 1;
        }
    }   

    return 0;

    

}
