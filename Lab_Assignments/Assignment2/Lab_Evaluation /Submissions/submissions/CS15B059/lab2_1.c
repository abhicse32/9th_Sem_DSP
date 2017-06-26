/*CS15B059 KOMMURU ALEKHYA REDDY 18AUG2016
TO COMPARE THE RECURSIVE AND ITERATIVE TIME TO FIND N NUMBERS OF THE FIBONACCI SERIES*/
#include<stdio.h>
#include<sys/time.h>//header file to get the time taken for execution
int fibRec(int num);
int fibIte(int num);//defining the function prototypes
void main()
	{
		struct timeval t1,t2;
		FILE *fp;//output printed in the file fp
		fp=fopen("output.csv","w");//the csv file where it is printed
		int no,i,f;
		printf("Enter the number of fibonacci numbers to be printed");
		scanf("%d",&no);//to accept the number of inputs
		//for(i=1;i<=no;i++)
		//{	
		//	printf("%d ",fibRec(i));//printing the numbers recursively	 
		//}
		
		for(i=1;i<=20;i++)
		{	
			gettimeofday(&t1,NULL);
			f=fibIte(i);
			gettimeofday(&t2,NULL);//to get the time using recursion
			double timetakenit=(double)(t2.tv_usec-t1.tv_usec)+(t2.tv_sec-t1.tv_sec)*1000000;
			fprintf(fp,"%lf,",timetakenit);//printing the times into the csv file
			gettimeofday(&t1,NULL);
			f=fibRec(i);
			gettimeofday(&t2,NULL);//getting the time using iteration
			double timetakenrec=(double)(t2.tv_usec-t1.tv_usec)+(t2.tv_sec-t1.tv_sec)*1000000;
			fprintf(fp,"%lf,\n",timetakenrec);//printing the time into the csv file
			
			 
		}
			//printf("\n");
			
			
		//for(i=1;i<=no;i++)
		//{
		//	printf("%d ",fibIte(i));//printing the fibonacci series using iteration
		//}
		
		
	}
	
//recursive code for fibonacci series,returns 1 for the base cases 
int fibRec(int num)
{
	if(num==1)
		return 1;
	else if(num==2)
		return 1;
	else 
		return(fibRec(num-1)+fibRec(num-2));

}

//iterative code
int fibIte(int num)
{
	int sum=2,i;
	int first=1,second=1;
	if(num==1)
		return 1;
	else if(num==2)
		{
		return 1;
		}
		
	else 
	{for(i=3;i<=num;i++)
		{ 
	           sum=first+second;//by definition of the fibonacci series
		   first=second;//the first number is assigned the value of the second number 
		   second=sum;//the second number has the value of the previous two numbers which is nothing but the sum 
		   
		}
	 return(sum);// returns the sum
	}
	}	

