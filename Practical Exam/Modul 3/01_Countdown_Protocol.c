#include <stdio.h>

void countdown(int n) {
    if (n < 1) {
        printf("GO\n");
        return;
    }
    if (n % 3 == 0 && n % 5 == 0) {
        printf("BIPBOP\n");
    } else if (n % 3 == 0) {
        printf("BIP\n");
    } else if (n % 5 == 0) {
        printf("BOP\n");
    } else {
        printf("%d\n", n);
    }
    countdown(n - 1);
}

int main(void) {
    int n;
    if (scanf("%d", &n) == 1) {
        countdown(n);
    }
    return 0;
}
