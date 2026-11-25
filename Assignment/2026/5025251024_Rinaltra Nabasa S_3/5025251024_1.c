#include <stdio.h>

int main()
{
    float purchase_total, discount = 0.0, subtotal, tax, final_total;
    char is_student;

    printf("Enter purchase total: $");
    scanf("%f", &purchase_total);

    printf("Are you a student? (y/n): ");
    scanf(" %c", &is_student);

    if (is_student == 'y' || is_student == 'Y')
    {
        discount = purchase_total * 0.20;
    }

    subtotal = purchase_total - discount;
    tax = subtotal * 0.05;
    final_total = subtotal + tax;

    printf("\n--- Receipt ---\n");
    printf("Purchase Total: $%8.2f\n", purchase_total);
    if (discount > 0)
    {
        printf("Student Discount: $%8.2f\n", discount);
    }
    printf("Subtotal:       $%8.2f\n", subtotal);
    printf("Sales Tax (5%%): $%8.2f\n", tax);
    printf("Final Total:    $%8.2f\n", final_total);

    return 0;
}