#include <stdio.h>

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
    
    int top = 0;
    int bottom = N - 1;
    int left = 0;
    int right = N - 1;
    int count = 0;
    int total_elements = N * N;
    int is_first = 1;
    
    while (count < total_elements) {
        
        for (int j = left; j <= right && count < total_elements; j++) {
            if (!is_first) {
                printf(" ");
            }
            printf("%d", matrix[top][j]);
            is_first = 0;
            count++;
        }
        top++;
        
        for (int i = top; i <= bottom && count < total_elements; i++) {
            if (!is_first) {
                printf(" ");
            }
            printf("%d", matrix[i][right]);
            is_first = 0;
            count++;
        }
        right--;
        
        for (int j = right; j >= left && count < total_elements; j--) {
            if (!is_first) {
                printf(" ");
            }
            printf("%d", matrix[bottom][j]);
            is_first = 0;
            count++;
        }
        bottom--;
        
        for (int i = bottom; i >= top && count < total_elements; i--) {
            if (!is_first) {
                printf(" ");
            }
            printf("%d", matrix[i][left]);
            is_first = 0;
            count++;
        }
        left++;
    }
    
    printf("\n");
    
    return 0;
}