#include <stdio.h>

int hitung_cara(int n) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }
    return hitung_cara(n - 1) + hitung_cara(n - 2) + hitung_cara(n - 3);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", hitung_cara(n));
    return 0;
}
