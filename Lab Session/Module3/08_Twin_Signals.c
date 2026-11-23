#include <stdio.h>

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main(void) {
    long long a, b;
    if (scanf("%lld %lld", &a, &b) == 2) {
        long long g = gcd(a, b);
        long long lcm = (a / g) * b;
        printf("%lld %lld\n", g, lcm);
    }
    return 0;
}
