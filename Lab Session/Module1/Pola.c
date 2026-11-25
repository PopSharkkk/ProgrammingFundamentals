#include <stdio.h>

int main() {
    long long T, N, ans;

    scanf("%lld %lld", &T, &N);

    switch (T) {
        case 1:
            ans = N * N;
            printf("%lld\n", ans);
            break;

        case 2:
            ans = N * (N + 1);
            printf("%lld\n", ans);
            break;

        case 3:
            ans = N * (N + 1) * (2 * N + 1) / 6;
            printf("%lld\n", ans);
            break;

        case 4:
            ans = (N * (N + 1) / 2);
            ans *= ans;
            printf("%lld\n", ans);
            break;

        default:
            printf("MODE TIDAK VALID\n");
    }

    return 0;
}
