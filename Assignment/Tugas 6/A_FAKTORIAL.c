#include <stdio.h>

long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) {
        return 0;
    }
    printf("%lld\n", factorial(N));
    return 0;
}