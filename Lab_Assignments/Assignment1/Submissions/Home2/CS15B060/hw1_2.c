#include<stdio.h>

void main()            //beginning of main fn
{  int n,i;
  i=0;
 char a[17]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','\0'};  //array having hexadec. eqt of 0......16
 char hex[11]={'o','x','0','0','0','0','0','0','0','0','\0'};                        //hex is character array to store hexadecimal  

scanf("%d",&n);                                              
   while(n>0)         //loop as long as n doesn't come down as 0 
{   hex[10-i]=a[n%16];  
    i++;             //increment i which keeps track of posn of new element to be inserted  
   n=n/16;           //new n is computed as n(new)=n/16
   }


  printf("%s",hex); //printing of hexadecimal eqt

}

 




