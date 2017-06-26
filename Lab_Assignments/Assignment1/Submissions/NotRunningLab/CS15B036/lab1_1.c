#include<stdio.h>
#include<math.h>
int addition(int,int,int,int);
int subtraction(int,int,int,int);
int multi(int,int,int,int);
int division(int,int,int,int);
float division(int,int,int,int);
int main()
{
int x1;
int y1;
int x2;
int y2;
int menu;
scanf("%d%d\n",&x1,&y1);
scanf("%d%d\n",&x2,&y2);
int i;
scanf("%d",&menu);
while(i<6)
{
if(menu==1)
addition(x1,y1,x2,y2);
if(menu==2)
subtraction(x1,y1,x2,y2);
if(menu==3)
multi(x1,y1,x2,y2);
if(menu==4)
division(x1,y1,x2,y2);
if(menu==5)
distance(x1,y1,x2,y2);
if(menu==(-1))
break;
i++;
}
return 0;
}
addition(int x1,int y1,int x2,int y2)
{
int x;
int y;
x=x1+x2;
y=y1+y2;
printf("%d+%di\n",x,y);
}
subtraction(int x1,int y1,int x2,int y2)
{
int x;
int y;
x=x1-x2;
y=y1-y2;
printf("%d+%di",x,y);
}
multi(int x1,int y1,int x2,int y2)
{
int x;
int y;
x=((x1)*(x2))-((y1)*(y2));
y=((x1)*(y2))+((y1)*(x2));
printf("%d+%di",x,y);
}
division(int x1,int y1,int x2,int y2)
{
int x;
int y;
x=(int)(((x1)*(x2)+(y1)*(y2))/((x2)*(x2)+(y2)*(y2)));
y=(int)(((y1)*(x2)-(x1)*(y2))/((x2)*(x2)+(y2)*(y2)));
printf("%d+%di",x,y);
}
distance(int x1,int y1,int x2,int y2)
{
int x;
x=sqrt((x1)*(x2)+(y1)*(y2));
printf("%f",x);
}



