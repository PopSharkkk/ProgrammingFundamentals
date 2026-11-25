#include <stdio.h>

int main()
{
    long long a, b, c, p, q, r;
    scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &p, &q, &r);

    long long D = a * q - b * p;

    if (D != 0)
    {
        double x = (double)(c * q - b * r) / D;
        double y = (double)(a * r - c * p) / D;

        if (x == -0.0)
            x = 0.0;
        if (y == -0.0)
            y = 0.0;

        printf("SATU SOLUSI\n");
        printf("%.2f %.2f\n", x, y);
    }
    else
    {
        if (a * r == c * p && b * r == c * q)
            printf("BANYAK SOLUSI\n");
        else
            printf("TIDAK ADA SOLUSI\n");
    }

    return 0;
}