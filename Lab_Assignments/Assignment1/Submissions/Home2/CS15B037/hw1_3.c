#include<stdio.h>

int main()
{
    int n1;
    int n2;
    scanf("%d %d",&n1,&n2);
    if(n1>n2) {
                    int temp;
                    temp = n1;
                    n1 = n2;
                    n2 = temp;
              }

    int arr[n1];
    int x=0;
    arr[x]=n2;
    int i;
    for(i=2; i<=n1;i++)
    {
        if(n1%i==0){
                        if(n2%i==0) {
                                        int j,flag=1;
                                        for(j=0; j<=x; j++)
                                        {
                                            if(i%arr[j]==0) {
                                                                flag=0;
                                                                break;
                                                            }
                                        }

                                        if(flag==1) {
                                                        printf("%d ",i);
                                                        x=x+1;
                                                        arr[x]=i;
                                                    }
                                    }

                   }
    }

}
