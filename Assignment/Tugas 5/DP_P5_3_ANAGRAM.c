#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str1[101], str2[101];
    int freq1[26] = {0}, freq2[26] = {0};
    int i;

    scanf("%100s", str1);
    scanf("%100s", str2);

    if (strlen(str1) != strlen(str2)) {
        printf("TIDAK\n");
        return 0;
    }

    for (i = 0; str1[i]; i++) {
        if (isalpha(str1[i]))
            freq1[tolower(str1[i]) - 'a']++;
    }
    for (i = 0; str2[i]; i++) {
        if (isalpha(str2[i]))
            freq2[tolower(str2[i]) - 'a']++;
    }

    for (i = 0; i < 26; i++) {
        if (freq1[i] != freq2[i]) {
            printf("TIDAK\n");
            return 0;
        }
    }

    printf("YA\n");
    return 0;
}
