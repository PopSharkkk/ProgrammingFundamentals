#include <stdio.h>

void perjalanan(int n) {
    if (n == 1) {
        printf("1 odd\n");
        return;
    }

    if (n % 2 == 0) {
        perjalanan(n / 2);
        printf("%d even\n", n);
    } else {
        perjalanan(3 * n + 1);
        printf("%d odd\n", n);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    perjalanan(n);
    return 0;
}
