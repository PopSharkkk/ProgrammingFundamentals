#include <stdio.h>
#define ll long long

int main ()
{
    ll N, M;
    ll lineN[100], lineM[100];

    scanf("%lld %lld", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%lld", &lineN[i]);
    }
    for (int j = 0; j < M; j++) {
        scanf("%lld", &lineM[j]);
    }

    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        ll same = 0;
        for (int j = 0; j < M; j++)
        {
            if (lineN[i] == lineM[j])
            {
                same = 1;
                break;
            }

        }
        if (!same)
        {
            sum += lineN[i];
        }
    }
        printf("%lld", sum);
        return 0;

}
