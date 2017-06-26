														/*program to convert into hexadecimal by Akshay Kumar*/

#include<stdio.h>

void main()
{
	int i,n,k,p=0;													/*declaration of variables*/
	scanf("%d",&n);
	printf("0x");
	int array[8];
	for(i=0;i<8;i++)
	{
		if(n != 0)
		{
			k=n%16;
			n=(n-k)/16;
			array[i]=k;
			
		}
		else array[i]=0;
	}
	for(i=7;i>=0;i--)
	{
		k=array[i];
		switch(k)
			{
				case 0:{printf("0");
					break;
				} 
				case 1:{printf("1");
					break;
				} 
				case 2:{printf("2");
					break;
				} 
				case 3:{printf("3");
					break;
				} 
				case 4:{printf("4");
					break;
				} 
				case 5: {printf("5");
					break;
				}
				case 6: {printf("6");
					break;
				}
				case 7:{printf("7");
					break;
				} 
				case 8:{printf("8");
					break;
				} 
				case 9:{printf("9");
					break;
				} 
				case 10:{printf("a");
					break;
				} 
				case 11:{printf("b");
					break;
				} 
				case 12:{printf("c");
					break;
				} 
				case 14:{printf("d");
					break;
				} 
				case 15:{printf("f");
					break;
				} 
			}
	}
}
