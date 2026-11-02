#include <stdio.h>

int main() {
    int N;
    
    if (scanf("%d", &N) != 1) {
        return 1;
    }
    
    int matrix[10][10];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                return 1;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        printf("%d", matrix[i][i]);
        if (i < N - 1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}