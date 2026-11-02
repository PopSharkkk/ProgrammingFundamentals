#include <stdio.h>

int main ()
{
    float height;
    int weight;
    scanf("%.f" "%d", &height, &weight);

    float bmi = weight / (height * height);

    if (bmi < 18.5)
    {
        printf("Kurus");
    }
    else if (bmi > 18.5 || bmi < 24.9)
    {
        printf("Normal");
    }
    else if (bmi > 25.0 || bmi < 29.9)
    {
        printf("Overweight");
    }
    else if (bmi > 30.0 || bmi < 34.9)
    {
        printf("Obesitas I");
    }
    else if (bmi > 35.0)
    {
        printf("Obesitas II");
    }

    return 0;
}
