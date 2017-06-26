#include<stdio.h>
/*
  To convert decimal to hexadecimal
*/
int main()
{
  int n;
  scanf("%d",&n);                      //Taking number to be converted as input
  int r=0;
  int i;
  int hexa[8];                         //Array to store hexadecimal equivalent
  for(i=0;i<8;i++)
    hexa[i]=0;
  i=7;
  while(n!=0)     
  {
    r = (n%16);
    hexa[i] = r;                       //Storing remainder in the array
    n = n/16;
    i--;
  }
  printf("0x");
  for(i=0;i<8;i++)
  {
    switch(hexa[i])                    //Replacing 10 wih a, 11 with b and so on, before printing
    {
      case 10: printf("a");
               break;
      case 11: printf("b");
               break;
      case 12: printf("c");
               break;
      case 13: printf("d");
               break;
      case 14: printf("e");
               break;
      case 15: printf("f");
               break;
      default: printf("%d",hexa[i]);   //Printing other digits(0 to 9)
               break;
    }
  }
  return 0;
}  
