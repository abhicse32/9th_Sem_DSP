#include <stdio.h>

long double sqrt(long double );

void main() {
    long double number;
    scanf("%llf", &number);
    printf("%.15llf\n", sqrt(number));

}

long double sqrt(long double number) {
    long double guessed_root = number / 2, better_root;
    better_root = 0.5 * (guessed_root + number / guessed_root);
    while (guessed_root != better_root) {
        guessed_root = better_root;
        better_root = 0.5 * (guessed_root + number / guessed_root);
    }
    return better_root;
}