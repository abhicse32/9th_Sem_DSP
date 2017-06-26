/* Program to implement an Abstract type of Complex numbers
   To perform basic mathematical operations on complex numbers
   
   by Chandrashekhar D   Roll no.CS15B009    8 August 2016 */


#include <stdio.h>   // Importing the required libraries
#include <math.h>

/* Structure defining a complex number:
   consists of real part and imaginary part (both of float type)*/
struct ComplexNumber  
{						
	float real;        
	float img;
};

// Initial declaration of functions:
struct ComplexNumber addComplex(struct ComplexNumber c1,struct ComplexNumber c2);
struct ComplexNumber subtractComplex(struct ComplexNumber c1,struct ComplexNumber c2);
struct ComplexNumber multiplyComplex(struct ComplexNumber c1,struct ComplexNumber c2);
struct ComplexNumber divideComplex(struct ComplexNumber c1,struct ComplexNumber c2);
float distComplex(struct ComplexNumber c1,struct ComplexNumber c2);

int main()
{
	int choice;                           
	struct ComplexNumber c1,c2,ans;  // Declaring the required variables        
	float distance;
	
	while(1)
	{
		scanf("%f %f",&c1.real,&c1.img);    // Accepting the first complex number
		scanf("%f %f",&c2.real,&c2.img);    // Accepting the second complex number
		scanf("%d",&choice);                // Accepting the user choice of operation
		
		/* Switch case construct to perform desired operation: */
		switch(choice)                      
		{
			case 1:
				ans = addComplex(c1,c2);    //Addition
				if (ans.img < 0)
					printf("%f%fi",ans.real,ans.img);
				else
					printf("%f+%fi",ans.real,ans.img);
				break;
			case 2:
				ans = subtractComplex(c1,c2);  //Subtraction
				if (ans.img < 0)
					printf("%f%fi",ans.real,ans.img);
				else
					printf("%f+%fi",ans.real,ans.img);
				break;
			case 3:
				ans = multiplyComplex(c1,c2);  //Multiplication
				if (ans.img < 0)
					printf("%f%fi",ans.real,ans.img);
				else
					printf("%f+%fi",ans.real,ans.img);
				break;
			case 4:
				ans = divideComplex(c1,c2);    //Division
				if (ans.img < 0)
					printf("%f%fi",ans.real,ans.img);
				else
					printf("%f+%fi",ans.real,ans.img);
				break;
			case 5:
				distance = distComplex(c1,c2); //Distance between the two complex numbers
				printf("%.6f",distance);
				break;
			case -1:
				return 0;
				
		}  // End of switch case construct
		
	}  // End of while loop 
	
	return 0;
	
} // End of main function

/*  Function to add two complex numbers
	Input parameters : c1,c2 (two variables of the ComplexNumber structure data type)
	Returns : out = c1 + c2 (ComplexNumber type)  */
struct ComplexNumber addComplex(struct ComplexNumber c1,struct ComplexNumber c2)
{
	struct ComplexNumber out;
	out.real = c1.real + c2.real;
	out.img = c1.img + c2.img;
	return out;
}

/*  Function to subtract two complex numbers
	Input parameters : c1,c2 (two variables of the ComplexNumber structure data type)
	Returns : out = c1-c2 (ComplexNumber type)  */
struct ComplexNumber subtractComplex(struct ComplexNumber c1,struct ComplexNumber c2)
{
	struct ComplexNumber out;
	out.real = c1.real - c2.real;
	out.img = c1.img - c2.img;
	return out;
}

/*  Function to multiply two complex numbers
	Input parameters : c1,c2 (two variables of the ComplexNumber structure data type)
	Returns : out = c1*c2 (ComplexNumber type)  */
struct ComplexNumber multiplyComplex(struct ComplexNumber c1,struct ComplexNumber c2)
{
	struct ComplexNumber out;
	out.real = c1.real*c2.real - c1.img*c2.img;
	out.img = c1.real*c2.img + c1.img*c2.real;
	return out;
}

/*  Function to add divide two complex numbers
	Input parameters : c1,c2 (two variables of the ComplexNumber structure data type)
	Returns : out = c1/c2 (ComplexNumber type)  */
struct ComplexNumber divideComplex(struct ComplexNumber c1,struct ComplexNumber c2)
{
	struct ComplexNumber out;
	out.real = (c1.real*c2.real + c1.img*c2.img)/(c2.real*c2.real + c2.img*c2.img);
	out.img = (c1.img*c2.real - c1.real*c2.img)/(c2.real*c2.real + c2.img*c2.img);
	return out;
}

/*  Function to find distance between two complex numbers
	Input parameters : c1,c2 (two variables of the ComplexNumber structure data type)
	Returns : out (float type)  */
float distComplex(struct ComplexNumber c1,struct ComplexNumber c2)
{
	float out,x_dist,y_dist;
	x_dist = c1.real - c2.real;
	y_dist = c1.img - c2.img;
	out = sqrt(x_dist*x_dist + y_dist*y_dist);
	return out;
}











