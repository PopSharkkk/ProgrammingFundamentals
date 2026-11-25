#include <stdio.h>

long long sum (int n) {
    if (n <= 1) {
        return 1;
    }
    return n + sum(n - 1);
}

int main (void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }
    printf("%lld\n", sum(n));
    return 0;
}