//CS15B013 HEXADECIMAL CONVERSION


#include<stdio.h>
char hexnum(int rem);

{ int num,newnum,i,i1,mod;
  scanf("%d",&num);char array[10000];
  newnum=num;
  for(i=0;newnum!=0;i++)
     {mod=newnum%16;
      newnum=newnum/16;

      array[i]=hexnum(mod);


     }

  for(i1=i-1;i1>=0;i1--)
     {
       printf("%c",array[i1]);

      }
  printf("\n");
}



char hexnum(int rem)
   {
    int a=rem;
    char c='0';
    switch (a)
        {
          case 0:c='0';break;         
          case 1:c='1';break;
          case 2:c='2';break;
          case 3:c='3';break;

          case 4:c='4';break;
          case 5:c='5';break;
          case 6:c='6';break;
          case 7:c='7';break;
          case 8:c='8';break;
          case 9:c='9';break;
          case 10:c='a';break;
          case 11:c='b';break;
          case 12:c='c';break;
          case 13:c='d';break;
          case 14:c='e';break;
          case 15:c='f';break;

         }


     return c;

   }
