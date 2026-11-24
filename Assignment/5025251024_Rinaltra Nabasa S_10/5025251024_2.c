#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

/*
 * Function: create_sample_files
 * -----------------------------
 * Creates sample file1.txt and file2.txt matching the assignment specification.
 */
void create_sample_files(const char *f1_name, const char *f2_name) {
    FILE *f1 = fopen(f1_name, "w");
    if (f1 != NULL) {
        fprintf(f1, "A binary file is a file created by executing a program that stores directly in the file the computer's internal representation of each file component.\n");
        fclose(f1);
    }

    FILE *f2 = fopen(f2_name, "w");
    if (f2 != NULL) {
        fprintf(f2, "A pointer whose value equals NULL is called a null pointer.\n");
        fclose(f2);
    }
}

/*
 * Function: append_file
 * ---------------------
 * Copies all characters from src_fp to dest_fp.
 * Returns the last character written, or EOF if file was empty.
 */
int append_file(FILE *src_fp, FILE *dest_fp) {
    int ch;
    int last_ch = EOF;
    while ((ch = fgetc(src_fp)) != EOF) {
        fputc(ch, dest_fp);
        last_ch = ch;
    }
    return last_ch;
}

/*
 * Function: display_file
 * ----------------------
 * Prints contents of a file to console with indentation.
 */
void display_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("  [Error: Could not open %s for reading]\n", filename);
        return;
    }
    char line[BUFFER_SIZE];
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("  %s", line);
    }
    fclose(fp);
}

int main(int argc, char *argv[]) {
    printf("====================================================\n");
    printf("  PROGRAM 2: TEXT FILE MERGER (File 2 then File 1)  \n");
    printf("  Name: Rinaltra Nabasa Simanungkalit | NRP: 5025251024\n");
    printf("====================================================\n\n");

    const char *file1_path = (argc > 1) ? argv[1] : "file1.txt";
    const char *file2_path = (argc > 2) ? argv[2] : "file2.txt";
    const char *output_path = (argc > 3) ? argv[3] : "merged_output.txt";

    // Create sample text files if using default names
    if (argc <= 1) {
        create_sample_files(file1_path, file2_path);
    }

    // Display inputs
    printf("1. Source File 1 (%s):\n", file1_path);
    display_file(file1_path);

    printf("2. Source File 2 (%s):\n", file2_path);
    display_file(file2_path);

    // Open source file 2
    FILE *f2 = fopen(file2_path, "r");
    if (f2 == NULL) {
        fprintf(stderr, "Error: Unable to open input file 2: %s\n", file2_path);
        return 1;
    }

    // Open source file 1
    FILE *f1 = fopen(file1_path, "r");
    if (f1 == NULL) {
        fprintf(stderr, "Error: Unable to open input file 1: %s\n", file1_path);
        fclose(f2);
        return 1;
    }

    // Open destination output file
    FILE *fout = fopen(output_path, "w");
    if (fout == NULL) {
        fprintf(stderr, "Error: Unable to create output merged file: %s\n", output_path);
        fclose(f1);
        fclose(f2);
        return 1;
    }

    // Merge: First write file 2, then file 1
    int last_ch = append_file(f2, fout);
    if (last_ch != EOF && last_ch != '\n') {
        fputc('\n', fout); // Ensure newline between files
    }

    append_file(f1, fout);

    fclose(f1);
    fclose(f2);
    fclose(fout);

    printf("3. Merged Output (%s - Contents of File 2 followed by File 1):\n", output_path);
    printf("----------------------------------------------------\n");
    display_file(output_path);
    printf("----------------------------------------------------\n");
    printf("Merge operation completed successfully.\n");

    return 0;
}
