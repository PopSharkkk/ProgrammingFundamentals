#include <stdio.h>

unsigned long long factorial(int n) {
    if (n <= 1) {
        return 1ULL;
    }
    return (unsigned long long)n * factorial(n - 1);
}

int main(void) {
    int n;
    if (scanf("%d", &n) == 1) {
        printf("%llu\n", factorial(n));
    }
    return 0;
}
