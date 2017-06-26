//PERMUTATION GENERATOR

#include <stdio.h>
void permute (int n,int a[n],int b[n]);    //function which is called recursively
int find(int n,int b[n]);                   //Finds the index at which value starts decreasing fron right
void swap(int i,int n,int b[n]);           //Used for swapping
void sort(int i,int n,int b[n]);           //Sorts
void Print (int n,int a[n],int b[n]);       //Prints the permutations
int main ()
{
	int n,fact=1,i;
	scanf ("%d",&n);
	int a[n],b[n];
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);         //a[n] is input array ,b[n] maps to a[n]
		b[i]=i;
	}
	
	
	permute(n,a,b);                     //function call
	return 0;
	
	
}
void permute (int n,int a[n],int b[n])
{
	int j,i;
	
	
		Print(n,a,b);
		i=find(n,b);
		if(i!=-1)                //exiting condition
		{
		swap(i,n,b);
		sort(i+1,n,b);
		permute(n,a,b);
		}
		
	
}

int find(int n,int b[n])
{
	int i;
	for(i=n-1;i>0;i--)
	{
		if(b[i-1]<b[i])
		{
			return i-1;
		}
	}
	return -1;                    //returns -1 is last permutation reaches and thus ends recursion 
}
		
void swap(int i,int n,int b[n])       //swaps the required 2 elements
{
	int j,temp,k,flag=0;
	
	for(k=1;k+b[i]<n;k++)
	{
	for(j=i;j<n;j++)
		if(b[i]+k==b[j])
		{
			temp=b[j];
			b[j]=b[i];
			b[i]=temp;
			flag=1;
			break;
		}
	if (flag==1)
		break;
	}
}


void sort(int i,int n,int b[n])          //Sorts the part of array to be sorted
{
	int j,k,temp;
	for(k=i;k<n;k++)
	for(j=i;j<n-1;j++)
		if(b[j]>b[j+1])
		{
			temp=b[j];
			b[j]=b[j+1];
			b[j+1]=temp;
		}
}

void Print (int n,int a[n],int b[n])      
{
	int j,k;
	for(j=0;j<n;j++)
	{
		k=b[j];
		printf("%d",a[k]);         //maps b[n] to a[n] and then prints it
	}
	printf (" ");
}
			
