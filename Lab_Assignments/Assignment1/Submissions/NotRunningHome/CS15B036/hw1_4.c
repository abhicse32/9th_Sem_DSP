#include<stdio.h>
#include<string.h>
int main()
{
	char string1[50];
	char string2[50];
	char temp1;
	char temp2;
	int i;
	int j;
	scanf("%s\n",&string1);
	scanf("%s",&string2);
	if(strlen(string1)==strlen(string2))
	{
	  	for(i=0;i<strlen(string1);i++)
	  	{
	  		for(j=i;j<strlen(string2);j++)
	  		{
	  			if(string1[i]<string1[j])
	  			{
	  				temp1=string1[i];
	  				string1[i]=string1[j];
	  				string1[j]=temp1;
				  }
			  }
		  }
		for(i=0;i<strlen(string1);i++)
	  	{
	  		for(j=i;j<strlen(string2);j++)
	  		{
	  			if(string2[i]<string2[j])
	  			{
	  				temp2=string2[i];
	  				string2[i]=string2[j];
	  				string2[j]=temp2;
				  }
			  }
		  }
		if(strcmp(string1,string2)==0)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	else
	{
		printf("0");
	}
	return 0;
}
