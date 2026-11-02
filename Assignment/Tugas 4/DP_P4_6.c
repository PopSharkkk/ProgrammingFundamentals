#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    int N;
    
    if (scanf("%d", &N) != 1) {
        return 1;
    }
    
    int matrix[20][20];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                return 1;
            }
        }
    }
    
    bool is_dominant = true;
    
    for (int i = 0; i < N; i++) {
        int diagonal_val = matrix[i][i];
        int sum_others = 0;
        
        for (int j = 0; j < N; j++) {
            if (i != j) {
                sum_others += abs(matrix[i][j]); 
            }
        }
        
        if (diagonal_val <= sum_others) {
            is_dominant = false;
            break;
        }
    }
    
    if (is_dominant) {
        printf("YA\n");
    } else {
        printf("TIDAK\n");
    }
    
    return 0;
}