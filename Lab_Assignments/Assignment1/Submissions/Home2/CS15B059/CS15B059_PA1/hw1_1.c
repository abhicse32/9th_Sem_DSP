/*CS15B059 KOMMURU ALEKHYA REDDY  DATE:12AUG2016
TO FIND THE MAXIMUM AND THE NEXT MAXIMUM ELEMENT IN AN ARRAY*/
#include<stdio.h>
#include<stdlib.h>
void comp(int * check,int a);// defining the function prototype
void main()
{
	int no,count;
	scanf("%d",&no);//input the number of elements in the array from the user
	int *arr=(int *)malloc(sizeof(int)*(2*no-1));//defining the array
	for(count=2*no-2;count>=(no-1);count--)
		{
			scanf("%d",&arr[count]);//input all the elements into the array
		}
	int set=no-2;//set is used to assign the unassigned spaces of the array
	count=2*no-2;//count compares the two elements and assigns the larger one to set
	while(set>=0)
		{
			if(arr[count]>arr[count-1])
				arr[set]=arr[count];
			else
				arr[set]=arr[count-1];
			set--;
			count=count-2;
		}// reassigning the elements

	int temp,index=1;
	
	if(arr[0]==arr[1])
		{temp=arr[2];
		index=2;}
	else
		{temp=arr[1];
		index=3;}//checking for the largest number and assigning a value to temp, the next largest number
     

	while(2*index-1<=(2*no-1))
		{
			if(arr[index-1]==arr[2*(index)-1])
			{				
				if(temp<arr[2*index])
				temp=arr[2*index];
				index=2*index;//swap elements if a number previously compared with the largest number is greater than temp
			}
			else 
			{
				if(temp<arr[2*index-1])
				temp=arr[2*index-1];
				index=2*index+1;
			}
		
		
		}
	
	printf("%d %d",arr[0],temp);//printing the largest and the next largest number
}


