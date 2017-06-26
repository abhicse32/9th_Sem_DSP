#include<stdio.h>

static int count = 0, countA, countB = 0, countC = 0;

void tower_of_hanoi(int, char, char, char);

void getcount(char, char);

void main() {
    int N;
    scanf("%d", &N);
    countA = N;
    tower_of_hanoi(N, 'A', 'C', 'B');
    printf("%d\n", count);
}

void getcount(char A, char B) {
    switch (B) {
        case 'A':
            countA++;
            break;
        case 'B':
            countB++;
            break;
        case 'C':
            countC++;
            break;
    }
    switch (A) {
        case 'A':
            countA--;
            break;
        case 'B':
            countB--;
            break;
        case 'C':
            countC--;
            break;
    }


}

void tower_of_hanoi(int n, char PoleA, char PoleC, char PoleB) {
    if (n == 0)
        return;
    tower_of_hanoi(n - 1, PoleA, PoleB, PoleC);
    getcount(PoleA, PoleC);
    printf("%c -> %c %d %d %d\n", PoleA, PoleC, countA, countB, countC);
    tower_of_hanoi(n - 1, PoleB, PoleC, PoleA);
    count++;
}

