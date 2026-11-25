#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 50

/*
 * User-defined type to represent a date
 */
typedef struct {
    int month;
    int day;
    int year;
} date_t;

/*
 * User-defined type to represent a vehicle's gas tank
 */
typedef struct {
    double capacity;      // Tank capacity in gallons
    double current_level; // Current fuel level in gallons
} tank_t;

/*
 * User-defined type to represent an automobile
 */
typedef struct {
    char make[STR_LEN];
    char model[STR_LEN];
    int odometer;
    date_t manufacture_date;
    date_t purchase_date;
    tank_t gas_tank;
} auto_t;

/*
 * Function: scan_date
 * -------------------
 * Scans month, day, and year for a date_t structure from input stream.
 * Returns 1 on success, EOF on end of file.
 */
int scan_date(FILE *fp, date_t *d) {
    if (fscanf(fp, "%d %d %d", &d->month, &d->day, &d->year) == 3) {
        return 1;
    }
    return EOF;
}

/*
 * Function: scan_tank
 * -------------------
 * Scans tank capacity and current fuel level for a tank_t structure.
 * Returns 1 on success, EOF on end of file.
 */
int scan_tank(FILE *fp, tank_t *t) {
    if (fscanf(fp, "%lf %lf", &t->capacity, &t->current_level) == 2) {
        return 1;
    }
    return EOF;
}

/*
 * Function: scan_auto
 * -------------------
 * Scans all components of an automobile from input stream.
 * Returns 1 on success, EOF on end of file.
 */
int scan_auto(FILE *fp, auto_t *a) {
    if (fscanf(fp, "%49s %49s %d", a->make, a->model, &a->odometer) != 3) {
        return EOF;
    }
    if (scan_date(fp, &a->manufacture_date) == EOF) return EOF;
    if (scan_date(fp, &a->purchase_date) == EOF) return EOF;
    if (scan_tank(fp, &a->gas_tank) == EOF) return EOF;
    return 1;
}

/*
 * Function: print_date
 * --------------------
 * Displays date in MM/DD/YYYY format.
 */
void print_date(date_t d) {
    printf("%02d/%02d/%04d", d.month, d.day, d.year);
}

/*
 * Function: print_tank
 * --------------------
 * Displays fuel tank capacity, current level, and percentage.
 */
void print_tank(tank_t t) {
    double pct = (t.capacity > 0.0) ? (t.current_level / t.capacity) * 100.0 : 0.0;
    printf("%.1f / %.1f gallons (%.1f%% full)", t.current_level, t.capacity, pct);
}

/*
 * Function: print_auto
 * --------------------
 * Displays the complete automobile record in a formatted block.
 */
void print_auto(auto_t a) {
    printf("  +---------------------------------------------------\n");
    printf("  | Make & Model      : %s %s\n", a.make, a.model);
    printf("  | Odometer Reading  : %d miles\n", a.odometer);
    printf("  | Manufacture Date  : ");
    print_date(a.manufacture_date);
    printf("\n");
    printf("  | Purchase Date     : ");
    print_date(a.purchase_date);
    printf("\n");
    printf("  | Gas Tank Status   : ");
    print_tank(a.gas_tank);
    printf("\n");
    printf("  +---------------------------------------------------\n");
}

/*
 * Helper to ensure sample data file exists
 */
void create_sample_file(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp != NULL) {
        fprintf(fp, "Mercury Sable    99842 1 18 2001 5 30 1991 16   12.5\n");
        fprintf(fp, "Mazda   Navajo   123961 2 20 1993 6 15 1993 19.3 16.7\n");
        fclose(fp);
    }
}

int main(int argc, char *argv[]) {
    printf("====================================================\n");
    printf("  PROGRAM 1: AUTOMOBILE STRUCTURE RECORD (auto_t)   \n");
    printf("  Name: Rinaltra Nabasa Simanungkalit | NRP: 5025251024\n");
    printf("====================================================\n\n");

    const char *data_filename = "auto_data.txt";
    create_sample_file(data_filename);

    FILE *fp = NULL;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            printf("Notice: Could not open %s. Using default %s\n", argv[1], data_filename);
            fp = fopen(data_filename, "r");
        }
    } else {
        fp = fopen(data_filename, "r");
    }

    if (fp == NULL) {
        printf("Error: Could not open input data source.\n");
        return 1;
    }

    printf("Input Data Set:\n");
    printf("----------------------------------------------------\n");
    printf("  Make     Model     Odom   Mfg Date   Purch Date  Tank (Cap/Lvl)\n");
    printf("  Mercury  Sable     99842  01/18/2001 05/30/1991  16.0 / 12.5 gal\n");
    printf("  Mazda    Navajo    123961 02/20/1993 06/15/1993  19.3 / 16.7 gal\n");
    printf("----------------------------------------------------\n\n");

    printf("Processing Automobile Records until EOF:\n\n");

    auto_t current_car;
    int record_count = 0;

    // Driver loop: repeatedly fills and displays auto structure until EOF
    while (scan_auto(fp, &current_car) != EOF) {
        record_count++;
        printf("Record #%d:\n", record_count);
        print_auto(current_car);
        printf("\n");
    }

    printf("End of File (EOF) reached. Total automobiles processed: %d\n", record_count);

    fclose(fp);
    return 0;
}
