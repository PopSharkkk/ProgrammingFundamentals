#include <stdio.h>
#include <math.h>

// Function prototypes
int get_corners(FILE *inFile, double x[], double y[], int maxSize);
void output_corners(FILE *outFile, double x[], double y[], int actualSize);
double polygon_area(double x[], double y[], int actualSize);

int main() {
    const int MAX_SIZE = 20;
    double x[20], y[20];
    
    // Create a temporary test file with the provided data
    FILE *createTestFile = fopen("polygon_data.txt", "w");
    if (createTestFile) {
        fprintf(createTestFile, "4 0\n4 7.5\n7 7.5\n7 3\n9 0\n7 0\n4 0\n");
        fclose(createTestFile);
    }

    FILE *inFile = fopen("polygon_data.txt", "r");
    if (!inFile) {
        printf("Error opening input file.\n");
        return 1;
    }

    int actualSize = get_corners(inFile, x, y, MAX_SIZE);
    fclose(inFile);

    FILE *outFile = fopen("polygon_output.txt", "w");
    output_corners(outFile, x, y, actualSize);
    fclose(outFile);

    double area = polygon_area(x, y, actualSize);
    printf("Polygon area calculated: %.2f square units.\n", area);

    return 0;
}

int get_corners(FILE *inFile, double x[], double y[], int maxSize) {
    int count = 0;
    while (count < maxSize && fscanf(inFile, "%lf %lf", &x[count], &y[count]) == 2) {
        count++;
    }
    return count; // Returns the number of coordinates stored
}

void output_corners(FILE *outFile, double x[], double y[], int actualSize) {
    fprintf(outFile, "x\ty\n-------------\n");
    for (int i = 0; i < actualSize; i++) {
        fprintf(outFile, "%.1f\t%.1f\n", x[i], y[i]);
    }
}

double polygon_area(double x[], double y[], int actualSize) {
    double sum = 0.0;
    // Formula: sum of (x_{i+1} + x_i) * (y_{i+1} - y_i)
    for (int i = 0; i < actualSize - 1; i++) {
        sum += (x[i+1] + x[i]) * (y[i+1] - y[i]);
    }
    return 0.5 * fabs(sum);
}