
/* project completed 
	by R.D.Nishal Singh, CS15B032 on 13.8.16
*/

#include<stdio.h>
#include<string.h>

int main()
{
long int n;
scanf("%ld",&n);
int i;
char hex[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
char ans[8];

for(i=0;n!=0;i++)
{
ans[i]=hex(n%16);
n=n%16;
}


printf("0x");
for(;i>0;i--)
printf("%c",ans[i-1]);

return 0;
}



