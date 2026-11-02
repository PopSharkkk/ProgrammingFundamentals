#include <stdio.h>
typedef long long ll;

ll deret (int n) {
    if (n == 1)
    return 1;
    return deret(n - 1) + n;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%lld\n", deret(n));

    return 0;
}