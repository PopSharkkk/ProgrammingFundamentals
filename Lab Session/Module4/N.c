#include <stdio.h>

int loker[100005];

int binarySearch(int *arr, int n, int target) {
    int kiri = 0, kanan = n - 1;
    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        if (arr[tengah] == target) {
            return tengah;
        } else if (arr[tengah] < target) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &loker[i]) != 1) return 0;
    }

    int q;
    if (scanf("%d", &q) != 1) return 0;

    for (int i = 0; i < q; i++) {
        int cari;
        if (scanf("%d", &cari) != 1) return 0;
        printf("%d\n", binarySearch(loker, n, cari));
    }

    return 0;
}
