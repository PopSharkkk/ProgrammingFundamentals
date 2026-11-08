#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 1000000

static bool is_prime[MAX_N + 1];
static int prime_pref[MAX_N + 1];

void sieve(int n) {
    for (int i = 0; i <= n; i++) {
        is_prime[i] = true;
    }
    is_prime[0] = false;
    is_prime[1] = false;

    for (int p = 2; (long long)p * p <= n; p++) {
        if (is_prime[p]) {
            for (int j = p * p; j <= n; j += p) {
                is_prime[j] = false;
            }
        }
    }

    prime_pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        prime_pref[i] = prime_pref[i - 1] + (is_prime[i] ? 1 : 0);
    }
}

int main(void) {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) {
        return 0;
    }

    sieve(n);

    for (int k = 0; k < q; k++) {
        int l, r;
        if (scanf("%d %d", &l, &r) == 2) {
            int ans = prime_pref[r] - prime_pref[l - 1];
            printf("%d\n", ans);
        }
    }

    return 0;
}
