#include <stdio.h>
#include <stdbool.h>

bool is_prime_rec(long long n, long long d) {
    if (d * d > n) {
        return true;
    }
    if (n % d == 0) {
        return false;
    }
    return is_prime_rec(n, d + 1);
}

bool is_prime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;
    return is_prime_rec(n, 3);
}

int main(void) {
    long long n;
    if (scanf("%lld", &n) == 1) {
        if (is_prime(n)) {
            printf("VALID\n");
        } else {
            printf("INVALID\n");
        }
    }
    return 0;
}
