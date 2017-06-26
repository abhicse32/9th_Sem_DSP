
/* 
	Home Assignment1_3 question
	CS15B049 lokesh koshale

*/

#include<stdio.h>
#include<string.h> 		//including string library file

int main()
{
	/*declaring array of strings*/
	char str1[101];
	char str2[101];
	
	scanf("%s %s",&str1,&str2);   // scanning strings
	
	int i,j;					// counter variables
	int flag;					
	
	/*comparing the lengths of strings*/
	if(strlen(str1)!=strlen(str2))
	{
		printf("0");
	}
	else
	{
		for(i=0; str1[i]!='\0';i++)		// until the last char
		{
			flag=0;
		
			for(j=0; (str2[j]!='\0') ;j++)
			{
				if(str2[j]==str1[i])		// comparing each element of str1 to all element od str2
				{
					flag=1;
					break;
				}
			
			}
		
			if(flag==0)
			{
				break;
			}
		
		} // end for
		
		
		/* printing the output */
		if(flag==1)
		{
			printf("1");
		}
		else
		{	
			printf("0");
		}
	
	} 		//end else
	
	
		return 0;
		
}		// end main 
