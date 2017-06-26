// Lab Assignment 1 Question 1
// Operations on Complex Number ADT
// Author : Milind Srivastava
// Date : 8 Aug 2016

#include <stdio.h>
#include <math.h>

struct Complex
{
    float real;
    float imag;
};

struct Complex Add(struct Complex x, struct Complex y) // Adds 2 Complex numbers "x" and "y"
{
    struct Complex result;
    result.real = x.real + y.real;
    result.imag = x.imag + y.imag;
    return result;
}

struct Complex Subtract(struct Complex x, struct Complex y) // Subtracts 2 Complex numbers "x" and "y"
{
    struct Complex result;
    result.real = x.real - y.real;
    result.imag = x.imag - y.imag;
    return result;  
}

struct Complex Multiply(struct Complex x, struct Complex y) // Multiplies 2 Complex numbers "x" and "y"
{
    struct Complex result;
    result.real = x.real*y.real - x.imag*y.imag;
    result.imag = x.imag*y.real + x.real*y.imag;
    return result;
}

float Modulus(struct Complex x) // Return modulus of Complex number "x"
{
    return sqrt(pow(x.real,2.0f) + pow(x.imag,2.0f));
}

struct Complex Divide(struct Complex x, struct Complex y) // Divides 2 Complex numbers "x" and "y"
{
    struct Complex reciprocalOfy;
    reciprocalOfy.real = y.real/(Modulus(y)*Modulus(y));
    reciprocalOfy.imag = -y.imag/(Modulus(y)*Modulus(y));
    return Multiply(x,reciprocalOfy);
}

float Distance(struct Complex x, struct Complex y) // Computes distance between 2 Complex numbers "x" and "y"
{
    return sqrt(pow(x.real-y.real,2.0f) + pow(x.imag-y.imag,2.0f));
}

void printComplex(struct Complex x) // Prints Complex number "x" in specified format (a+bi) or (a-bi)
{
    if(x.imag >= 0)
    {
        printf("%f+%fi\n",x.real,x.imag);
    }
    else
    {
        printf("%f-%fi\n",x.real,-x.imag);
    }
    return;
}

int main()
{
    int choice = -1;
    do
    {
        struct Complex a,b;
        
        // Inputting Complex numbers and choice

        scanf("%f%f",&a.real,&a.imag);
        scanf("%f%f",&b.real,&b.imag);
        
        scanf("%d",&choice);
        
        if(choice == 0 || choice == -1)
        {
            return 0; 
        }

        // Checking for divide by zero error
        
        if(b.real == 0.0f && b.imag == 0.0f && choice == 4)
        {
            printf("%s\n","Divide by zero error");
            continue;
        }
        
        switch(choice)
        {
            case 1:printComplex(Add(a,b));
            break;
                
            case 2:printComplex(Subtract(a,b));
            break;
            
            case 3:printComplex(Multiply(a,b));
            break;
            
            case 4:printComplex(Divide(a,b));
            break;
            
            case 5:printf("%f\n",Distance(a,b));
            break;
            
            case 0:
            case -1:printf("%s","Sentinel value entered");
            break;
            
            default:printf("%s","Wrong choice entered");
                
        }
    } while(choice != -1 && choice != 0);
    
    return 0;
}








