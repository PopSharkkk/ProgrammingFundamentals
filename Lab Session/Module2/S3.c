#include <stdio.h>

int main () {
    int N;
    scanf("%d", &N);

    int max1 = 0;
    int count1 = 0;

    while (N > 0)
    {
        if (N & 1)
        {
            count1++;
            if (count1 > max1)
            {
                max1 = count1;
            }
        }
        else
        {
            count1 = 0;
        }
        N = N >> 1;
    }
    printf("%d\n", max1);
    return 0;
    
}