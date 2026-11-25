#include <stdio.h>

int main () {
    int A, B;
    scanf("%d %d", &A, &B);

    int x = A ^ B;
    int count = 0;

    while (x > 0) {
        count += x & 1;
        x >>= 1;
    }

    printf("%d\n", count);
    return 0;

}