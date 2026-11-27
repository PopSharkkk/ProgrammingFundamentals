#include <stdio.h>

struct Pasien {
    char nama[25];
    int level;
};

void tukar(struct Pasien *a, struct Pasien *b) {
    struct Pasien temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Pasien p[1005];
    for (int i = 0; i < n; i++) {
        if (scanf("%24s %d", p[i].nama, &p[i].level) != 2) return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (p[j].level > p[j + 1].level) {
                tukar(&p[j], &p[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", p[i].nama);
    }

    return 0;
}
