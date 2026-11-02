#include <stdio.h>
#include <string.h>
#include <math.h>

#define NUM_COLORS 10
#define MAX_COLOR_LEN 7

// Table of resistor color codes
const char COLOR_CODES[NUM_COLORS][MAX_COLOR_LEN] = {
    "black", "brown", "red", "orange", "yellow",
    "green", "blue", "violet", "gray", "white"
};

// Helper function to search for a target color in the list
// Returns subscript of matching element or -1 if not found
int search(const char list[][MAX_COLOR_LEN], int size, const char *target) {
    for (int i = 0; i < size; i++) {
        if (strcmp(list[i], target) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char band1[20], band2[20], band3[20];
    char reply[10];
    char again = 'y';

    while (again == 'y' || again == 'Y') {
        printf("Enter the colors of the resistor's three bands, beginning with\n");
        printf("the band nearest the end. Type the colors in lowercase letters\n");
        printf("only, NO CAPS.\n\n");

        printf("Band 1 => ");
        if (scanf("%19s", band1) != 1) break;
        printf("Band 2 => ");
        if (scanf("%19s", band2) != 1) break;
        printf("Band 3 => ");
        if (scanf("%19s", band3) != 1) break;

        int b1 = search(COLOR_CODES, NUM_COLORS, band1);
        int b2 = search(COLOR_CODES, NUM_COLORS, band2);
        int b3 = search(COLOR_CODES, NUM_COLORS, band3);

        if (b1 == -1) {
            printf("Invalid color: %s\n", band1);
        } else if (b2 == -1) {
            printf("Invalid color: %s\n", band2);
        } else if (b3 == -1) {
            printf("Invalid color: %s\n", band3);
        } else {
            // Resistance in ohms = (b1 * 10 + b2) * 10^b3
            // Resistance in kilo-ohms = Resistance / 1000
            double resistance_ohms = (b1 * 10.0 + b2) * pow(10.0, b3);
            double resistance_kilo_ohms = resistance_ohms / 1000.0;

            if (resistance_kilo_ohms == (long)resistance_kilo_ohms) {
                printf("Resistance value: %.0f kilo-ohms\n", resistance_kilo_ohms);
            } else {
                printf("Resistance value: %g kilo-ohms\n", resistance_kilo_ohms);
            }
        }

        printf("Do you want to decode another resistor?\n=> ");
        if (scanf("%9s", reply) != 1) break;
        again = reply[0];
    }

    return 0;
}
