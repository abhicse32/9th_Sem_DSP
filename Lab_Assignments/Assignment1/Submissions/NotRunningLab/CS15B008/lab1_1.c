// Code for arithmetc fuctions of complex numbers
// Code written by B.Nikhil Baba-CS15B008 on 8th Aug 2016
#include<stdio.h>
#include<math.h>
typedef struct ComplexNumber Complex ;                   //Defining the structure
struct ComplexNumber                            
  {  
     float real,imaginary;
  };

int main()                                               //main function
{
   Complex number1,number2;                              //Declaring Complex variables
   float a1,a2,b1,b2;                                    //Declaring other variables
   printf("Enter two Complex numbers");
   scanf("%f %f",&a1,&a2);
   scanf("%f %f",&b1,&b2);

   number1.real=a1,number1.imaginary=a2;                 //Assigning numbers to variables
   number2.real=b1,number2.imaginary=b2;
   
  
  
  int Operation;
 do{                                                     //Writing a do-while loop
 printf("Enter the choice of operation:");
  scanf("%d",&Operation);
  
  
    
    switch(Operation){                                   //Writing a switch case
        case 1:
        Addition(number1,number2);
        break;
       
        case 2:
        Subtraction(number1,number2);
        break;
         
        case 3:
        Multiplication(number1,number2);
        break;
         
        case 4:
        Division(number1,number2);
        break;
   
        case 5:
        Distance(number1,number2);
        break;
  
        default:
        printf("Invalid Operation is requested");
        break;
   
       
         ;
    }
  }while(Operation!=-1);

return 0;                                                     //Concluding the program

}
 
 void Addition(Complex a,Complex b){                          //Addition function                                    
          float real1,imaginary1;
          real1 = a.real+b.real;
          imaginary1=a.imaginary+b.imaginary;
          if(imaginary1>0)
          printf("%f+%fi",real1,imaginary1);
          else
          printf("%f-%fi",real1,-imaginary1);
         
         }
 void Subtraction(Complex a,Complex b){                       //Subtraction function
          float real1=(a.real-b.real),imaginary1=(a.imaginary-b.imaginary);
          if(imaginary1>0)
          printf("%f+%fi",(real1),(imaginary1));
          else
          printf("%f-%fi",real1,-imaginary1);
         }    
 void Multiplication(Complex a,Complex b){                     //Multiplication function
          float real1=a.real,real2=b.real,imaginary1=a.imaginary,imaginary2=b.imaginary;
          float real,imaginary;
          real = ((real1*real2)-(imaginary2*imaginary1));
          imaginary=((real1*imaginary2)+(real2*imaginary1));
          if(imaginary1>0)
          printf("%f+%fi",real,imaginary);
          else
          printf("%f-%fi",real1,-imaginary1);
    
         }
 void Division(Complex a,Complex b){                           //Division function
          float real1=a.real,real2=b.real,imaginary1=a.imaginary,imaginary2=b.imaginary;  
          float magnitude,real,imaginary;
          magnitude=((real2*real2)+(imaginary2*imaginary2));
          real = ((real1*real2)+(imaginary1*imaginary2))/magnitude;
          imaginary=(-(real1*imaginary2)+(real2*imaginary1))/magnitude;
          if(imaginary1>0)
          printf("%f+%fi",real,imaginary);
          else
          printf("%f-%fi",real1,-imaginary1);
         }
 void Distance(Complex a,Complex b){                           //Distance function
        
          float real1=sqrt((a.real-b.real)*(a.real-b.real)+(a.imaginary-b.imaginary)*(a.imaginary-b.imaginary));
          printf("%f",real1);
      
         }
         
          
          



               
