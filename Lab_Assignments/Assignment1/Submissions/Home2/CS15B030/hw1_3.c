#include <stdio.h>
#include <math.h>

int isPrime(int num) {
	if (num == 2) {
		return 1;
	}
	if (num % 2 == 0) {
		return 0;
	}

	int rtnum = sqrt(num);
	int i;
	for (i = 3; i <= rtnum; i += 2) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int num1, num2;
	scanf("%d%d", &num1, &num2);
	int i;
	int cmp = num1 / 2;
	if (cmp < num2 / 2) {
		cmp = num2 / 2;
	}
	for (i = 2; i <= cmp; i++) {
		if (num1 % i == 0 && num2 % i == 0) {
			if (isPrime(i) == 1) {
				printf("%d ", i);
			}
		}
	}
	printf("\n");
	return 0;
}
