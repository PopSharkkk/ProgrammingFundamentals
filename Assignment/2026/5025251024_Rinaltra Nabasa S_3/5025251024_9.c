#include <stdio.h>
#include <math.h>

int main() {
    int weekday_mins, night_mins, weekend_mins, total_mins;
    
    // Constants stored as cents
    const int FLAT_RATE = 3999;
    const int INCLUDED_WEEKDAY_MINS = 600;
    const int EXTRA_MIN_COST = 40;
    const double TAX_RATE = 0.0525;

    printf("Enter weekday minutes used: ");
    scanf("%d", &weekday_mins);
    printf("Enter night minutes used: ");
    scanf("%d", &night_mins);
    printf("Enter weekend minutes used: ");
    scanf("%d", &weekend_mins);

    // Calculations
    int extra_mins = 0;
    if (weekday_mins > INCLUDED_WEEKDAY_MINS) {
        extra_mins = weekday_mins - INCLUDED_WEEKDAY_MINS;
    }

    int pretax_bill_cents = FLAT_RATE + (extra_mins * EXTRA_MIN_COST);
    total_mins = weekday_mins + night_mins + weekend_mins;

    int avg_minute_cost_cents = 0;
    if (total_mins > 0) {
        avg_minute_cost_cents = (int)round((double)pretax_bill_cents / total_mins);
    }

    int taxes_cents = (int)round(pretax_bill_cents * TAX_RATE);
    int total_bill_cents = pretax_bill_cents + taxes_cents;

    // Output formatted to dollars
    printf("\n--- Monthly Bill Summary ---\n");
    printf("Weekday Minutes: %d\n", weekday_mins);
    printf("Night Minutes:   %d\n", night_mins);
    printf("Weekend Minutes: %d\n", weekend_mins);
    printf("Pretax Bill:     $%.2f\n", pretax_bill_cents / 100.0);
    printf("Average Cost/Min:$%.2f\n", avg_minute_cost_cents / 100.0);
    printf("Taxes (5.25%%):   $%.2f\n", taxes_cents / 100.0);
    printf("Total Bill:      $%.2f\n", total_bill_cents / 100.0);

    return 0;
}