#include <stdio.h>
#include <stdlib.h>

int **buatMatriks(int baris, int kolom) {
    int **m = (int **)malloc(baris * sizeof(int *));
    for (int i = 0; i < baris; i++) {
        m[i] = (int *)malloc(kolom * sizeof(int));
    }
    return m;
}

void hapusMatriks(int **m, int baris) {
    for (int i = 0; i < baris; i++) {
        free(m[i]);
    }
    free(m);
}

int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2) return 0;

    int **peta = buatMatriks(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (scanf("%d", &peta[i][j]) != 1) return 0;
        }
    }

    int **hasil = buatMatriks(c, r);
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            hasil[i][j] = peta[r - 1 - j][i];
        }
    }

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            printf("%d%c", hasil[i][j], (j == r - 1) ? '\n' : ' ');
        }
    }

    hapusMatriks(peta, r);
    hapusMatriks(hasil, c);

    return 0;
}
