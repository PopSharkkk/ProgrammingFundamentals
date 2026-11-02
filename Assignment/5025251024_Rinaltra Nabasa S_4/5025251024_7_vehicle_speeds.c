#include <stdio.h>

int main() {
    // Input test data provided in the problem
    int speeds[] = {
        43, 23, 54, 57, 68, 67, 51, 90, 33, 22, 11,
        88, 34, 52, 75, 12, 78, 32, 89, 14, 65, 67, 97, 53, 10, 47, 34
    };
    int num_vehicles = sizeof(speeds) / sizeof(speeds[0]);

    int high_count = 0;
    int medium_count = 0;
    int slow_count = 0;
    int sum_speeds = 0;

    printf("Vehicle Speed Analysis:\n");
    printf("---------------------------\n");

    for (int i = 0; i < num_vehicles; i++) {
        int speed = speeds[i];
        sum_speeds += speed;

        printf("Vehicle %2d: %2d mph - ", i + 1, speed);

        if (speed >= 90) {
            printf("High Speed\n");
            high_count++;
        } else if (speed >= 50) { // 50 to 89 mph
            printf("Medium Speed\n");
            medium_count++;
        } else { // Less than 50 mph
            printf("Slow Speed\n");
            slow_count++;
        }
    }

    // Part a: Counts output
    printf("\n--- Summary Counts ---\n");
    printf("High Speed vehicles (>= 90 mph): %d\n", high_count);
    printf("Medium Speed vehicles (50-89 mph): %d\n", medium_count);
    printf("Slow Speed vehicles (< 50 mph): %d\n", slow_count);

    // Part b: Average speed output
    double average_speed = (double)sum_speeds / num_vehicles;
    printf("\n--- Average Speed ---\n");
    printf("Average speed of all vehicles: %.2f mph\n", average_speed);

    return 0;
}