#include <stdio.h>

void tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int tinggi[1005];
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &tinggi[i]) != 1) return 0;
    }

    int pertukaran = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (tinggi[j] > tinggi[j + 1]) {
                tukar(&tinggi[j], &tinggi[j + 1]);
                pertukaran++;
            }
        }
    }

    printf("%d\n", pertukaran);

    return 0;
}
