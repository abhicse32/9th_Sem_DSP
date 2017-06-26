#include<stdio.h>
#include<math.h>
#include <stdlib.h>
 struct cmpx               //structure for storing parts of complex nos
 {float p,q;};             //p-real part,q-complx part

  void add(struct cmpx c1,struct cmpx c2)  //function for adding 2 complex nos c1,c2
{   struct cmpx c;                          //local structure variable
    c.p=c1.p+c2.p;
    c.q=c1.q+c2.q;
     if(c.q>0)                                 // for checking if imag part is +ve or -ve and print accordingly
     printf("%f + %f i",c.p,c.q);
      else
      printf("%f - %f i",c.p,-c.q);
}
 
    void sub(struct cmpx c1,struct cmpx c2)     // function for subtracting 2 compx nos
{    struct cmpx c;
       c.p=c1.p-c2.p;
       c.q=c1.q-c2.q;
        if(c.q>=0)                                // for checking if imag part is +ve or -ve and print accordingly
         printf("%f + %f i",c.p,c.q);
        else
         printf("%f - %f i",c.p,-c.q);
}


    void mul( struct cmpx c1,struct cmpx c2)   //function for multiplication
{    struct cmpx c;
     c.p=(c1.p*c2.p)-(c1.q*c2.q);
      c.q=(c1.p*c2.q)+(c1.q*c2.p);
        if(c.q>=0)                               // for checking if imag part is +ve or -ve and print accordingly
       printf("%f + %f i",c.p,c.q);
       else
       printf("%f - %f i",c.p,-c.q);
}


      void div(struct cmpx c1,struct cmpx c2) //function for division
{      struct cmpx c;
       float m;
       m=c2.p*c2.p+c2.q*c2.q;
       c.p=((c1.p*c2.p)+(c1.q*c2.q))/m;
       c.q=(-(c1.p*c2.q)+(c1.q*c2.p))/m;
         if(c2.q!=0 && c2.p!=0)
          {if(c.q>=0)                              // for checking if imag part is +ve or -ve and print accordingly
           printf("%f + %f i",c.p,c.q);
          else 
             printf("%f - %f i",c.p,-c.q);
           }
          else
          printf("\n Error..pl change your nos");

}

          void mod(struct cmpx c1,struct cmpx c2)                           //function for finding distance bet 2 nos 
{         printf("%f",sqrt((c1.p-c2.p)*(c1.p-c2.p)+(c1.q-c2.q)*(c1.q-c2.q)));
}




void main()                                          //begining of main program
{  struct cmpx c1,c2; 
   int in,inp;
  while(1)                                                 //exit controlled loop to check if user wants to continue with prgm or not
    {scanf("%f%f",&c1.p,&c1.q);
      scanf("%f%f",&c2.p,&c2.q);

        scanf("%d",&in);
      if(in==0 ||in==-1)
        break;
       else{
        if(in==1)                                   //checking the user wish list
        add(c1,c2);
         else if(in==2)
         sub(c1,c2);
          else if(in==3)
           mul(c1,c2);
           else if(in==4)
            div(c1,c2); 
             else if(in==5)
              mod(c1,c2);
         }
            }
}


    

