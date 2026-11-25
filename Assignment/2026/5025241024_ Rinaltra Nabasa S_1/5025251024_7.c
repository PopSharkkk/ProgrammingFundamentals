#include <stdio.h>

int main()
{
    const double btuperbarrel = 5800000.0;
    const double galperbarrel = 42.0;

    double gallons, effpercent;

    printf("Enter gallons of oil: ");
    scanf("%lf", &gallons);
    printf("Enter effeciency: ");
    scanf("%lf", &effpercent);

    double ef = effpercent / 100.0;

    double btupergal = btuperbarrel / galperbarrel;
    double potentialbtu = gallons * btupergal;

    double delivered_btu = potentialbtu * effpercent;

    printf("Heat delivered: %.2lf BTUs\n", delivered_btu);

    return 0;
}