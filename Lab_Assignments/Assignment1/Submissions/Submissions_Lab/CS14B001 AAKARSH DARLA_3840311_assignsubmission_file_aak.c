#include<stdio.h>
void minmax(int*,int*,int);
main()
{
     int i,n;
     scanf("%d",&n);
     int a[n],b[2];
     for(i=0;i<n;i++)
     scanf("%d",&a[i]);
     minmax(a,b,n);

 }
 void minmax(int* a,int* b,int y)
 {
     int i,j,t,min,max;
     if(y%2==0)
     {
         if(a[0]<a[1])
         {
           t=a[1];
           j=a[0];

         }
         else
         {
             t=a[0];
             j=a[1];
         }

          for(i=0;i<y;i+=2)
         {


         if(a[i]>=a[i+1])
        {
            if(a[i] > t)
            {
                t=a[i];
            }
            if(a[i+1] < j)
            {
                j = a[i+1];
            }
        }
        else

        {
    

            for(i=0;i<y-1;i++)

            if(a[i+1]>t)
            {
                t=a[i+1];
            }
            if(a[i] < j)
            {
                j = a[i];
            }
        }

         }

         b[0] = t;
         b[1] = j;

    }

    else
{
        if(y==1)
{
        b[0] = a[0];
        b[1] = a[1];
   
}

        else
{
        if(a[0]<a[1])
         {
           t=a[1];
           j=a[0];

         }
         else
         {
             t=a[0];
             j=a[1];
         }

          for(i=0;i<y-1;i+=2)
         {


         if(a[i]>=a[i+1])
        {
            if(a[i] > t)
            {
                t=a[i];
            }
            if(a[i+1] < j)
            {
                j = a[i+1];
            }
        }
        else

        {
    

            for(i=0;i<y-1;i++)

            if(a[i+1]>t)
            {
                t=a[i+1];
            }
            if(a[i] < j)
            {
                j = a[i];
            }
        }

         }

        if(a[y-1] > t)
{
    t = a[y-1];}
        if(a[y-1] < j)
{j=a[y-1];}

         b[0] = t;
         b[1] = j;

}
    
}


        printf("%d %d",b[0],b[1]);
        return;
 }

