#include <stdio.h>
#include <string.h>


void reverse(char *word);

void cyclicshift(char *a, int shift_value, int max_size);


void main() {
    int number, remainder, i = 0;
    char hexa[8] = {'0'};
    scanf("%d", &number);
    do {
        remainder = number % 16;
        if (remainder <= 9)
            hexa[i++] = (char) (remainder + 48);
        else
            hexa[i++] = (char) (remainder + 87);
        number /= 16;
    } while (number > 0);
    reverse(hexa);
    printf("0x%s\n", hexa);
}

void reverse(char *word) {
    int i = 0, j = (int) strlen(word) - 1;
    char temp;
    while (i < j) {
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
        i++;
        j--;
    }
    cyclicshift(word, 8 - (int) strlen(word), 8);
    return;
}

void cyclicshift(char *a, int shift_value, int max_size) {
    char *number = a;
    int i;
    if (shift_value > 0) {
        for (i = max_size - 1; i >= shift_value; i--) {
            number[i] = number[i - (shift_value)];
        }
        for (i = shift_value - 1; i >= 0; i--)
            number[i] = '0';
    }
    else if (shift_value < 0) {
        shift_value = -shift_value;
        for (i = 0; i < max_size - shift_value; i++) {
            number[i] = number[i + (shift_value)];
        }
        for (i = max_size - shift_value; i < max_size; i++)
            number[i] = 0;
    }
    return;
}
