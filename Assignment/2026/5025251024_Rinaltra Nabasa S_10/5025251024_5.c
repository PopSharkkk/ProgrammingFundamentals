#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LEN 512

/*
 * Helper to create sample input text file
 */
void create_sample_file(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp != NULL) {
        fprintf(fp, "Algorithms and Data Structures form the core of Computer Science.\n");
        fprintf(fp, "Binary search requires a sorted array for logarithmic lookups.\n");
        fprintf(fp, "Apple developed macOS and iOS with refined ergonomics.\n");
        fprintf(fp, "Programming Fundamentals teaches foundational procedural C.\n");
        fprintf(fp, "Arrays and Pointers allow direct memory access.\n");
        fprintf(fp, "Functions modularize repetitive logic into reusable blocks.\n");
        fclose(fp);
    }
}

/*
 * Function: extract_uppercase
 * ----------------------------
 * Part 1: Reads text from in_path, extracts all uppercase letters (A-Z),
 * and prints them into out_path.
 * Generates an error message if any file cannot be opened.
 * Returns 1 on success, 0 on failure.
 */
int extract_uppercase(const char *in_path, const char *out_path) {
    FILE *fin = fopen(in_path, "r");
    if (fin == NULL) {
        printf("  [ERROR] Cannot open input file '%s' for reading.\n", in_path);
        return 0;
    }

    FILE *fout = fopen(out_path, "w");
    if (fout == NULL) {
        printf("  [ERROR] Cannot open output file '%s' for writing.\n", out_path);
        fclose(fin);
        return 0;
    }

    int ch;
    int count = 0;
    while ((ch = fgetc(fin)) != EOF) {
        if (isupper(ch)) {
            fputc(ch, fout);
            count++;
        }
    }
    fputc('\n', fout);

    fclose(fin);
    fclose(fout);
    return 1;
}

/*
 * Function: extract_lines_starting_with_A
 * ---------------------------------------
 * Part 2 (Modified Program): Reads text from in_path and prints all lines
 * that start with the letter 'A' into out_path.
 * Generates an error message if any file cannot be opened.
 * Returns 1 on success, 0 on failure.
 */
int extract_lines_starting_with_A(const char *in_path, const char *out_path) {
    FILE *fin = fopen(in_path, "r");
    if (fin == NULL) {
        printf("  [ERROR] Cannot open input file '%s' for reading.\n", in_path);
        return 0;
    }

    FILE *fout = fopen(out_path, "w");
    if (fout == NULL) {
        printf("  [ERROR] Cannot open output file '%s' for writing.\n", out_path);
        fclose(fin);
        return 0;
    }

    char line[MAX_LINE_LEN];
    int line_count = 0;

    while (fgets(line, sizeof(line), fin) != NULL) {
        if (line[0] == 'A') {
            fputs(line, fout);
            line_count++;
        }
    }

    fclose(fin);
    fclose(fout);
    return 1;
}

/*
 * Helper to display the contents of a file
 */
void display_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("  [Error: Could not open %s]\n", filename);
        return;
    }
    char line[MAX_LINE_LEN];
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("  %s", line);
    }
    fclose(fp);
}

int main() {
    printf("====================================================\n");
    printf("  PROGRAM 5: TEXT FILE FILTERING & EXTRACTION       \n");
    printf("  Name: Rinaltra Nabasa Simanungkalit | NRP: 5025251024\n");
    printf("====================================================\n\n");

    const char *input_file = "input_text.txt";
    const char *upper_file = "uppercase_letters.txt";
    const char *lines_a_file = "lines_starting_with_A.txt";

    // 1. Create input file
    create_sample_file(input_file);
    printf("Original Input File (%s):\n", input_file);
    printf("----------------------------------------------------\n");
    display_file(input_file);
    printf("----------------------------------------------------\n\n");

    // 2. Part 1: Extract all uppercase letters
    printf("Part 1: Extract All Upper-Case Letters -> %s\n", upper_file);
    if (extract_uppercase(input_file, upper_file)) {
        printf("Extraction successful. File contents:\n");
        printf("  >> ");
        display_file(upper_file);
    }
    printf("\n");

    // 3. Part 2: Extract all lines starting with 'A'
    printf("Part 2: Extract Lines Starting with Letter 'A' -> %s\n", lines_a_file);
    if (extract_lines_starting_with_A(input_file, lines_a_file)) {
        printf("Extraction successful. File contents:\n");
        printf("----------------------------------------------------\n");
        display_file(lines_a_file);
        printf("----------------------------------------------------\n");
    }
    printf("\n");

    // 4. Error Message Generation Demonstration
    printf("Part 3: Error Message Validation (Testing Missing File):\n");
    printf("Attempting to open non-existent file 'non_existent_data.txt'...\n");
    extract_uppercase("non_existent_data.txt", "dummy_out.txt");

    printf("\nAll file filtering operations completed successfully.\n");
    return 0;
}
