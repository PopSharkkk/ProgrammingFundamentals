#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DRUGS 50
#define MAX_NAME_LEN 50
#define MAX_INSTR_LEN 250
#define FILENAME "drugs.txt"

// Case-insensitive comparison for up to n characters
int str_nicmp(const char *s1, const char *s2, size_t n) {
    for (size_t i = 0; i < n; i++) {
        unsigned char c1 = (unsigned char)tolower((unsigned char)s1[i]);
        unsigned char c2 = (unsigned char)tolower((unsigned char)s2[i]);
        if (c1 != c2 || c1 == '\0') {
            return c1 - c2;
        }
    }
    return 0;
}

// Function to create default data file if not present
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
int load_drugs(const char *filename, char drug_names[][MAX_NAME_LEN], char instructions[][MAX_INSTR_LEN], int max_drugs) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Could not open %s\n", filename);
        return 0;
    }

    char line[512];
    int count = 0;

    while (count < max_drugs && fgets(line, sizeof(line), fp)) {
        // Strip trailing \r and \n
        size_t len = strlen(line);
        while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) {
            line[--len] = '\0';
        }

        if (len == 0) continue;

        char raw_instr[MAX_INSTR_LEN] = "";
        if (sscanf(line, "%s %[^\n]", drug_names[count], raw_instr) >= 1) {
            // Process instructions: replace ';' with '\n'
            size_t raw_len = strlen(raw_instr);
            // Remove trailing semicolon if present
            while (raw_len > 0 && (raw_instr[raw_len - 1] == ';' || raw_instr[raw_len - 1] == ' ')) {
                raw_instr[--raw_len] = '\0';
            }

            int dest_idx = 0;
            for (size_t j = 0; j < raw_len; j++) {
                if (raw_instr[j] == ';') {
                    instructions[count][dest_idx++] = '\n';
                    // Skip any whitespace immediately following semicolon
                    while (j + 1 < raw_len && raw_instr[j + 1] == ' ') {
                        j++;
                    }
                } else {
                    instructions[count][dest_idx++] = raw_instr[j];
                }
            }
            instructions[count][dest_idx] = '\0';
            count++;
        }
    }

    fclose(fp);
    return count;
}

int main() {
    ensure_data_file();

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

        if (strcmp(query, "q") == 0 || strcmp(query, "Q") == 0 ||
            str_nicmp(query, "quit", 4) == 0) {
            printf("\nExiting program. Goodbye!\n");
            break;
        }

        int found_idx = -1;
        for (int i = 0; i < num_drugs; i++) {
            if (str_nicmp(query, drug_names[i], 3) == 0) {
                found_idx = i;
                break;
            }
        }

        if (found_idx != -1) {
            printf("\nDrug: %s\n", drug_names[found_idx]);
            printf("Instructions:\n%s\n\n", instructions[found_idx]);
        } else {
            printf("Drug not found. Please try again.\n\n");
        }
    }

    return 0;
}
