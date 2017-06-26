 
#include<stdio.h>

   double squrt(int n)// square root function 
    {
         double low = 0;
         double high = n;// temperory variales for solving
         while (high - low > 0.00000000001)// for getting precise 15 digits after decimal 
         {
               double mid =(double)(low+high)/2;
               if (mid*mid <= n)
                     low = mid;
               else
                     high = mid;
         }
         
         return low;
    }
int main()
{ int n;
  double ans;
  scanf("%d",&n);
  ans=squrt(n);// calling square root function 
  printf("%0.15lf\n",ans);// printing it in required format.
return 0;
}





