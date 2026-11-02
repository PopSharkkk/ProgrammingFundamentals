#include <stdio.h>

int main()
{
    int bilangan;

    scanf("%d", &bilangan);

    if (bilangan > 0)
    {
        printf("Positif\n");
    }
    else if (bilangan < 0)
    {
        printf("Negatif\n");
    }
    else
    {
        printf("Nol\n");
    }

    return 0;
}