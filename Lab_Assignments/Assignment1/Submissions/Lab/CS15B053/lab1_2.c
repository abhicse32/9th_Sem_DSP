/* 	Program to find minimum and maximum numbers of a set of numbers
	Author : Monisha J, CS15B053
	Date : 8 August 2016 							*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void compare(int *numbers, int n)	//Finds and prints maximum and minimum of the array
{
	int i,min,max;  
	if (n%2 == 0)
	{         
    		if (numbers[0] > numbers[1])     
    		{
      			max = numbers[0];
      			min = numbers[1];
   		 }  
    		else
    		{
      			min = numbers[0];
     			max = numbers[1];
    		}
    		i = 2;  
  	} 
	else 
	{
		min = numbers[0];
    		max = numbers[0];
    		i = 1; 
 	 }
   
 	while (i < n-1)  
	{          
		if (numbers[i] > numbers[i+1])          
		{
			if(numbers[i] > max)        
        			max = numbers[i];
      			if(numbers[i+1] < min)          
       				min = numbers[i+1];        
    		} 
    		else        
    		{
      			if (numbers[i+1] > max)        
       				max = numbers[i+1];
     			 if (numbers[i] < min)          
       				min = numbers[i];        
    		}        
   		i += 2;
 	}            
 
  printf("%d %d", min, max);	//Printing the minimum and maximum
	
}

void main()
{
	int numbers[100];
	int i,n;
	
	scanf("%d", &n); //Number of inputs
	
	for(i=0; i<n; i++)	//Reading the numbers
	{
		scanf("%d", &numbers[i]);
	}
	
	compare(numbers,n);
	
	
	
}
	
	
