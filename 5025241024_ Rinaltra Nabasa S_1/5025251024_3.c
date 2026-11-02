#include <stdio.h>

int main()
{
    int hours, minutes;

    printf("Enter elapsed time since power failure (hours minutes): ");
    scanf("%d %d", &hours, &minutes);

    double t = hours + (minutes / 60.0);

    double temperature = ((4.0 * t * t) / (t + 2.0)) - 20.0;

    printf("Estimated freezer temperature: %lf *C\n", temperature); // * as in the degree simbol.

    return 0;
}