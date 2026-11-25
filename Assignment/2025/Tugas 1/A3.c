#include <stdio.h>

int main()
{

    float tempC, tempF;
    scanf("%f", &tempC);
    tempF = (tempC * 9 / 5) + 32;
    printf("%.2f\n", tempF);

    return 0;
}