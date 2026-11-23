#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int rates[105];
    int weights[2005];
    int slot[105];
    int parkir[2005];
    int antre[2005];

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &rates[i]);
        slot[i] = 1; // slot kosong
    }

    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &weights[i]);
        parkir[i] = -1; // belum parkir
    }

    long long ans = 0;

    int depan = 0;
    int belakang = 0;

    for (int i = 1; i <= 2 * m; i++)
    {
        int x;
        scanf("%d", &x);

        if (x > 0) // robot datang
        {
            int found = -1;

            for (int j = 1; j <= n; j++)
            {
                if (slot[j] == 1)
                {
                    found = j;
                    break;
                }
            }

            if (found != -1)
            {
                slot[found] = 0;
                parkir[x] = found;

                ans += (long long) rates[found] * weights[x];
            }
            else
            {
                antre[belakang++] = x;
            }
        }
        else // robot keluar
        {
            int robot = -x;
            int slot_dipakai = parkir[robot];

            parkir[robot] = -1;

            if (depan < belakang)
            {
                int next_robot = antre[depan++];

                parkir[next_robot] = slot_dipakai;

                ans += (long long) rates[slot_dipakai] * weights[next_robot];
            }
            else
            {
                slot[slot_dipakai] = 1;
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}