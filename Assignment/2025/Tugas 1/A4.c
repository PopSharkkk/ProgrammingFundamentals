#include <stdio.h>

int main()
{

    float volume, radius, height, area;
    scanf("%f %f", &radius, &height);
    volume = 3.14159 * radius * radius * height;
    area = 2 * 3.14159 * radius * (radius + height);
    printf("%.2f %.2f\n", volume, area);
    return 0;
}