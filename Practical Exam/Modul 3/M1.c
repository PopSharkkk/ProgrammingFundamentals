#include <stdio.h>

char papan[105][105];

int fpb(int a, int b) {
    if (b == 0) {
        return a;
    }
    return fpb(b, a % b);
}

void isi_ubin(int r, int c, int h, int w, int langkah) {
    if (h == 0 || w == 0) {
        return;
    }

    char huruf = 'A' + langkah;
    if (h >= w) {
        int s = w;
        int q = h / s;
        for (int i = r; i < r + q * s; i++) {
            for (int j = c; j < c + s; j++) {
                papan[i][j] = huruf;
            }
        }
        isi_ubin(r + q * s, c, h % s, w, langkah + 1);
    } else {
        int s = h;
        int q = w / s;
        for (int i = r; i < r + s; i++) {
            for (int j = c; j < c + q * s; j++) {
                papan[i][j] = huruf;
            }
        }
        isi_ubin(r, c + q * s, h, w % s, langkah + 1);
    }
}

int main() {
    int h, w;
    scanf("%d %d", &h, &w);

    isi_ubin(0, 0, h, w, 0);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%c", papan[i][j]);
        }
        printf("\n");
    }
    printf("%d\n", fpb(h, w));

    return 0;
}
