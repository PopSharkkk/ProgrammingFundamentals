#include <stdio.h>

int main()
{
    float berat, tinggi, bmi;
    scanf("%f %f", &berat, &tinggi);
    bmi = berat / (tinggi * tinggi);
    printf("%.2f\n", bmi);
    return 0;
}