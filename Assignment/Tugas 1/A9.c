#include <stdio.h>

int main()
{
    float gajipokok, pajak, tunjangan, gajibersih;
    scanf("%f", &gajipokok);
    tunjangan = 0.2 * gajipokok;
    pajak = 0.1 * (gajipokok + tunjangan);
    gajibersih = gajipokok + tunjangan - pajak;

    printf("%.2f\n", gajibersih);
    return 0;
}