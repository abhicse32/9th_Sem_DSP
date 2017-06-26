#include<stdio.h>
#include<string.h>
int main(){
	char a[101], b[101];
	scanf("%s%s", a, b);
	int i, c[26] = {0}, d[26] = {0};
	for(i = 0; i < strlen(a); i++){
		if(a[i] == 'a') c[0]++;
		if(a[i] == 'b') c[1]++;
		if(a[i] == 'c') c[2]++;
		if(a[i] == 'd') c[3]++;
		if(a[i] == 'e') c[4]++;
		if(a[i] == 'f') c[5]++;
		if(a[i] == 'g') c[6]++;
		if(a[i] == 'h') c[7]++;
		if(a[i] == 'i') c[8]++;
		if(a[i] == 'j') c[9]++;
		if(a[i] == 'k') c[10]++;
		if(a[i] == 'l') c[11]++;
		if(a[i] == 'm') c[12]++;
		if(a[i] == 'n') c[13]++;
		if(a[i] == 'o') c[14]++;
		if(a[i] == 'p') c[15]++;
		if(a[i] == 'q') c[16]++;
		if(a[i] == 'r') c[17]++;
		if(a[i] == 's') c[18]++;
		if(a[i] == 't') c[19]++;
		if(a[i] == 'u') c[20]++;
		if(a[i] == 'v') c[21]++;
		if(a[i] == 'w') c[22]++;
		if(a[i] == 'x') c[23]++;
		if(a[i] == 'y') c[24]++;
		if(a[i] == 'z') c[25]++;
	}
	for(i = 0; i < strlen(b); i++){
		if(b[i] == 'a') d[0]++;
		if(b[i] == 'b') d[1]++;
		if(b[i] == 'c') d[2]++;
		if(b[i] == 'd') d[3]++;
		if(b[i] == 'e') d[4]++;
		if(b[i] == 'f') d[5]++;
		if(b[i] == 'g') d[6]++;
		if(b[i] == 'h') d[7]++;
		if(b[i] == 'i') d[8]++;
		if(b[i] == 'j') d[9]++;
		if(b[i] == 'k') d[10]++;
		if(b[i] == 'l') d[11]++;
		if(b[i] == 'm') d[12]++;
		if(b[i] == 'n') d[13]++;
		if(b[i] == 'o') d[14]++;
		if(b[i] == 'p') d[15]++;
		if(b[i] == 'q') d[16]++;
		if(b[i] == 'r') d[17]++;
		if(b[i] == 's') d[18]++;
		if(b[i] == 't') d[19]++;
		if(b[i] == 'u') d[20]++;
		if(b[i] == 'v') d[21]++;
		if(b[i] == 'w') d[22]++;
		if(b[i] == 'x') d[23]++;
		if(b[i] == 'y') d[24]++;
		if(b[i] == 'z') d[25]++;
	}
	int count = 0;
	for(i = 0; i < 26; i++){
		if(c[i] == d[i]) count++;
	}
	if(count == 26) printf("1\n");
	else printf("0\n");
	return 0;
}


