#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
    int n;
    double approx, term1, term2;
    scanf("%d", &n);

    term1 = (2.0 * n) + (1.0 / 3.0);
    term2 = sqrt(term1 * PI);
    
    approx = pow(n, n) * exp(-n) * term2;

    printf("Nilai perantara (2n + 1/3): %lf\n", term1);
    printf("Nilai perantara sqrt((2n + 1/3)PI): %lf\n", term2);
    printf("%d! equals approximately %lf\n", n, approx);

    return 0;
}