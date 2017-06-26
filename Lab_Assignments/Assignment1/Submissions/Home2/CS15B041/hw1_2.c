
#include <stdio.h>

void Hex(int num)
{
int rem[100];int i=0;int length=0;
while(num>0)
{
rem[i]=num%16;
num=num/16;
i++;
length++;
}
printf("hex no. ");
printf("0x");
for(i=8;i>=length;i--)
    printf("0");
for(i=length-1;i>=0;i--)
{switch(rem[i])
{
case 10: printf('A');
break;
case 11:printf('B');
break;
case 12:printf('C');
break;
case 13:printf('D');
break;
case 14:printf('E');
break;
case 15:printf('F');
break;
default:printf("%d",rem[i]);
}
}
}
void main()
{
int num;
printf("enter");
scanf("%ld",&num);
Hex(num);
}




