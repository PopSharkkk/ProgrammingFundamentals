#include <stdio.h>

int kupon[100005];

int batasBawah(int *arr, int n, int x) {
    int kiri = 0, kanan = n;
    while (kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        if (arr[tengah] < x) {
            kiri = tengah + 1;
        } else {
            kanan = tengah;
        }
    }
    return kiri;
}

int batasAtas(int *arr, int n, int x) {
    int kiri = 0, kanan = n;
    while (kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        if (arr[tengah] <= x) {
            kiri = tengah + 1;
        } else {
            kanan = tengah;
        }
    }
    return kiri;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &kupon[i]) != 1) return 0;
    }

    int q;
    if (scanf("%d", &q) != 1) return 0;

    for (int i = 0; i < q; i++) {
        int x;
        if (scanf("%d", &x) != 1) return 0;
        int jumlah = batasAtas(kupon, n, x) - batasBawah(kupon, n, x);
        printf("%d\n", jumlah);
    }

    return 0;
}
