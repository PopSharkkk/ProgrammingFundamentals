#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2;
    int a, b, remainder;

    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Work with absolute values
    a = abs(num1);
    b = abs(num2);

    if (a == 0 && b == 0) {
        printf("GCD is undefined for (0, 0).\n");
        return 0;
    }

    // Ensure 'a' is the larger value to start
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Euclidean division process
    while (b != 0) {
        remainder = a % b;
        a = b;
        b = remainder;
    }

    printf("The greatest common divisor (gcd) of %d and %d is %d\n", num1, num2, a);

    return 0;
}