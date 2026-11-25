#include <stdio.h>

int main()
{
    int day, price = 0;

    scanf("%d", &day);

    for (int i = 0; i < day; i++)
    {
        int daily_price;
        scanf("%d", &daily_price);
        price += daily_price;
    }
    printf("%d\n", price);
    return 0;
}
