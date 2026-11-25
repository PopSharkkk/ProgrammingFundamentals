#include <stdio.h>
#include <string.h>

/*
 * Message Trace
 * Melacak penerus pesan dan penerima akhir menggunakan struct dan pointer.
 */

struct Orang {
    char nama[21];
    struct Orang *penerus; /* NULL jika tidak meneruskan pesan */
};

struct PenerimaAkhir {
    char nama[21];
    int sumbangan;
};

/* Mencari alamat Orang berdasarkan nama */
struct Orang* cariOrang(struct Orang *daftar, int n, const char *nama) {
    for (int i = 0; i < n; i++) {
        if (strcmp((daftar + i)->nama, nama) == 0) {
            return (daftar + i);
        }
    }
    return NULL;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Orang daftar[1005];
    char namaTujuan[1005][25];

    /* Baca semua orang dan nama penerusnya */
    for (int i = 0; i < n; i++) {
        scanf("%s %s", daftar[i].nama, namaTujuan[i]);
        daftar[i].penerus = NULL;
    }

    /* Hubungkan pointer penerus */
    for (int i = 0; i < n; i++) {
        if (strcmp(namaTujuan[i], "-") != 0) {
            daftar[i].penerus = cariOrang(daftar, n, namaTujuan[i]);
        }
    }

    struct PenerimaAkhir akhir[1005];
    int jumlahAkhir = 0;

    /* 1. Telusuri penerima akhir dan banyak penerusan untuk setiap orang */
    for (int i = 0; i < n; i++) {
        struct Orang *curr = &daftar[i];
        int forwards = 0;
        while (curr->penerus != NULL) {
            curr = curr->penerus;
            forwards++;
        }

        printf("%s %s %d\n", daftar[i].nama, curr->nama, forwards);

        /* Catat sumbangan ke penerima akhir */
        int found = 0;
        for (int k = 0; k < jumlahAkhir; k++) {
            if (strcmp(akhir[k].nama, curr->nama) == 0) {
                akhir[k].sumbangan++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(akhir[jumlahAkhir].nama, curr->nama);
            akhir[jumlahAkhir].sumbangan = 1;
            jumlahAkhir++;
        }
    }

    /* 2. Urutkan peringkat penerima akhir:
          - Sumbangan terbanyak di posisi atas
          - Jika sumbangan sama, urutkan berdasarkan nama ASCII (A-Z)
    */
    for (int i = 0; i < jumlahAkhir - 1; i++) {
        for (int j = 0; j < jumlahAkhir - 1 - i; j++) {
            int tukar = 0;
            if (akhir[j].sumbangan < akhir[j + 1].sumbangan) {
                tukar = 1;
            } else if (akhir[j].sumbangan == akhir[j + 1].sumbangan) {
                if (strcmp(akhir[j].nama, akhir[j + 1].nama) > 0) {
                    tukar = 1;
                }
            }
            if (tukar) {
                struct PenerimaAkhir temp = akhir[j];
                akhir[j] = akhir[j + 1];
                akhir[j + 1] = temp;
            }
        }
    }

    /* Cetak peringkat */
    printf("Peringkat:\n");
    for (int i = 0; i < jumlahAkhir; i++) {
        printf("%s %d\n", akhir[i].nama, akhir[i].sumbangan);
    }

    return 0;
}
