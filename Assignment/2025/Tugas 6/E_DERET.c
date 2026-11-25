#include <stdio.h>

int hitung_deret_segitiga(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return hitung_deret_segitiga(n - 1) + n;
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("%d\n", hitung_deret_segitiga(n));

    return 0;
}