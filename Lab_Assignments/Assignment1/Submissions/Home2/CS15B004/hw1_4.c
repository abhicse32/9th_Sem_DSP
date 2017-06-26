#include<stdio.h>
#include<string.h>

int main()
{
	char str1[101],str2[101];
	scanf("%s %s", str1, str2);
	//printf("%c",str1[2]);

	int j,i=0;

	if(strlen(str1)!=strlen(str2))
	{	printf("0");
		return 0;
	}
	
	char a;
	int flag=0;

	while(str1[i]!='\0')
	{
		a=str1[i];
		flag=0;							//reinitialise flag to 0
		j=0;
		while(str2[j]!='\0')
		{
			if(str2[j]==a)
			{
				str2[j]='0'; 		 
				flag=1;
				break;
			}

			j++;
		}


		if(flag==0)						//if a was not matched with any of str2, end
		{	printf("0");
			return 0;
		}	
			
		i++;
	}

	printf("1");
	
	return 0;
}