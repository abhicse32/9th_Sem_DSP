//Finding Maximum and Minimum: B Arjun CS15B058 08/08/16

#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	
	int i,j,n,min,max;	//i and j are loop variables
	scanf("%d",&n);		
	int *data=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",(data+i));
	}

	int *win=(int*)malloc(((n/2)+1)*sizeof(int));	// n/2+1 is used in case the array has odd number of elements
	int *lose=(int*)malloc(((n/2)+1)*sizeof(int));

	/* We use two arrays, win and lose. From the array data we take 2 elements at a time, and the higher is stored in win and lower is stored in loser sequentially. If the number of elements is odd, we check pairs of elements untill the second last element and then store the last element in both arrays*/
	j=0;
	if(n%2==0)
	{
		for(i=0;i<n;i+=2)
		{
			if(data[i]>data[i+1])
				{
					win[j]=data[i];
					lose[j]=data[i+1];
					j++;
				}
			else
				{
					win[j]=data[i+1];
					lose[j]=data[i];
					j++;
				}
			
		}
	}
	else
	{
		for(i=0;i<n-1;i+=2)
		{
			if(data[i]>data[i+1])
				{
					win[j]=data[i];
					lose[j]=data[i+1];
					j++;
				}
			else
				{
					win[j]=data[i+1];
					lose[j]=data[i];
					j++;
				}
			
		}
	win[j]=data[n-1];
	lose[j]=data[n-1];
	j++;
	}
/*wlcount contains the number of elements in both win and lose arrays. After isolating the win and lose arrays, we linearly find the maximum from win and minimum from lose, which is the same as the maximum and minimum of the array*/	
	int wlcount=j;
	max=win[0];
	min=lose[0];
	for(i=0;i<wlcount;i++)
	{
		if(win[i]>max)
		max=win[i];
		if(lose[i]<min)
		min=lose[i];
	}
	printf("%d %d",min,max);

}
