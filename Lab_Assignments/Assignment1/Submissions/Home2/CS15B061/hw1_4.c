/*
 * =====================================================================================
 *
 *
 *    Description:  To Check if two Strings are anagrams
 *
 *       
 *
 *         Author: Harshavardhan.P.K. 
 *
 * 	  Roll No: CS15B061
 * =====================================================================================
 */

#include <stdio.h>
#define MAXLEN 100

short chkanagrams(char *, char *, unsigned int);


/*
 * =====================================================================================
 *	Main Functions
 *	Inputs the strings and checks its sizes. 
 *	Output: prints 1 if strings are anagrams, else prints 0.
 *  Note: Whitespace characters signify end of string
 * =====================================================================================
 */
int main (void){
	char ar1[MAXLEN], ar2[MAXLEN];
	scanf ("%s%s",ar1,ar2);
	int i=0;
	unsigned int len=0;
	while (ar1[i]!='\0'){
		len++; i++;
	}
	
	printf("%d\n",chkanagrams(ar1, ar2, len));

	return 0;

}


/*
 * =====================================================================================
 *	chkanagrams Functions: to check if a1 and a2 of length l each are anagrams.
 *	Inputs :
 *	a1, a2: two strings for comparison
 *	l: length of a1 and a2
 *	Output: 1 if a1 and a2 are anagrams else return 0.
 * =====================================================================================
 */

short chkanagrams(char *a1, char *a2, unsigned int l){
	int c1[256], c2[256], i;

	/*
		Makes an arrays c1 and c2 to hold no. of occurences of each ascii character in a1 and a2 respectively.

	*/
	for (i=0;i<256;i++){
		c1[i]=c2[i]=0;
		
	}

	/*
		Checks every character of ar1 and ar2 and increments curresponding counters in c1 and c2 respectively.
	*/
	for(i=0; i<(int)l; i++){
		c1[(int)a1[i]]++;
		c2[(int)a2[i]]++;
	}

	/*
		Checks if no. of occurences of characters of each type is same in ar1 and ar2.
	*/
	for (i=0; i<256; i++){
		if(c1[i] != c2[i])
			return 0;
	}
	return 1;
}
