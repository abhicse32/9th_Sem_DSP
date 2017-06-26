#include <stdio.h>

int main() {
	int dec_num;
	scanf("%d", &dec_num);
	int hex_arr[8];
	int i, j;
	for (i = 0; i < 8; i++) {
		hex_arr[i] = dec_num % 16;
		dec_num = dec_num / 16;
		if (dec_num == 0) {
			break;
		}
	}
	printf("0x");
	for (j = 0; j < 7 - i; j++) {
		printf("0");
	}
	for (j = i; j >= 0; j--) {
		if (hex_arr[j] < 10) {
			printf("%d", hex_arr[j]);
		} else {
			printf("%c", hex_arr[j]+87);
		}
	}
	printf("\n");
	return 0;
}
