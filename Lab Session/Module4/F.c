#include <stdio.h>

void tukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int skor[105];
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &skor[i]) != 1) return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (skor[j] < skor[j + 1]) {
                tukar(&skor[j], &skor[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d%c", skor[i], (i == n - 1) ? '\n' : ' ');
    }

    return 0;
}
