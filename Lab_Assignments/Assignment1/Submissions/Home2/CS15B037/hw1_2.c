#include<stdio.h>

char convhex(long n);

int main()
{
    long n;
    scanf("%li",&n);
    char A[8];
    int i;

    for(i=0;i<8;i++)
    {
        A[i] = '0';
    }

    i=7;

    while(n!=0)
    {

        A[i] = convhex(n%16);
        n = n/16;
        i--;
    }

    printf("0x%c%c%c%c%c%c%c%c",A[0],A[1],A[2],A[3],A[4],A[5],A[6],A[7]);

}

char convhex(long n)
{
    if(n==0) return '0';
    if(n==1) return '1';
    if(n==2) return '2';
    if(n==3) return '3';
    if(n==4) return '4';
    if(n==5) return '5';
    if(n==6) return '6';
    if(n==7) return '7';
    if(n==8) return '8';
    if(n==9) return '9';
    if(n==10) return 'a';
    if(n==11) return 'b';
    if(n==12) return 'c';
    if(n==13) return 'd';
    if(n==14) return 'e';
    if(n==15) return 'f';

}
