#include <stdio.h>

int countEven (int *arr, int n)
{
    int x;
    int *p = arr;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", *(arr + i));
    }
}

int main ()
{
    int n;
    int *arr;
    countEven(arr, n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (*arr % 2 == 0)
        {
            count = count + 1;
        }


    }
       printf("%d,", count);
}
