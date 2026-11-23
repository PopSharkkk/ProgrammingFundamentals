#include <stdio.h>

#define GRID_SIZE 5

/*
 * Initial grid configuration from Figure 9.27
 * y-coordinates: 4 (top) to 0 (bottom)
 * x-coordinates: 0 (left) to 4 (right)
 */
const int INITIAL_GRID[GRID_SIZE][GRID_SIZE] = {
    /* y = 0 */ {0, 1, 0, 1, 1},
    /* y = 1 */ {1, 0, 0, 0, 1},
    /* y = 2 */ {0, 0, 1, 0, 1},
    /* y = 3 */ {0, 1, 1, 0, 0},
    /* y = 4 */ {1, 1, 0, 0, 0}
};

/*
 * Function: blob_check
 * --------------------
 * Recursively counts the number of pixels belonging to a blob (object).
 * Parameters:
 *   grid - 2D array of cells (0 = empty, 1 = filled)
 *   x    - x-coordinate (column, 0 to 4)
 *   y    - y-coordinate (row, 0 to 4)
 *
 * Returns:
 *   Number of cells in the blob to which cell (x, y) belongs.
 */
int blob_check(int grid[GRID_SIZE][GRID_SIZE], int x, int y) {
    // Case 1: Cell is outside the grid bounds
    if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE) {
        return 0;
    }

    // Case 2: Cell is empty (0)
    if (grid[y][x] == 0) {
        return 0;
    }

    // Case 3: Cell is on the grid and filled (1)
    // Mark cell as empty (0) to avoid counting it more than once
    grid[y][x] = 0;

    // Value returned is 1 plus the sizes of blobs containing each of its eight neighbors
    int count = 1;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx != 0 || dy != 0) {
                count += blob_check(grid, x + dx, y + dy);
            }
        }
    }

    return count;
}

// Helper function to print the 5x5 grid with coordinate axes
void print_grid(const int grid[GRID_SIZE][GRID_SIZE]) {
    printf("   y\\x  0 1 2 3 4\n");
    printf("  +---------------\n");
    for (int y = GRID_SIZE - 1; y >= 0; y--) {
        printf("  %2d | ", y);
        for (int x = 0; x < GRID_SIZE; x++) {
            printf(" %d", grid[y][x]);
        }
        printf("\n");
    }
}

// Helper to copy initial grid into a working grid
void reset_grid(int dest[GRID_SIZE][GRID_SIZE], const int src[GRID_SIZE][GRID_SIZE]) {
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            dest[y][x] = src[y][x];
        }
    }
}

int main() {
    int working_grid[GRID_SIZE][GRID_SIZE];

    printf("====================================================\n");
    printf("  PROGRAM 1: PIXEL COUNTING (BLOB DETECTION)        \n");
    printf("  Name: Rinaltra Nabasa Simanungkalit | NRP: 5025251024\n");
    printf("====================================================\n\n");

    printf("Original Grid (Figure 9.27):\n");
    reset_grid(working_grid, INITIAL_GRID);
    print_grid(working_grid);
    printf("\n");

    // Test cases matching the blobs in Figure 9.27
    printf("Testing individual blob queries (fresh grid for each query):\n");

    // Test 1: Blob 1 starting at (0, 4)
    reset_grid(working_grid, INITIAL_GRID);
    int size1 = blob_check(working_grid, 0, 4);
    printf("- Query blob_check at (0, 4): Size = %d cells (Blob 1)\n", size1);

    // Test 2: Blob 2 starting at (0, 1)
    reset_grid(working_grid, INITIAL_GRID);
    int size2 = blob_check(working_grid, 0, 1);
    printf("- Query blob_check at (0, 1): Size = %d cells (Blob 2)\n", size2);

    // Test 3: Blob 3 starting at (4, 2)
    reset_grid(working_grid, INITIAL_GRID);
    int size3 = blob_check(working_grid, 4, 2);
    printf("- Query blob_check at (4, 2): Size = %d cells (Blob 3)\n", size3);

    // Test 4: Query empty cell (0, 0)
    reset_grid(working_grid, INITIAL_GRID);
    int size_empty = blob_check(working_grid, 0, 0);
    printf("- Query blob_check at (0, 0): Size = %d cells (Empty cell)\n", size_empty);

    // Test 5: Query out of bounds (5, 5)
    reset_grid(working_grid, INITIAL_GRID);
    int size_oob = blob_check(working_grid, 5, 5);
    printf("- Query blob_check at (5, 5): Size = %d cells (Out of bounds)\n\n", size_oob);

    // Full grid scan to detect all distinct blobs
    printf("Scanning grid to detect all distinct blobs:\n");
    reset_grid(working_grid, INITIAL_GRID);
    int blob_count = 0;
    int total_pixels = 0;

    for (int y = GRID_SIZE - 1; y >= 0; y--) {
        for (int x = 0; x < GRID_SIZE; x++) {
            if (working_grid[y][x] == 1) {
                blob_count++;
                int b_size = blob_check(working_grid, x, y);
                total_pixels += b_size;
                printf("  -> Found Blob #%d starting at (%d, %d): Size = %d pixels\n",
                       blob_count, x, y, b_size);
            }
        }
    }
    printf("\nSummary: Total Blobs = %d, Total Pixels = %d\n", blob_count, total_pixels);

    return 0;
}
