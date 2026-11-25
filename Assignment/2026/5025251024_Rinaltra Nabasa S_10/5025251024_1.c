#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#define MAX_SITES 10

/*
 * Structure type to represent meteorological measured data
 */
typedef struct {
    int site_id_num;     // Four-digit site identification number
    double wind_speed;   // Wind speed in knots
    int day_of_month;    // Day of the month
    double temperature;  // Temperature in degrees Celsius
} measured_data_t;

/*
 * Structure to aggregate statistical metrics per site
 */
typedef struct {
    int site_id_num;
    int count;
    double min_temp;
    double max_temp;
    double total_wind;
} site_stats_t;

/*
 * Helper to ensure the sample meteorological data file exists
 */
void create_sample_file(const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp != NULL) {
        // July daily data collected over one week at three sites
        fprintf(fp, "2001 10 11 30\n");
        fprintf(fp, "2001 11  5 22\n");
        fprintf(fp, "2001 12 18 25\n");
        fprintf(fp, "2001 13 16 26\n");
        fprintf(fp, "2001 14 14 26\n");
        fprintf(fp, "2001 15  2 25\n");
        fprintf(fp, "2001 16 14 22\n");

        fprintf(fp, "3345 10  8 29\n");
        fprintf(fp, "3345 11  5 23\n");
        fprintf(fp, "3345 12 12 23\n");
        fprintf(fp, "3345 13 14 24\n");
        fprintf(fp, "3345 14 10 24\n");
        fprintf(fp, "3345 15  9 22\n");
        fprintf(fp, "3345 16  9 20\n");

        fprintf(fp, "3819 10 17 27\n");
        fprintf(fp, "3819 11 20 21\n");
        fprintf(fp, "3819 12 22 21\n");
        fprintf(fp, "3819 13 18 22\n");
        fprintf(fp, "3819 14 15 22\n");
        fprintf(fp, "3819 15  9 19\n");
        fprintf(fp, "3819 16 12 18\n");
        fclose(fp);
    }
}

/*
 * Finds the index of a site in the stats array, or adds it if new
 */
int find_or_add_site(site_stats_t sites[], int *num_sites, int site_id) {
    for (int i = 0; i < *num_sites; i++) {
        if (sites[i].site_id_num == site_id) {
            return i;
        }
    }
    if (*num_sites < MAX_SITES) {
        int idx = *num_sites;
        sites[idx].site_id_num = site_id;
        sites[idx].count = 0;
        sites[idx].min_temp = DBL_MAX;
        sites[idx].max_temp = -DBL_MAX;
        sites[idx].total_wind = 0.0;
        (*num_sites)++;
        return idx;
    }
    return -1; // Exceeded maximum number of sites
}

int main(int argc, char *argv[]) {
    printf("====================================================\n");
    printf("  PROGRAM 1: METEOROLOGICAL DATA ANALYSIS           \n");
    printf("  Name: Rinaltra Nabasa Simanungkalit | NRP: 5025251024\n");
    printf("====================================================\n\n");

    const char *data_filename = "weather_july.txt";
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
        printf("Error: Could not open input meteorological data file.\n");
        return 1;
    }

    site_stats_t sites[MAX_SITES];
    int num_sites = 0;

    measured_data_t record;
    int total_records = 0;

    // Read file of measured_data_t records until EOF
    while (fscanf(fp, "%d %d %lf %lf",
                  &record.site_id_num,
                  &record.day_of_month,
                  &record.wind_speed,
                  &record.temperature) == 4) {
        total_records++;
        int idx = find_or_add_site(sites, &num_sites, record.site_id_num);
        if (idx != -1) {
            sites[idx].count++;
            sites[idx].total_wind += record.wind_speed;
            if (record.temperature < sites[idx].min_temp) {
                sites[idx].min_temp = record.temperature;
            }
            if (record.temperature > sites[idx].max_temp) {
                sites[idx].max_temp = record.temperature;
            }
        }
    }
    fclose(fp);

    printf("Input File: %s (Processed %d daily records across %d sites)\n\n",
           data_filename, total_records, num_sites);

    printf("Meteorological Summary per Station:\n");
    printf("--------------------------------------------------------------------\n");
    printf("  Site ID | Days | Min Temp | Max Temp | Temp Var (Extrema) | Avg Wind\n");
    printf("--------------------------------------------------------------------\n");

    double max_variation = -1.0;
    double max_avg_wind = -1.0;

    for (int i = 0; i < num_sites; i++) {
        double variation = sites[i].max_temp - sites[i].min_temp;
        double avg_wind = (sites[i].count > 0) ? (sites[i].total_wind / sites[i].count) : 0.0;

        printf("   %4d   |  %2d  | %5.1f C  | %5.1f C  |      %5.1f C       | %5.2f kts\n",
               sites[i].site_id_num,
               sites[i].count,
               sites[i].min_temp,
               sites[i].max_temp,
               variation,
               avg_wind);

        if (variation > max_variation) {
            max_variation = variation;
        }
        if (avg_wind > max_avg_wind) {
            max_avg_wind = avg_wind;
        }
    }
    printf("--------------------------------------------------------------------\n\n");

    // Display sites with the greatest variation in temperature
    printf("Analysis Results:\n");
    printf("1. Site(s) with Greatest Variation in Temperature (extrema difference):\n");
    for (int i = 0; i < num_sites; i++) {
        double variation = sites[i].max_temp - sites[i].min_temp;
        if (variation == max_variation) {
            printf("   -> Site %d: Variation = %.1f C (Min: %.1f C, Max: %.1f C)\n",
                   sites[i].site_id_num, variation, sites[i].min_temp, sites[i].max_temp);
        }
    }
    printf("\n");

    // Display site with the highest average wind speed
    printf("2. Site(s) with Highest Average Wind Speed:\n");
    for (int i = 0; i < num_sites; i++) {
        double avg_wind = (sites[i].count > 0) ? (sites[i].total_wind / sites[i].count) : 0.0;
        if (avg_wind >= max_avg_wind - 1e-5) {
            printf("   -> Site %d: Highest Average Wind Speed = %.2f knots\n",
                   sites[i].site_id_num, avg_wind);
        }
    }
    printf("\n");

    return 0;
}
