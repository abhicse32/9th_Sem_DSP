#include<stdio.h>
int main()
{
	int n;
	int i;
	scanf("%d",&n); //Num of elements
	int num[n+1];
	//Take elements as input
	for(i=0;i<n;i++)
        	scanf("%d",&num[i]);

	int win[(n+1)/2],los[(n+1)/2];
	int posw=0,posl=0; //represent position for storing in winners and losers array
	int max=0,min;
	
	// If no of ele is odd add extra element at array end as we are taking pairs
	if(n%2!=0)
		num[n]= num[n-1] ;
	
	//Compare pairwise and find 1st round winners and losers --n/2
	for(i=0;i< n;i=i+2)
	{
		if(num[i]>num[i+1])
		{
			win[posw] = num[i];
			los[posl] = num[i+1] ;
			posw++; 
			posl++;
		}
		else
		{
			win[posw] = num[i+1];
			los[posl] = num[i] ;
			posw++; 
			posl++;
		}
	}
	
	//find max in win arr --> n/2 -1
	max = win[0] ;
	for(i=1;i<posw;i++)
	{
		if(max < win[i])
			max= win[i];
	}	
	
	//find min in los arr -- n/2 -1
	min = los[0] ;
	for(i=1;i<posl;i++)
	{
		if(min > los[i])
			min= los[i];
	}
	printf("%d %d\n",min,max); 
}
