/*CS15B059 KOMMURU ALEKHYA REDDY 12AUG2016
COMPARES TWO STRINGS TO CHECK IF THEY ARE ANAGRAMS*/
#include<stdio.h>
void main()
{
	char s1[100],s2[100];//declaration of the length of the two strings
	printf("Enter the two strings you want to compare\n" );
	scanf("%s %s",s1,s2);// input the two strings
	
	int arr[25];
	int i=0;
	for (i=0;i<26;i++)
		arr[i]=0;//initialise the array values to 0
	i=0;
	while(s1[i]!='\0')//condition, to check till the end of a word is reached	
	{ 
	switch(s1[i])
		{
			case 'a': arr[0]++;
				break;
			case 'b': arr[1]++;
				break;
			case 'c': arr[2]++;
				break;
			case 'd': arr[3]++;
				break;
			case 'e': arr[4]++;
				break;
			case 'f': arr[5]++;
				break;
			case 'g': arr[6]++;
				break;
			case 'h': arr[7]++;
				break;
			case 'i': arr[8]++;
				break;
			case 'j': arr[9]++;
				break;
			case 'k': arr[10]++;
				break;
			case 'l': arr[11]++;
				break;
			case 'm': arr[12]++;
				break;
			case 'n': arr[13]++;
				break;
			case 'o': arr[14]++;
				break;
			case 'p': arr[15]++;
				break;
			case 'q': arr[16]++;
				break;
			case 'r': arr[17]++;
				break;
			case 's': arr[18]++;
				break;
			case 't': arr[19]++;
				break;
			case 'u': arr[20]++;
				break;
			case 'v': arr[21]++;
				break;
			case 'w': arr[22]++;
				break;
			case 'x': arr[23]++;
				break;
			case 'y': arr[24]++;
				break;
			case 'z': arr[25]++;
				break;
		}
		i++;
	}

	

	int j=0;
		while(s2[j]!='\0')	
	{
	switch(s2[j])
		{
			case 'a': arr[0]--;
				break;
			case 'b': arr[1]--;
				break;
			case 'c': arr[2]--;
				break;
			case 'd': arr[3]--;
				break;
			case 'e': arr[4]--;
				break;
			case 'f': arr[5]--;
				break;
			case 'g': arr[6]--;
				break;
			case 'h': arr[7]--;
				break;
			case 'i': arr[8]--;
				break;
			case 'j': arr[9]--;
				break;
			case 'k': arr[10]--;
				break;
			case 'l': arr[11]--;
				break;
			case 'm': arr[12]--;
				break;
			case 'n': arr[13]--;
				break;
			case 'o': arr[14]--;
				break;
			case 'p': arr[15]--;
				break;
			case 'q': arr[16]--;
				break;
			case 'r': arr[17]--;
				break;
			case 's': arr[18]--;
				break;
			case 't': arr[19]--;
				break;
			case 'u': arr[20]--;
				break;
			case 'v': arr[21]--;
				break;
			case 'w': arr[22]--;
				break;
			case'x': arr[23]--;
				break;
			case 'y': arr[24]--;
				break;
			case 'z': arr[25]--;
				break;
			
		}
		j++;
	}//is more efficient this way rather than comparing the elements because it is O(n).
	//each array element is incremented by 1 and then decremented again when a letter is encountered

	int flag=1,count;
	for(count=0;count<26;count++)
		{
			if(arr[count]!=0)
				flag=0;//the array is checked to see if any element has a non zero value, if yes then the words are not anagrams
		}
	if(flag==0)
		printf("0");
	else
		printf("1");// printing the result obtained
	
}
