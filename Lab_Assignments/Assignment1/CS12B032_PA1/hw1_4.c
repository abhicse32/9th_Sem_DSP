#include <stdio.h>
#include <string.h>

int isAnagram(char* str1,char* str2){
	int len1= strlen(str1);
	int len2= strlen(str2);
	int i;
	int arr[27];
	memset(arr,0,sizeof arr);
	for(i=0;i<len1;i++)
		arr[str1[i]-'a']++;
	for(i=0;i<len2;i++)
		arr[str2[i]-'a']--;
	for(i=0;i<26;i++)
		if(arr[i])
			return 0;
	return 1;
}

int main(){
	char str1[102],str2[102];
	scanf("%s%s",str1,str2);
	printf("%d\n",isAnagram(str1,str2));
}