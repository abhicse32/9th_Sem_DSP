#include<stdio.h>
#include<math.h>

int main()
{
 int q, j, x, i, n, t, z;
 i=0;

 scanf("%d",&n);

 for(t=1;t<=n;t=t*16)
  {
   i=i+1; 
  }

 z=i-1; 
 char S[8] ; 

  
 for(j=n;j>=1;j=j/16)
   {
  x=j%16;
  if(x==10) S[z]='A';
  if(x==11) S[z]='B';
  if(x==12) S[z]='C';
  if(x==13) S[z]='D';
  if(x==14) S[z]='E';
  if(x==15) S[z]='F';
  if(x==9) S[z]='9';
  if(x==8) S[z]='8';
  if(x==7) S[z]='7';
  if(x==6) S[z]='6';
  if(x==5) S[z]='5';
  if(x==4) S[z]='4';
  if(x==3) S[z]='3';
  if(x==2) S[z]='2';
  if(x==1) S[z]='1';
  if(x==0) S[z]='0'; 
  z=z-1;
   }

  printf("0X");
  for(q=i;q<8;q++)
  {
   S[q]='0';
  }

  for(z=0;z<8;z++)
  printf("%c",S[7-z]);

 return 0;
}
