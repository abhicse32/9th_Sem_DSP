#include <stdio.h>
#include <string.h>
void swap(char *, char *);

void permutations(char *, int, int);


void main() {
    int n, i, temp;
    scanf("%d", &n);
    char number[10];
    for (i = 0; i < n; i++) {
        scanf("%d", &temp);
        number[i] = temp + '0';
    }
    permutations(number, 0, n - 1);
}


void swap(char *p, char *q) {
    char temp;
    temp = *p;
    *p = *q;
    *q = temp;
    return;
}


void permutations(char *number, int left_index, int right_index) {
    int i;
    if (left_index < right_index) {
        for (i = left_index; i <= right_index; i++) {
            swap((number + left_index), (number + i));
            permutations(number, left_index + 1, right_index);
            swap((number + left_index), (number + i));
        }
    }
    else {
        number[strlen(number)-1]='\0';
        printf("%s ", number);
        return;
    }
    return;
}

