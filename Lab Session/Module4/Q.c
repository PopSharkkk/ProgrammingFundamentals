#include <stdio.h>

long long akarBulat(long long x) {
    long long kiri = 0, kanan = 1000000000LL;
    long long hasil = 0;

    while (kiri <= kanan) {
        long long tengah = kiri + (kanan - kiri) / 2;
        if (tengah * tengah <= x) {
            hasil = tengah;
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }

    return hasil;
}

int main() {
    int q;
    if (scanf("%d", &q) != 1) return 0;

    for (int i = 0; i < q; i++) {
        long long x;
        if (scanf("%lld", &x) != 1) return 0;
        printf("%lld\n", akarBulat(x));
    }

    return 0;
}
