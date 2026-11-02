#include <stdio.h>  
typedef long long ll;

ll sum (int n) {
    if (n == 0)
        return 0;
    return n + sum(n - 1);  
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", sum(n));
    return 0;
}