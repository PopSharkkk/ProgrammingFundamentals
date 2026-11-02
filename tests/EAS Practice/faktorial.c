#include <stdio.h>
typedef long long ll;

ll faktorial (int n) {
    if (n == 0)
        return 1;
    return n * faktorial(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", faktorial(n));
    return 0;
}