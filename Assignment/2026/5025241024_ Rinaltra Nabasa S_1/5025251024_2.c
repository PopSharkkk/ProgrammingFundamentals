#include <stdio.h>

int main()
{
    const double gravity = 9.80;
    const double eff = 0.90;
    const double waterdensity = 1000.0;
    const double watts = 1e6;

    double height, flow_rate;

    printf("enter height: ");
    scanf("%lf", &height);
    printf("Enter water debit: ");
    scanf("%lf", &flow_rate);

    double mass = flow_rate * waterdensity;

    double work_per_sec = mass * gravity * height;

    double power_watts = work_per_sec * eff;

    double power_mw = power_watts / watts;

    printf("power produced: ", power_mw);

    return 0;
}