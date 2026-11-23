#include <stdio.h>
#include <stdlib.h>

#define MAX_N 25

int N;
long long H[MAX_N];
long long memo[MAX_N];

long long llabs_val(long long val) {
    return val < 0 ? -val : val;
}

long long min_val(long long a, long long b) {
    return a < b ? a : b;
}

long long min_cost(int i) {
    if (i == N - 1) {
        return 0;
    }
    if (memo[i] != -1) {
        return memo[i];
    }

    long long cost1 = llabs_val(H[i] - H[i + 1]) + min_cost(i + 1);

    if (i + 2 < N) {
        long long cost2 = llabs_val(H[i] - H[i + 2]) + min_cost(i + 2);
        memo[i] = min_val(cost1, cost2);
    } else {
        memo[i] = cost1;
    }

    return memo[i];
}

int main(void) {
    if (scanf("%d", &N) != 1) {
        return 0;
    }

    for (int i = 0; i < N; i++) {
        scanf("%lld", &H[i]);
        memo[i] = -1;
    }

    printf("%lld\n", min_cost(0));

    return 0;
}
