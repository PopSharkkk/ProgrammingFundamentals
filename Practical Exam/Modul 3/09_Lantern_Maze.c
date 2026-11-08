#include <stdio.h>
#include <stdbool.h>

#define MAX_DIM 105

int R, C;
char grid[MAX_DIM][MAX_DIM];
bool visited[MAX_DIM][MAX_DIM];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool dfs(int r, int c) {
    if (grid[r][c] == 'E') {
        return true;
    }

    visited[r][c] = true;

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
            if (!visited[nr][nc] && grid[nr][nc] != '#') {
                if (dfs(nr, nc)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main(void) {
    if (scanf("%d %d", &R, &C) != 2) {
        return 0;
    }

    int start_r = -1, start_c = -1;

    for (int i = 0; i < R; i++) {
        scanf("%s", grid[i]);
        for (int j = 0; j < C; j++) {
            visited[i][j] = false;
            if (grid[i][j] == 'S') {
                start_r = i;
                start_c = j;
            }
        }
    }

    if (start_r != -1 && dfs(start_r, start_c)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
