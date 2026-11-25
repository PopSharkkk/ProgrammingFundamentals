#include <stdio.h>
#include <stdbool.h>

int main() {
    int M, N;
    
    if (scanf("%d %d", &M, &N) != 2) {
        return 1;
    }
    
    int matrix[50][50];
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                return 1;
            }
        }
    }
    
    bool found_identical = false;
    
    for (int i = 0; i < M; i++) {
        for (int k = i + 1; k < M; k++) {
            bool is_identical = true;
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] != matrix[k][j]) {
                    is_identical = false;
                    break;
                }
            }
            if (is_identical) {
                found_identical = true;
                break;
            }
        }
        if (found_identical) {
            break;
        }
    }
    
    if (found_identical) {
        printf("YA\n");
    } else {
        printf("TIDAK\n");
    }
    
    return 0;
}