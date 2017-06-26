#include <stdio.h>
        struct numb
                  {
            int min;
            int max;
          };
 struct numb Comp(int arr[],int n,int j);
      
        int main()
        {
            int i;
            scanf("%d",&i);
            int a[i];
            if(i>=0&&i<=100)
                {
          
                    int j;
                    for(j=0;j<i;j++)
                    scanf("%d",&a[j]);


                    struct numb Numb=Comp(a,0,i-1);
                    printf("%d",Numb.min);
                    printf(" %d",Numb.max);
                }

        }

      
      
      

      
        struct numb Comp(int arr[],int n,int j)
        { struct numb Numb;int mid;
                    if (n ==j)
                        {
                            Numb.min= arr[n];
                            Numb.max=arr[j];
                            return Numb;
                        }


                    else if(j == n+1)
                        {
                            if(arr[j] >arr[n])
                                {
                                    Numb.max= arr[j];
                                    Numb.min=arr[n];
                                }
                            else
                                {
                                    Numb.max=arr[n];
                                    Numb.min=arr[j];
                                }
                            return Numb;
                        }
          
                    else
                                {
                                    int mid;
                                    mid=(n+j)/2;
                                    struct numb numb1;
                                    struct numb numb2;
                                   
                                    numb1=Comp(arr,n,mid);
                                    numb2=Comp(arr,mid+1,j);

                                    if(numb1.min <numb2.min)
                                    Numb.min=numb1.min;
                                    else
                                    Numb.min=numb2.min;
                                    if(numb1.max>numb2.max)
                                    Numb.max=numb1.max;
                                    else
                                    Numb.max=numb2.max;
                                    return Numb;


                                }
}
