#include<stdio.h>
#include<math.h>

struct complexno
        {
            float r;
            float i;
        };
void printcmn(struct complexno a)
    {
      if(a.i<0){printf("%f-%fi\n",a.r,0-a.i);}
      else printf("%f+%fi\n",a.r,a.i);
    }
void addition (struct complexno a,struct complexno b)
    {
        struct complexno x;
        x.r=a.r+b.r; x.i=a.i+b.i;
        printcmn(x);
    }   

void subtraction (struct complexno a,struct complexno b)
    {
        struct complexno x;
        x.r=a.r-b.r;x.i=a.i-b.i;
        printcmn(x);
    }

void multiplication (struct complexno a,struct complexno b)
    { 
       struct complexno x;
       x.r=(a.r*b.r)-(a.i*b.i);x.i=(a.r*b.i)+(a.i*b.r);
       printcmn(x);   
    }

float absolute (struct complexno a)
    {
     float abs;
    abs=sqrt(a.i*a.i+a.r*a.r);
     return abs;
    }

void division (struct complexno a,struct complexno b)
    {   float abs;
        abs=absolute(b);
        b.r=b.r/abs;
        b.i=0-(b.i/abs);
        multiplication(a,b);
    }
 
void modulus(struct complexno a,struct complexno b)
    {
        a.r=a.r-b.r;
       a.i=a.i-b.i;
       printf("%0.6f\n",absolute(a));
    }

  



int main()
{
 char input;
 struct complexno numb1;
 struct complexno numb2;
 printf("Addition: 1\nSubtraction: 2\nMultiplication: 3\nDivision: 4\nModulus: 5\n");
 
 
  while(1)
 {
  scanf("%f %f %f %f %c",&(numb1.r),&(numb1.i),&(numb2.r),&(numb2.i),&input);
  switch(input)
   {
   case '0':{return 1;}
   case '1':{addition(numb1,numb2); continue;} 
   case '2':{subtraction(numb1,numb2); continue;}
   case '3':{multiplication(numb1,numb2); continue;}
   case '4':{division(numb1,numb2); continue;}
   case '5':{modulus(numb1,numb2); continue;}
 }
}
}

