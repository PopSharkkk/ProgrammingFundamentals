#include <stdio.h>
#define ll long long
int main() {
    ll n;
    scanf("%lld", &n);

    ll a = n / 3;
    ll b = n / 5;
    ll c = n / 15;

	ll result = (3 * a * (a + 1) / 2) + (5 * b * (b + 1) / 2) - (15 * c * (c + 1) / 2);

	printf("%lld\n", result);

    return 0;
}