#include <stdio.h>
#include <limits.h>

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

int main() {
	int n;
	scanf("%d", &n);
	int inp1, inp2;
	int max = INT_MIN, nextmax = INT_MIN;
	int i;

	for (i = 0; i < n - 1; i += 2) {
		scanf("%d", &inp1);
		scanf("%d", &inp2);
		if (inp1 < inp2) {
			swap(&inp1, &inp2);
		}
		if (inp1 > max) {
			nextmax = max;
			max = inp1;
			if (inp2 > nextmax)
				nextmax = inp2;
		} else if (inp1 > nextmax) {
			nextmax = inp1;
		}
	}
	if (n % 2 == 1) {
		scanf("%d", &inp1);
		if (inp1 > max) {
			nextmax = max;
			max = inp1;
		} else if (inp1 > nextmax) {
			nextmax = inp1;
		}
	}
	printf("%d %d\n", max, nextmax);
	return 0;
}
