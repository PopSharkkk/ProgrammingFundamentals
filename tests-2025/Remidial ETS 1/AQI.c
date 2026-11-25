#include <stdio.h>

int main ()
{
    int pm10, pm2_5, CO;
    scanf("%d %d %d", &pm10, &pm2_5, &CO);

    if ((pm10 > 200) || (pm2_5 > 150))
    {
        printf("Sangat Tidak Sehat");
    }
    else if (CO > 12)
    {
        printf("Tidak Sehat");
    }
    else if ((pm10 >= 50 && pm10 <= 100) || (pm2_5 >=30 && pm2_5 <= 60))
    {
        printf("Sedang");
    }
    else if (pm10 < 50 && pm2_5 < 30)
    {
        printf("Baik");
    }
    else
    {
        printf("Perlu Dipantau");
    }
    return 0;
}
