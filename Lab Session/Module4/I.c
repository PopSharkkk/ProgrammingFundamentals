#include <stdio.h>

struct Driver {
    char nama[25];
    double jarak;
    double rating;
};

void tukar(struct Driver *a, struct Driver *b) {
    struct Driver temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Driver d[105];
    for (int i = 0; i < n; i++) {
        if (scanf("%24s %lf %lf", d[i].nama, &d[i].jarak, &d[i].rating) != 3) return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            double selisih = d[j].jarak - d[j + 1].jarak;
            if (selisih < 0) selisih = -selisih;

            int harusTukar = 0;
            if (selisih < 1e-9) {
                if (d[j].rating < d[j + 1].rating) {
                    harusTukar = 1;
                }
            } else if (d[j].jarak > d[j + 1].jarak) {
                harusTukar = 1;
            }

            if (harusTukar) {
                tukar(&d[j], &d[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", d[i].nama);
    }

    return 0;
}
