#include <stdio.h>
#define ll long long

int main()
{
    ll a, b, R;
    ll m, c;

    scanf("%lld %lld %lld", &a, &b, &R);
    scanf("%lld %lld", &m, &c);

    ll denominator = (m * a) - b + c;
    ll numerator = denominator * denominator;
    ll comparator = R * (1 + (m * m));

    if (numerator < comparator)
    {
        printf("We're cooked.\n");
    }
    else if (numerator == comparator)
    {
        printf("Kegores dikit ga ngaruh.\n");
    }
    else
    {
        printf("We're so back.\n");
    }

    return 0;
}

