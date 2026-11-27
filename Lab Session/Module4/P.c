#include <stdio.h>

int rak[1005][1005];

void cariBuku(int n, int m, int target, int *baris, int *kolom) {
    int r = 0, c = m - 1;
    while (r < n && c >= 0) {
        if (rak[r][c] == target) {
            *baris = r + 1;
            *kolom = c + 1;
            return;
        } else if (rak[r][c] > target) {
            c--;
        } else {
            r++;
        }
    }
    *baris = -1;
    *kolom = -1;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%d", &rak[i][j]) != 1) return 0;
        }
    }

    int q;
    if (scanf("%d", &q) != 1) return 0;

    for (int i = 0; i < q; i++) {
        int x;
        if (scanf("%d", &x) != 1) return 0;

        int baris, kolom;
        cariBuku(n, m, x, &baris, &kolom);

        if (baris == -1) {
            printf("-1\n");
        } else {
            printf("%d %d\n", baris, kolom);
        }
    }

    return 0;
}
