#include<stdio.h>
int main()
		{
			
			int ch;
			printf("Enter the size of the array:");
			scanf("%d",&ch);
			int arr[ch];
			int j;	
			printf("Enter the elements of the array:");		
			for(j=0;j<ch;j++)
				{
					scanf("%d",&arr[j]);
				}
		

					int k,m;

				for(k=0;k<ch;k++)
				{
					int a=0;
					for(m=k+1;m<ch;m++)
						{
							if(arr[k]<arr[m])
								{
									a=arr[m];
									arr[k]=arr[m];
									arr[m]=arr[k];
								}
						}
				
			}printf("%d %d ", arr[0],arr[1]);
			
		}


