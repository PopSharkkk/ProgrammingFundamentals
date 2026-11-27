#include <stdio.h>
#include <string.h>

struct Kata {
    char asli[25];
    char terbalik[25];
};

void balikKata(const char *sumber, char *tujuan) {
    int len = strlen(sumber);
    for (int i = 0; i < len; i++) {
        tujuan[i] = sumber[len - 1 - i];
    }
    tujuan[len] = '\0';
}

void tukar(struct Kata *a, struct Kata *b) {
    struct Kata temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Kata k[105];
    for (int i = 0; i < n; i++) {
        if (scanf("%24s", k[i].asli) != 1) return 0;
        balikKata(k[i].asli, k[i].terbalik);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (strcmp(k[j].terbalik, k[j + 1].terbalik) > 0) {
                tukar(&k[j], &k[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", k[i].asli);
    }

    return 0;
}
