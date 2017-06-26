#include <stdio.h>

int main() {
	int arr1[26], arr2[26];
	int i;
	for (i = 0; i < 26; i++) {
		arr1[i] = arr2[i] = 0;
	}

	char c;
	scanf("%c", &c);
	while (c != ' ') {
		arr1[c-97]++;
		scanf("%c", &c);
	}

	scanf("%c", &c);
	while (c != '\n') {
		arr2[c-97]++;
		scanf("%c", &c);
	}

	for (i = 0; i < 26; i++) {
		if (arr1[i] != arr2[i]) {
			printf("0\n");
			return 0;
		}
	}
	printf("1\n");
	return 0;
}
