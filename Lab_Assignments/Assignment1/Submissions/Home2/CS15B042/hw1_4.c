#include <stdio.h>
#include <string.h>
#define MAX 100
int main(){
	char s1[MAX],s2[MAX];
	int a[26] = {0};
	int b[26] = {0};
	int i;
	fscanf(stdin,"%s %s",s1,s2);
	for(i = 0;i < strlen(s1);i++)  a[(int)s1[i] - 97]++;
	for(i = 0;i < strlen(s2);i++)  b[(int)s2[i] - 97]++;
	int x = 1;
	for(i = 0;i < 26;i++){
		if(a[i] != b[i]) x = 0;
	}
	printf("%d\n",x);
	return 0;
}
