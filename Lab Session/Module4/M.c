#include <stdio.h>
#include <string.h>

struct Buku {
    char judul[25];
};

int linearSearch(struct Buku *rak, int n, const char *cari) {
    for (int i = 0; i < n; i++) {
        if (strcmp((rak + i)->judul, cari) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Buku rak[105];
    for (int i = 0; i < n; i++) {
        if (scanf("%24s", rak[i].judul) != 1) return 0;
    }

    char cari[25];
    if (scanf("%24s", cari) != 1) return 0;

    printf("%d\n", linearSearch(rak, n, cari));

    return 0;
}
