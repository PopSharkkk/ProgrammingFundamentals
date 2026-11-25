#include <stdio.h>

int main()
{
    // int i, end;

    // printf("Enter starting value for i: ");
    // scanf("%d", &i);

    // printf("Enter ending value: ");
    // scanf("%d", &end);

    // // Loop from i to end
    // for (; i <= end; i++)
    // {
    //     printf("%d\n", i);
    // }

    // return 0;

    int i;
    for (i = 1; i <= 10; i++)
    {
        if (i % 2 != 0)
        {
            continue; // Skip odd numbers
        }
        printf("Hello World! %d\n", i);
    }
}