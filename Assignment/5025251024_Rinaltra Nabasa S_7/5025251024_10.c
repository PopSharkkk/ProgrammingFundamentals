#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DRUGS 50
#define MAX_NAME_LEN 50
#define MAX_INSTR_LEN 121
#define FILENAME "drugs.txt"

// Function to ensure the data file exists
void ensure_data_file() {
    FILE *fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        fp = fopen(FILENAME, "w");
        if (fp != NULL) {
            fprintf(fp, "amiodarone Dose 1: 300 mg IV push;Dose 2: 150 mg IV push;Infusion 1: 1 mg/min for 6 hrs; Infusion 2: 0.5 mg/min for 18 hrs;\n");
            fprintf(fp, "adenosine Dose 1: 6 mg rapid IV push;Dose 2: 12 mg rapid IV push;\n");
            fprintf(fp, "atropine 0.5 mg IV push every 3-5 min;max 3 mg;\n");
            fprintf(fp, "dopamine Infusion 2-10 mcg/kg/min;\n");
            fprintf(fp, "epinephrine 1 mg IV push every 3-5 min;Infusion: 2-10 mcg/min\n");
            fprintf(fp, "magnesium Infusion: 1-2g over 5 to 20 min;\n");
            fprintf(fp, "vasopressin 40 units IV push;\n");
            fclose(fp);
        }
    } else {
        fclose(fp);
    }
}

// Function to load drug names and instructions from data file
// Scans drug names into an array of strings and dosing instructions into a second array of strings
int load_drugs(const char *filename, char drug_names[][MAX_NAME_LEN], char instructions[][MAX_INSTR_LEN], int max_drugs) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Could not open %s\n", filename);
        return 0;
    }

    char line[512];
    int count = 0;

    while (count < max_drugs && fgets(line, sizeof(line), fp)) {
        // Strip trailing newline characters
        size_t line_len = strlen(line);
        while (line_len > 0 && (line[line_len - 1] == '\n' || line[line_len - 1] == '\r')) {
            line[--line_len] = '\0';
        }
        if (line_len == 0) continue;

        // Scan drug name and raw instruction string
        char raw_instr[MAX_INSTR_LEN] = "";
        if (sscanf(line, "%s %[^\n]", drug_names[count], raw_instr) >= 1) {
            // String manipulation: Replace all semicolons (';') with newline ('\n')
            char *src = raw_instr;
            char *dst = instructions[count];
            while (*src != '\0') {
                if (*src == ';') {
                    *dst++ = '\n';
                    src++;
                    // Skip optional space following semicolon for clean formatting
                    while (*src == ' ') src++;
                } else {
                    *dst++ = *src++;
                }
            }
            *dst = '\0';

            // Remove trailing newline if instruction ended with a semicolon
            size_t instr_len = strlen(instructions[count]);
            while (instr_len > 0 && instructions[count][instr_len - 1] == '\n') {
                instructions[count][--instr_len] = '\0';
            }

            count++;
        }
    }

    fclose(fp);
    return count;
}

// Search helper function using strncmp from <string.h>
// Compares the first 3 characters of the query with drug names
int search_drug(const char drug_names[][MAX_NAME_LEN], int count, const char *target) {
    for (int i = 0; i < count; i++) {
        if (strncmp(target, drug_names[i], 3) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    ensure_data_file();

    // Arrays of strings for drug names and dosing instructions
    char drug_names[MAX_DRUGS][MAX_NAME_LEN];
    char instructions[MAX_DRUGS][MAX_INSTR_LEN];

    int num_drugs = load_drugs(FILENAME, drug_names, instructions, MAX_DRUGS);
    if (num_drugs == 0) {
        printf("No drug data loaded.\n");
        return 1;
    }

    printf("ACLS Drug Administration Assistant\n");
    printf("==================================\n");
    printf("Please enter only the first three characters of the desired drug.\n");
    printf("Enter 'q' or 'quit' to exit the program.\n\n");

    char query[50];
    while (1) {
        printf("Enter drug code (first 3 chars or 'q' to quit): ");
        if (scanf("%49s", query) != 1) break;

        // Exit condition using strcmp / strncmp from <string.h>
        if (strcmp(query, "q") == 0 || strcmp(query, "Q") == 0 ||
            strncmp(query, "quit", 4) == 0) {
            printf("\nExiting program. Goodbye!\n");
            break;
        }

        // Search for requested drug using 3-character prefix matching (strncmp)
        int found_idx = search_drug(drug_names, num_drugs, query);

        if (found_idx != -1) {
            printf("\nDrug: %s\n", drug_names[found_idx]);
            printf("Instructions:\n%s\n\n", instructions[found_idx]);
        } else {
            printf("Drug not found. Please try again.\n\n");
        }
    }

    return 0;
}
