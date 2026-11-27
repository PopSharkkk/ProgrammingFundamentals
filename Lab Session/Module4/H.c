#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int freq[101] = {0};
    for (int i = 0; i < n; i++) {
        int nilai;
        if (scanf("%d", &nilai) != 1) return 0;
        freq[nilai]++;
    }

    for (int i = 100; i >= 0; i--) {
        if (freq[i] > 0) {
            printf("%d %d\n", i, freq[i]);
        }
    }

    return 0;
}
