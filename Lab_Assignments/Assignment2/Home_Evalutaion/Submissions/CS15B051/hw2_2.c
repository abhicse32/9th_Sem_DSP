#include<stdio.h>
#include<math.h>
int a[100],count=0;
void print(int n)
{
 int i,j;
  for(i=1;i<=n;++i)
 {
   for(j=1;j<=n;++j) 
  {
   if(a[i]==j)
    printf("%d ",j-1); //queen at i,j position
    //Printing the configuration of the position of the queens
  }
 }
   ++count;
   printf("\n");

}
int place(int row,int column)
{
 int i;
 for(i=1;i<=row-1;++i)
 {
  if(a[i]==column)   //Checkin     
   return 0;
  else
   if(abs(a[i]-column)==abs(i-row))  //Checking the diagonal conflict
    return 0;
 }
 return 1; //no conflicts
}
void nQueens(int i,int n)
{
  int j;            //Here i and j are rows and coloumns
  for(j=1;j<=n;++j)
  {
    if(place(i,j))
    {
      a[i]=j;
      if(i==n) //end
      print(n);  //Printing the configuration
      else   //Try the next row
      nQueens(i+1,n);
    }
  }
}



int main()
{
  int n;
  scanf("%d",&n); //Number of queens
  nQueens(1,n);
  printf("%d\n",count);
  return 0;
}
