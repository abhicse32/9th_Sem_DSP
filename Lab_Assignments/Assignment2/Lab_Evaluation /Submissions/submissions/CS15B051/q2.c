#include<stdio.h>
#include<stdlib.h>
int val=-1,n,perm[100],a[100];
permutation(int k)
{
    int i;
    perm[k]=++val;    //The value is incremented 
    if(val==n)
    {
        for(i=0;i<n;i++)
        {
        printf("%d",a[perm[i]]);   
        }
        printf(" ");
    }
    for(i=0;i<n;i++)
    if(perm[i]==0)
    permutation(i); // Calling the permutation function
    val--;      //Value is decremented
    perm[k]=0;   
     
}
int main()
{
    int i,j;
    scanf("%d",&n); //Reads the value of the number of integers 
    for(i=0;i<n;i++)
    {
        perm[i]=0;            // All the values of perm are now 0
        j=i+1;               // j is assigned the value of i+1
        scanf("%d",&a[j]);  //Stores the value of the integers from the second array value
    }
    permutation(0);    // Calling the permutation function
}

