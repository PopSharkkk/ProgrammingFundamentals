#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 20
#define NAME_LEN 50

// Function to display the parallel arrays
void display_list(char names[][NAME_LEN], int ages[], int count) {
    for (int i = 0; i < count; i++) {
        printf("    %-22s %d\n", names[i], ages[i]);
    }
}

// Function to sort names alphabetically and keep ages synchronized
// Utilizes strcmp() for lexicographical comparison and strcpy() for string swapping
void sort_parallel(char names[][NAME_LEN], int ages[], int count) {
    for (int i = 0; i < count - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < count; j++) {
            // String comparison using strcmp from <string.h>
            if (strcmp(names[j], names[min_idx]) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            // Swap strings using strcpy from <string.h>
            char temp_name[NAME_LEN];
            strcpy(temp_name, names[i]);
            strcpy(names[i], names[min_idx]);
            strcpy(names[min_idx], temp_name);

            // Swap corresponding ages in parallel array
            int temp_age = ages[i];
            ages[i] = ages[min_idx];
            ages[min_idx] = temp_age;
        }
    }
}

int main() {
    // Initial parallel arrays based on the problem statement
    // names: 2D char array storing list of strings
    char names[MAX_PEOPLE][NAME_LEN] = {
        "Ryan, Elizabeth",
        "McIntyre, Osborne",
        "DuMond, Kristin",
        "Larson, Lois",
        "Thorpe, Trinity",
        "Ruiz, Pedro"
    };
    int ages[MAX_PEOPLE] = {62, 84, 18, 42, 15, 35};
    int count = 6;

    // Display original list
    printf("Original list\n");
    printf("-------------------------------------\n");
    display_list(names, ages, count);

    // Sort arrays in parallel using string operations
    sort_parallel(names, ages, count);

    // Display alphabetized list
    printf("\nAlphabetized list\n");
    printf("-------------------------------------\n");
    display_list(names, ages, count);

    return 0;
}
