#include <stdio.h>
#include <string.h>

#define MAX_STR 256

/*
 * Function: is_element
 * --------------------
 * Helper function to determine if character c belongs to string set.
 * Returns 1 if present, 0 otherwise.
 */
int is_element(char c, const char *set) {
    while (*set != '\0') {
        if (c == *set) {
            return 1;
        }
        set++;
    }
    return 0;
}

/*
 * Function: replace_first_x
 * -------------------------
 * Helper function that builds two strings based on its input argument.
 * In s0, the first 'x' or 'X' is replaced by '0'.
 * In s1, the first 'x' or 'X' is replaced by '1'.
 *
 * Returns:
 *   1 if an 'x' was found and replaced,
 *   0 if no 'x' was present in the input string.
 */
int replace_first_x(const char *src, char *s0, char *s1) {
    int len = strlen(src);
    int first_x_idx = -1;

    for (int i = 0; i < len; i++) {
        if (is_element(src[i], "xX")) {
            first_x_idx = i;
            break;
        }
    }

    if (first_x_idx == -1) {
        return 0; // No 'x' found
    }

    strcpy(s0, src);
    strcpy(s1, src);

    s0[first_x_idx] = '0';
    s1[first_x_idx] = '1';

    return 1;
}

/*
 * Function: display_binary_patterns
 * ---------------------------------
 * Recursive function that displays all binary numbers represented
 * by a pattern of '0's, '1's, and 'x's.
 */
void display_binary_patterns(const char *pattern, int *count) {
    char s0[MAX_STR];
    char s1[MAX_STR];

    // Base case: No 'x' remains in the string -> display binary number
    if (!replace_first_x(pattern, s0, s1)) {
        (*count)++;
        printf("  [%2d] %s\n", *count, pattern);
        return;
    }

    // Recursive case: Expand first 'x' into 0, then into 1
    display_binary_patterns(s0, count);
    display_binary_patterns(s1, count);
}

// Wrapper function to run test cases cleanly
void test_pattern(const char *pattern) {
    int count = 0;
    printf("Pattern: \"%s\"\n", pattern);
    printf("Generated binary numbers:\n");
    display_binary_patterns(pattern, &count);
    printf("Total combinations: %d\n\n", count);
}

int main() {
    printf("====================================================\n");
    printf("  PROGRAM 7: RECURSIVE BINARY PATTERN GENERATOR     \n");
    printf("  Name: Rinaltra Nabasa Simanungkalit | NRP: 5025251024\n");
    printf("====================================================\n\n");

    // Example 1 from problem statement: "1x0x" -> 1000, 1001, 1100, 1101
    printf("[Example 1 from Question]\n");
    test_pattern("1x0x");

    // Example 2 from problem statement: "xx1" -> 001, 011, 101, 111
    printf("[Example 2 from Question]\n");
    test_pattern("xx1");

    // Additional test cases
    printf("[Additional Test Case 3]\n");
    test_pattern("10x");

    printf("[Additional Test Case 4]\n");
    test_pattern("x1x0");

    return 0;
}
