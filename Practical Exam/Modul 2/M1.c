#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char msg[2001];

    scanf("%d", &n);
    scanf("%s", msg);

    int bestmincharacter = -1;
    int bestobstruct = 2000001;

    for (int nomor = 1; nomor <= n; nomor++)
    {
        char obsmsg[2001];
        scanf("%s", obsmsg);

        int j = 0;

        // cek apakah msg adalah subsequence dari obsmsg
        for (int i = 0; obsmsg[i] != '\0'; i++)
        {
            if (obsmsg[i] == msg[j])
            {
                j++;
            }
        }

        // jika seluruh karakter msg ditemukan
        if (msg[j] == '\0')
        {
            int obstruct = strlen(obsmsg) - strlen(msg);

            if (obstruct < bestobstruct)
            {
                bestobstruct = obstruct;
                bestmincharacter = nomor;
            }
        }
    }

    printf("%d\n", bestmincharacter);

    return 0;
}