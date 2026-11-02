#include <stdio.h>
#include <math.h>

int main() {
    double principal, annual_rate, monthly_rate;
    double payment, interest, principal_paid, balance;
    int n, i;

    // 1. Get user input
    printf("Enter loan amount (principal): ");
    scanf("%lf", &principal);

    printf("Enter annual interest rate (e.g., 9 for 9%%): ");
    scanf("%lf", &annual_rate);

    printf("Enter number of payments (months): ");
    scanf("%d", &n);

    // 2. Convert annual rate percentage to monthly decimal rate
    monthly_rate = (annual_rate / 100.0) / 12.0;

    // 3. Calculate regular monthly payment
    payment = principal * (monthly_rate * pow(1 + monthly_rate, n)) / (pow(1 + monthly_rate, n) - 1);

    // Round initial payment to 2 decimal places (nearest cent)
    payment = (int)(payment * 100.0 + 0.5) / 100.0;

    // 4. Print table header to screen
    printf("\n");
    printf("Principal\t\t$%.2f\t\tPayment\t\t$%.2f\n", principal, payment);
    printf("Annual interest\t\t%.1f%%\t\tTerm\t\t%d months\n\n", annual_rate, n);
    printf("%-10s %-12s %-12s %-18s\n", "Payment", "Interest", "Principal", "Principal Balance");
    printf("-------------------------------------------------------------\n");

    balance = principal;

    // 5. Loop through each month
    for (i = 1; i <= n; i++) {
        // Calculate monthly interest rounded to cents
        interest = balance * monthly_rate;
        interest = (int)(interest * 100.0 + 0.5) / 100.0;

        if (i == n) {
            // Last month: remaining balance becomes final principal payment
            principal_paid = balance;
            balance = 0.0;
            double final_payment = interest + principal_paid;

            printf("%-10d %-12.2f %-12.2f %-18.2f\n", i, interest, principal_paid, balance);
            printf("\nFinal payment\t$%.2f\n", final_payment);
        } else {
            principal_paid = payment - interest;
            balance = balance - principal_paid;

            printf("%-10d %-12.2f %-12.2f %-18.2f\n", i, interest, principal_paid, balance);
        }
    }

    return 0;
}