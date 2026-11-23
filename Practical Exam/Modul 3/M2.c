#include <stdio.h>
#include <stdlib.h>

int hitung_kombinasi(int sisa, int prev, int k) {
    if (sisa == 0) {
        return 1;
    }

    int hasil = 0;
    for (int d = 0; d <= 9; d++) {
        if (abs(d - prev) >= k) {
            hasil += hitung_kombinasi(sisa - 1, d, k);
        }
    }
    return hasil;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int jawab = 0;
    for (int d = 0; d <= 9; d++) {
        jawab += hitung_kombinasi(n - 1, d, k);
    }

    printf("%d\n", jawab);
    return 0;
}
