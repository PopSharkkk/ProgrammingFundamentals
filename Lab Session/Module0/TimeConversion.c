#include <stdio.h>

int main () {
    int hour, min, sec, input;

    scanf("%d", &input);

    hour = input / 3600;
    min = (input % 3600) / 60;
    sec = (input % 3600) % 60;

    printf("%d jam %d menit %d detik\n", hour, min, sec);
}