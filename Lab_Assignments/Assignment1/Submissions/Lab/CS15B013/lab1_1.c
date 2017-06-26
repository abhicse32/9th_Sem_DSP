  //CS15B013  D.MALLIKARJUNA 8-8-16  complex numbers operations


#include<stdio.h>         
#include<math.h>

 

  typedef struct complex{
                  
                     float p;            //structure definition
                     float q;

                      }Compnum;

 Compnum addcom(Compnum a,Compnum b);
 Compnum subcom(Compnum a,Compnum b);
 Compnum multcom(Compnum a,Compnum b);    //function initialisatin 
 Compnum divcom(Compnum a,Compnum b);
 float modcom(Compnum a,Compnum b);
 void printcom(Compnum a);


int main()
{ float a1,b1,a2,b2,mod;
  int i;int operation,cond=1;
  Compnum number1,number2,answer;
   
   for(i=1;cond==1;i++)
     {
      
      scanf("%f %f ",&a1,&b1);
                                         //taking input
      scanf("%f %f",&a2,&b2);
      scanf("%d",&operation);

      if(operation==0 || operation==-1)
          cond=0;

      number1.p=a1;number1.q=b1;
      number2.p=a2;number2.q=b2;
     
      if(operation==1)
        {answer=addcom(number1,number2);printcom(answer);
        }
      if(operation==2)                                        //complex number operations
        {answer=subcom(number1,number2);printcom(answer);
        }
      if(operation==3)
        {answer=multcom(number1,number2);printcom(answer);
        }
      if(operation==4)
        {answer=divcom(number1,number2);printcom(answer);
        }
      if(operation==5)
        {
         mod=modcom(number1,number2);printf("%f",mod);
        }

      
     }
  return 0;

}



  Compnum addcom(Compnum a,Compnum b)
       { float sump,sumq;
         Compnum num1=a;
         Compnum num2=b;
         Compnum sum;                             //addition function
         sump=num1.p+num2.p;
         sumq=num1.q+num2.q;

         sum.p=sump;sum.q=sumq;
         
         return sum;         
       }


  Compnum subcom(Compnum a,Compnum b)
       { float sump,sumq;
         Compnum num1=a;
         Compnum num2=b;
         Compnum sum;                            //subraction function
         sump=num1.p-num2.p;
         sumq=num1.q-num2.q;

         sum.p=sump;sum.q=sumq;

         return sum;         
       }

   
  Compnum multcom(Compnum a,Compnum b)
       { float sump,sumq;
         Compnum num1=a;
         Compnum num2=b;
         Compnum sum;                            //multiplication function
         sump=num1.p*num2.p-num1.q*num2.q;
         sumq=num1.p*num2.q+num1.q*num2.p;

         sum.p=sump;sum.q=sumq;

         return sum;         
       }

  Compnum divcom(Compnum a,Compnum b)
       { float sump,sumq;
         Compnum num1=a;
         Compnum num2=b;
         Compnum sum;
         
         sump=(num1.p*num2.p+num1.q*num2.q)/(num2.p*num2.p+num2.q*num2.q);  //division function
         sumq=(-num1.p*num2.q+num1.q*num2.p)/(num2.p*num2.p+num2.q*num2.q);

         sum.p=sump;sum.q=sumq;

         return sum;         
       }

   float modcom(Compnum a,Compnum b)
       { float mod,sump,sumq,tot;
         Compnum num1=a;
         Compnum num2=b;
         
         sump=(num1.p-num2.p)*(num1.p-num2.p);               //modulus function
         sumq=(num1.q-num2.q)*(num1.q-num2.q);
         tot=sump+sumq;
         mod=sqrt(tot);

         return mod;         
       }

   void printcom(Compnum a)
        {
          Compnum num=a;
          if(num.q>=0)
             printf("%f + %fi\n",num.p,num.q);
          else                                               //printing function
             {num.q=-1*num.q;
              printf("%f - %fi\n",num.p,num.q);
             }
         }






