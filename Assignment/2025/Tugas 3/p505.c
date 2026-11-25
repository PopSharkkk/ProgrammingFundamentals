
#include <stdio.h>

int main()
{
    int n = -1;
    while (n < 1 || n > 10){
        scanf("%d", &n);
    }

    printf("%d", n);
}
