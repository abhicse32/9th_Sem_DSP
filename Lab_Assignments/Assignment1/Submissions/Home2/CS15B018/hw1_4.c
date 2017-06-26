#include <stdio.h>
//CHECKING ANAGRAMS
int Ana(char [], char []);
int main()
{
	char a[100], b[100];
	int i;
 
	scanf("%s",&a);
	scanf("%s",&b);

	i = Ana(a, b);
 
	if (i == 1)	printf("1\n");
	
	else		printf("0\n");
	
	return 0;
}
 
int Ana(char a[], char b[])
{
	int x[26] = {0}, y[26] = {0}, z = 0;
 
	while (a[z] != '\0')
	{
		x[a[z]-'a']++;
		z++;
	}
 
	z = 0;
 
	while (b[z] != '\0')
	{
		y[b[z]-'a']++;
		z++;
	}
 
	for (z = 0; z < 26; z++)
	{
		if (x[z] != y[z])
		return 0;
	}
 
		return 1;
}

