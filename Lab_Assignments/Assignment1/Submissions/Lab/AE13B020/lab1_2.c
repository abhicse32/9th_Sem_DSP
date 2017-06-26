#include<stdio.h>

void main() {
    int i, min, max, n;
    scanf("%d", &n);
    int array[n];
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    if (!(n & 1)) {
        if (array[0] < array[1]) {
            min = array[0];
            max = array[1];
        }
        else {
            min = array[1];
            max = array[0];
        }
    }
    else {
        min = array[0];
        max = array[0];
    }
    for (i = 1; i < n - 1; i += 2) {
        if (array[i] < array[i + 1]) {
            if (min > array[i])
                min = array[i];
            if (max < array[i + 1])
                max = array[i + 1];
        }
        else {
            if (min > array[i + 1])
                min = array[i + 1];
            if (max < array[i])
                max = array[i];
        }
    }
    printf("%d %d\n", min, max);
}