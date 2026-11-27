#include <stdio.h>
#include <string.h>

struct Barang {
    char nama[35];
    long long harga;
    long long stok;
};

struct Barang* cariBarang(struct Barang *daftar, int n, const char *namaDicari) {
    for (int i = 0; i < n; i++) {
        if (strcmp((daftar + i)->nama, namaDicari) == 0) {
            return (daftar + i);
        }
    }
    return NULL;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Barang barang[105];
    for (int i = 0; i < n; i++) {
        if (scanf("%34s %lld %lld", barang[i].nama, &barang[i].harga, &barang[i].stok) != 3) return 0;
    }

    int q;
    if (scanf("%d", &q) != 1) return 0;

    for (int i = 0; i < q; i++) {
        char namaPesanan[35];
        long long jumlah;
        if (scanf("%34s %lld", namaPesanan, &jumlah) != 2) return 0;

        struct Barang *ptr = cariBarang(barang, n, namaPesanan);
        if (ptr == NULL) {
            printf("Barang %s tidak ditemukan\n", namaPesanan);
        } else if (ptr->stok < jumlah) {
            printf("Stok %s tidak cukup (tersisa %lld)\n", ptr->nama, ptr->stok);
        } else {
            ptr->stok -= jumlah;
            long long total = ptr->harga * jumlah;
            printf("Total bayar %s: %lld\n", ptr->nama, total);
        }
    }

    printf("Sisa stok:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %lld\n", barang[i].nama, barang[i].stok);
    }

    return 0;
}
