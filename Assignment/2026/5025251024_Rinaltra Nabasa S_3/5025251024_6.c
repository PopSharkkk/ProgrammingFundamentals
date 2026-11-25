#include <stdio.h>

int main() {
    float x, y;

    printf("Enter the x and y coordinates: ");
    scanf("%f %f", &x, &y);

    if (x == 0.0 && y == 0.0) {
        printf("(%.1f, %.1f) is at the origin\n", x, y);
    } else if (x == 0.0) {
        printf("(%.1f, %.1f) is on the y-axis\n", x, y);
    } else if (y == 0.0) {
        printf("(%.1f, %.1f) is on the x-axis\n", x, y);
    } else if (x > 0.0 && y > 0.0) {
        printf("(%.1f, %.1f) is in quadrant I\n", x, y);
    } else if (x < 0.0 && y > 0.0) {
        printf("(%.1f, %.1f) is in quadrant II\n", x, y);
    } else if (x < 0.0 && y < 0.0) {
        printf("(%.1f, %.1f) is in quadrant III\n", x, y);
    } else if (x > 0.0 && y < 0.0) {
        printf("(%.1f, %.1f) is in quadrant IV\n", x, y);
    }

    return 0;
}