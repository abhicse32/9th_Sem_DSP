/*CS15B059 KOMMURU ALEKHYA REDDY 12AUG2016
TO PRINT THE SQAURE ROOT OF A NUMBER CORRECT TO 15 PLACES AFTER THE DECIMAL POINT*/
#include<stdio.h>
#include<math.h>
int main()
{
	int no;
	scanf("%d",&no);//input the number to find its square root
         if(no>10000)
		return -1;

	int arr[36];
	if((no/10000)!=0)
		{
			arr[0]=0;
			arr[1]=1;
			arr[2]=0;
			arr[3]=0;
			arr[4]=0;
			arr[5]=0;
		}
	else if((no/1000)!=0)
		{
			arr[0]=0;
			arr[1]=0;
			arr[2]=no/1000;
			arr[3]=(no/100)%10;
			arr[4]=(no/10)%10;
			arr[5]=(no%10);
		}
	else if((no/100)!=0)
		{
			arr[0]=0;
			arr[1]=0;
			arr[2]=0;
			arr[3]=no/100;
			arr[4]=(no/10)%10;
			arr[5]=no%10;
		}
	else if((no/10)!=0)
		{
			arr[0]=0;
			arr[1]=0;
			arr[2]=0;
			arr[3]=0;
			arr[4]=no/10;
			arr[5]=no%10;
		}
	else if((no/1)!=0)
		{
			arr[0]=0;
			arr[1]=0;
			arr[2]=0;
			arr[3]=0;
			arr[4]=0;
			arr[5]=no;
		}//assigning the integral part of the root 
	int i;
	for(i=6;i<37;i++)
		arr[i]=0;//assigning the rest of the elements after the decimal point to 0
	
	
	
     
	long int div=0,quo=0,rem=0;//defining the divisor, quotient and remainder variables
	int check;
	
	for(i=0;i<6;i=i+2)
	{
	if(((((div+quo%10)*10+0)*0)<=(100*rem+arr[i]*10+arr[i+1]))&&((100*rem+arr[i]*10+arr[i+1])<((div+quo%10)*10+1)*1))
		check=0;
	else if(((((div+quo%10)*10+1)*1)<=(100*rem+arr[i]*10+arr[i+1]))&&((100*rem+arr[i]*10+arr[i+1])<((div+quo%10)*10+2)*2))
		check=1;
	else if(((((div+quo%10)*10+2)*2)<=(100*rem+arr[i]*10+arr[i+1]))&&((100*rem+arr[i]*10+arr[i+1])<((div+quo%10)*10+3)*3))
		check=2;
	else if(((((div+quo%10)*10+3)*3)<=(100*rem+arr[i]*10+arr[i+1]))&&((100*rem+arr[i]*10+arr[i+1])<((div+quo%10)*10+4)*4))
		check=3;
	else if(((((div+quo%10)*10+4)*4)<=(100*rem+arr[i]*10+arr[i+1]))&&((100*rem+arr[i]*10+arr[i+1])<((div+quo%10)*10+5)*5))
		check=4;
	else if(((((div+quo%10)*10+5)*5)<=(100*rem+arr[i]*10+arr[i+1]))&&((100*rem+arr[i]*10+arr[i+1])<((div+quo%10)*10+6)*6))
		check=5;
	else if(((((div+quo%10)*10+6)*6)<=(100*rem+arr[i]*10+arr[i+1]))&&((100*rem+arr[i]*10+arr[i+1])<((div+quo%10)*10+7)*7))
		check=6;
	else if(((((div+quo%10)*10+7)*7)<=(100*rem+arr[i]*10+arr[i+1]))&&((100*rem+arr[i]*10+arr[i+1])<((div+quo%10)*10+8)*8))
		check=7;
	else if(((((div+quo%10)*10+8)*8)<=(100*rem+arr[i]*10+arr[i+1]))&&((100*rem+arr[i]*10+arr[i+1])<((div+quo%10)*10+9)*9))
		check=8;
	else if(((((div+quo%10)*10+9)*9)<=(100*rem+arr[i]*10+arr[i+1])))
		check=9;
	
	
	switch(check)
		{	
			
			case 0:
					div=(div+quo%10)*10+0;
					quo=quo*10+0;
					rem=100*rem+(arr[i]*10+arr[i+1])-(div*0);
					break;
				
			case 1:
					div=(div+quo%10)*10+1;
					quo=quo*10+1;
					rem=100*rem+(arr[i]*10+arr[i+1])-(div*1);
					break;
				
			case 2:
					div=(div+quo%10)*10+2;
					quo=quo*10+2;
					rem=100*rem+(arr[i]*10+arr[i+1])-(div*2);
					break;
			case 3:
					div=(div+quo%10)*10+3;
					quo=quo*10+3;
					rem=100*rem+(arr[i]*10+arr[i+1])-(div*3);
					break;
			case 4:
					div=(div+quo%10)*10+4;
					quo=quo*10+4;
					rem=100*rem+(arr[i]*10+arr[i+1])-(div*4);
					break;
			case 5:
					div=(div+quo%10)*10+5;
					quo=quo*10+5;
					rem=100*rem+(arr[i]*10+arr[i+1])-(div*5);
					break;
			case 6:
					div=(div+quo%10)*10+6;
					quo=quo*10+6;
					rem=100*rem+(arr[i]*10+arr[i+1])-(div*6);
					break;
			case 7:
					div=(div+quo%10)*10+7;
					quo=quo*10+7;
					rem=100*rem+(arr[i]*10+arr[i+1])-(div*7);
					break;
			case 8:
					div=(div+quo%10)*10+8;
					quo=quo*10+8;
					rem=100*rem+(arr[i]*10+arr[i+1])-(div*8);
					break;
			case 9:
					div=(div+quo%10)*10+9;
					quo=quo*10+9;
					rem=100*rem+(arr[i]*10+arr[i+1])-(div*9);
					break;
		
	}//performing long division by the conventional method
}
		
                 printf("%ld.",quo);//printing the number before the decimal point
		
		

                for(i=6;i<36;i=i+2)
	{
		
		
	if(((((div+quo%10)*10+0)*0)<=(100*rem+arr[i]*10+arr[i+1]))&&((100*rem+arr[i]*10+arr[i+1])<((div+quo%10)*10+1)*1))
		check=0;
	else if(((((div+quo%10)*10+1)*1)<=(100*rem+arr[i]*10+arr[i+1]))&&((100*rem+arr[i]*10+arr[i+1])<((div+quo%10)*10+2)*2))
		check=1;
	else if(((((div+quo%10)*10+2)*2)<=(100*rem+arr[i]*10+arr[i+1]))&&((100*rem+arr[i]*10+arr[i+1])<((div+quo%10)*10+3)*3))
		check=2;
	else if(((((div+quo%10)*10+3)*3)<=(100*rem+arr[i]*10+arr[i+1]))&&((100*rem+arr[i]*10+arr[i+1])<((div+quo%10)*10+4)*4))
		check=3;
	else if(((((div+quo%10)*10+4)*4)<=(100*rem+arr[i]*10+arr[i+1]))&&((100*rem+arr[i]*10+arr[i+1])<((div+quo%10)*10+5)*5))
		check=4;
	else if(((((div+quo%10)*10+5)*5)<=(100*rem+arr[i]*10+arr[i+1]))&&((100*rem+arr[i]*10+arr[i+1])<((div+quo%10)*10+6)*6))
		check=5;
	else if(((((div+quo%10)*10+6)*6)<=(100*rem+arr[i]*10+arr[i+1]))&&((100*rem+arr[i]*10+arr[i+1])<((div+quo%10)*10+7)*7))
		check=6;
	else if(((((div+quo%10)*10+7)*7)<=(100*rem+arr[i]*10+arr[i+1]))&&((100*rem+arr[i]*10+arr[i+1])<((div+quo%10)*10+8)*8))
		check=7;
	else if(((((div+quo%10)*10+8)*8)<=(100*rem+arr[i]*10+arr[i+1]))&&((100*rem+arr[i]*10+arr[i+1])<((div+quo%10)*10+9)*9))
		check=8;
	else if(((((div+quo%10)*10+9)*9)<=(100*rem+arr[i]*10+arr[i+1])))
		check=9;
	  
	switch(check)
		{	
		
			case 0:
					div=(div+quo%10)*10+0;
					quo=quo*10+0;
					rem=100*rem+(arr[i]*10+arr[i+1])-(div*0);
					break;
				
			case 1:
					div=(div+quo%10)*10+1;
					quo=quo*10+1;
					rem=100*rem+(arr[i]*10+arr[i+1])-(div*1);
					break;
				
			case 2:
					div=(div+quo%10)*10+2;
					quo=quo*10+2;
					rem=100*rem+(arr[i]*10+arr[i+1])-(div*2);
					break;
			case 3:
					div=(div+quo%10)*10+3;
					quo=quo*10+3;
					rem=100*rem+(arr[i]*10+arr[i+1])-(div*3);
					break;
			case 4:
					div=(div+quo%10)*10+4;
					quo=quo*10+4;
					rem=100*rem+(arr[i]*10+arr[i+1])-(div*4);
					break;
			case 5:
					div=(div+quo%10)*10+5;
					quo=quo*10+5;
					rem=100*rem+(arr[i]*10+arr[i+1])-(div*5);
					break;
			case 6:
					div=(div+quo%10)*10+6;
					quo=quo*10+6;
					rem=100*rem+(arr[i]*10+arr[i+1])-(div*6);
					break;
			case 7:
					div=(div+quo%10)*10+7;
					quo=quo*10+7;
					rem=100*rem+(arr[i]*10+arr[i+1])-(div*7);
					break;
			case 8:
					div=(div+quo%10)*10+8;
					quo=quo*10+8;
					rem=100*rem+(arr[i]*10+arr[i+1])-(div*8);
					break;
			case 9:
					div=(div+quo%10)*10+9;
					quo=quo*10+9;
					rem=100*rem+(arr[i]*10+arr[i+1])-(div*9);
					break;
			
	
		}//calculating the decimal part
}
	int n;
	long p= pow(10,15);
	n=(int)((quo % p)/(p/10));
	if(n==0)
	printf("0");	
	printf("%ld",quo % p);//printing the decimal part
	return 0;
}

