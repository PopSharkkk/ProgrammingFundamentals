#include <stdio.h>
#include <stdbool.h>

char buttons[16];
char current_code[16];
bool used[16];
int N;

void generate_permutations(int depth) {
    if (depth == N) {
        current_code[depth] = '\0';
        printf("%s\n", current_code);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            used[i] = true;
            current_code[depth] = buttons[i];
            generate_permutations(depth + 1);
            used[i] = false;
        }
    }
}

int main(void) {
    char s;
    if (scanf("%d %c", &N, &s) != 2) {
        return 0;
    }

    for (int i = 0; i < N; i++) {
        buttons[i] = (char)('A' + ((s - 'A' + i) % 26));
        used[i] = false;
    }

    generate_permutations(0);

    return 0;
}
