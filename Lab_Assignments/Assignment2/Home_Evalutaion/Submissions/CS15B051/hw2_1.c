#include<stdio.h>
int a[20][20];
int determinant(int a[20][20],int x)
{
   int d=0;
   int b[20][20],i,p,q,t,u,c[20];
   if(x==2) 
   {      
      d=(a[1][1]*a[2][2])-(a[1][2]*a[2][1]);
      return(d);   
   } 
   else 
   {   
     for(i=1;i<=x;i++)   
     {       
      int r=1,s=1;
      for(p=1;p<=x;p++)
        {
          for(q=1;q<=x;q++)
            {
              if(p!=1&&q!=i)
              {
                b[r][s]=a[p][q];
                s++;
                if(s>x-1)
                 {
                   r++;
                   s=1;
                 }
              }
            }
          }
       
      for(t=1,u=1;t<=i+1;t++)
      u=(-1)*u;
      c[i]=u*determinant(b,x-1);
    }
    for(i=1,d=0;i<=x;i++)
    {    
      d=d+(a[1][i]*c[i]);
    }
     return(d);
}
}
int main()
{
  int N;
  int d;
  scanf("%d",&N); //Reading the value of the number of rows and coloumns
  int i,j;
  for(i=1;i<=N;i++)
  {
    for(j=1;j<=N;j++)
     {
       scanf("%d",&a[i][j]);
     }
   }
   printf("%d",determinant(a,N));
    
}
