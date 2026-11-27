#include <stdio.h>

void hitung(long long a, long long b, long long *jumlah, long long *selisih, long long *kali) {
    *jumlah = a + b;

    if (a >= b) {
        *selisih = a - b;
    } else {
        *selisih = b - a;
    }

    *kali = a * b;
}

int main() {
    long long a, b;
    if (scanf("%lld %lld", &a, &b) != 2) return 0;

    long long jumlah, selisih, kali;
    hitung(a, b, &jumlah, &selisih, &kali);

    printf("Jumlah: %lld\n", jumlah);
    printf("Selisih: %lld\n", selisih);
    printf("Kali: %lld\n", kali);

    return 0;
}
