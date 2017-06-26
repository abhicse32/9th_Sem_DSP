/* Author: G.Kavitha
Roll Number: CS15B057
Date: 11-08-16 */
#include <stdio.h>
typedef long long int l;//Creating an alias l for datatype long long int
int main(){
	l n;//Hold the number for which we need to find the hexadecimal equivalent
	scanf("%lld",&n);//Reads in n

	char ans[11];//Character array that holds the answer i.e. hexedecimal equivalent
	ans[0]='0';
	ans[1]='x';//The answer begins with "0x"
	
	int i;
	for(i=2;i<10;i++) ans[i]='0';//Setting others to '0'
	
	ans[10]='\0';//Setting the null character to show that it is the end of the string
	
	i=9;
	while(n!=0){
		/*If the equivalent value is an integer less than 10, 
		then integer is set as itself
 		If the equivalent integer is more than equal to 10, 
 		then the corresponding letter from a to f is set*/
		if((n%16)<=9) ans[i]=(n%16)+'0';
		else ans[i]=(n%16)-10+'a';
		i--;
		n/=16; 
	}
	printf("%s\n",ans);//Displaying the answer
	return 0;
}