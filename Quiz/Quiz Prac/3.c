#include <stdio.h>
typedef long long ll;
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int k;
    scanf("%d", &k);

    ll sum = 0;
    int target = k - 1;
    
    for (int j = 0; j < m; j++)
    {
        sum += arr[target][j];
    }

    printf("%lld", sum);
    
    return 0;
}