#include <stdio.h>

long long mirror_A(long long x) {
    if (x < 0) {
        return x + 6;
    } else if (x <= 9) {
        return 2 * x + 1;
    } else {
        return x - 8;
    }
}

long long mirror_B(long long x) {
    if (x < 0) {
        return -x;
    } else if (x <= 9) {
        return x + 4;
    } else {
        return x / 2; // floor division for non-negative integers; if negative handled above
    }
}

long long simulate_mirrors(long long x, int step, int k) {
    if (step > k) {
        return x;
    }
    if (step % 2 == 1) {
        return simulate_mirrors(mirror_A(x), step + 1, k);
    } else {
        return simulate_mirrors(mirror_B(x), step + 1, k);
    }
}

int main(void) {
    long long x;
    int k;
    if (scanf("%lld %d", &x, &k) == 2) {
        printf("%lld\n", simulate_mirrors(x, 1, k));
    }
    return 0;
}
