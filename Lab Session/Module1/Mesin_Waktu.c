#include <stdio.h>

int main() {
    int day, month, year;
    scanf("%d %d %d", &day, &month, &year);

    int leap = 0;

    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        leap = 1;
    }

    int maximum_day;

    if (month < 1 || month > 12) {
        printf("TIDAK VALID\n");
        return 0;
    }

    if (month == 2) {
        maximum_day = leap ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        maximum_day = 30;
    } else {
        maximum_day = 31;
    }

    if (day >= 1 && day <= maximum_day) {
        printf("VALID\n");
    } else {
        printf("TIDAK VALID\n");
    }

    return 0;
}