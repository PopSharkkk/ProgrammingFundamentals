#include <stdio.h>


int main() {
    double initial_cost, annual_fuel_cost, tax_rate, total_cost;
    double total_fuel, total_taxes;
    scanf("%lf", &initial_cost);

    scanf("%lf", &annual_fuel_cost);
    
    
    scanf("%lf", &tax_rate);

    total_fuel = annual_fuel_cost * 5.0;
    total_taxes = (tax_rate * initial_cost) * 5.0;
    total_cost = initial_cost + total_fuel + total_taxes;

    printf("Total biaya rumah setelah lima tahun: %.2lf\n", total_cost);

    return 0;
}
