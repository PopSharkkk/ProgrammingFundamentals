#include <stdio.h>

int main() {
    int N;
    
    if (scanf("%d", &N) != 1) {
        return 1;
    }
    
    int arr[100];
    int count[2001] = {0};
    int offset = 1000;
    
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            return 1;
        }
        count[arr[i] + offset]++;
    }
    
    int is_first = 1;
    int found_unique = 0;
    
    for (int i = 0; i < N; i++) {
        if (count[arr[i] + offset] == 1) {
            if (!is_first) {
                printf(" ");
            }
            printf("%d", arr[i]);
            is_first = 0;
            found_unique = 1;
        }
    }
    
    if (!found_unique) {
        printf("-");
    }
    
    printf("\n");
    
    return 0;
}