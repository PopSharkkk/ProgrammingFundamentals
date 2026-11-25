#include <math.h>
#include <stdio.h>
#define ll long long

int main ()
{
    ll N;
    scanf("%lld", &N);

    ll lamps = sqrt(N);
    printf("%lld", lamps);

    return 0;
}
