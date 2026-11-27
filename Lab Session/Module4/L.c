#include <stdio.h>
#include <string.h>

struct Kartu {
    char angka[15];
};

void tukar(struct Kartu *a, struct Kartu *b) {
    struct Kartu temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Kartu k[105];
    for (int i = 0; i < n; i++) {
        if (scanf("%14s", k[i].angka) != 1) return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            char ab[35], ba[35];
            strcpy(ab, k[j].angka);
            strcat(ab, k[j + 1].angka);

            strcpy(ba, k[j + 1].angka);
            strcat(ba, k[j].angka);

            if (strcmp(ab, ba) < 0) {
                tukar(&k[j], &k[j + 1]);
            }
        }
    }

    if (k[0].angka[0] == '0') {
        printf("0\n");
    } else {
        for (int i = 0; i < n; i++) {
            printf("%s", k[i].angka);
        }
        printf("\n");
    }

    return 0;
}
