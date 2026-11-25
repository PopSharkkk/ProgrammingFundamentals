#include <stdio.h>

int main() {
    int barcode[12];
    
    printf("Enter the 12 digits of a barcode separated by spaces: ");
    for (int i = 0; i < 12; i++) {
        scanf("%d", &barcode[i]);
    }

    // Step 1: Sum of digits in odd-numbered positions (indices 0, 2, 4, 6, 8, 10)
    int step1_sum = 0;
    for (int i = 0; i < 11; i += 2) {
        step1_sum += barcode[i];
    }
    int step1_result = step1_sum * 3;

    // Step 2: Sum of digits in even-numbered positions (indices 1, 3, 5, 7, 9)
    int step2_sum = 0;
    for (int i = 1; i < 10; i += 2) {
        step2_sum += barcode[i];
    }
    int step2_result = step1_result + step2_sum;

    // Step 3: Calculate the check digit[cite: 3]
    int last_digit_step2 = step2_result % 10;
    int calculated_check_digit = (last_digit_step2 == 0) ? 0 : (10 - last_digit_step2);

    // Output intermediate results
    printf("\nResult from step 1: %d\n", step1_result);
    printf("Result from step 2: %d\n", step2_result);

    // Step 4: Compare and output validation
    printf("Barcode: ");
    for (int i = 0; i < 12; i++) {
        printf("%d ", barcode[i]);
    }
    
    if (calculated_check_digit == barcode[11]) {
        printf("\nMessage: validated.\n");
    } else {
        printf("\nMessage: error in barcode.\n");
    }

    return 0;
}