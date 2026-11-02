#include <stdio.h>

typedef long long ll;

ll MAX(ll A[], ll n, ll i) {
    if (i == n - 1){
        return A[i];
    }
    return (A[i] > MAX(A, n, i + 1)) ? A[i] : MAX(A, n, i + 1);
}

void read(ll A[], ll n, ll i) {
    if (i == n) {
        return;
    }
    scanf("%lld", &A[i]);
    read(A, n, i + 1);
}
int main() {
    ll n;
    scanf("%lld", &n);

    ll A[n];
    read(A, n, 0);

    printf("%lld\n", MAX(A, n, 0));

    return 0;
}