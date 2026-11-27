#include <stdio.h>

void balik(int *awal, int *akhir) {
    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int arr[1005];
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) return 0;
    }

    for (int i = 0; i < n; i += k) {
        int akhir_idx = i + k - 1;
        if (akhir_idx >= n) {
            akhir_idx = n - 1;
        }
        balik(&arr[i], &arr[akhir_idx]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d%c", arr[i], (i == n - 1) ? '\n' : ' ');
    }

    return 0;
}
