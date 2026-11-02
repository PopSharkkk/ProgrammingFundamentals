#include <stdio.h>
#include <math.h>


int main(void) {
    double T, a;


    printf("Masukkan suhu dalam Fahrenheit: ");
    scanf("%lf", &T);
    a = 1086.0 * sqrt((5.0 * T + 297.0) / 247.0);

    printf("Kecepatan suara pada suhu %.2lf F adalah %.4lf ft/sec\n", T, a);

    return 0;
}