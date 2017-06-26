#include<stdio.h>
#include<string.h>


int main()
{
    char A[100];
    char B[100];

    scanf("%s",A);
    scanf("%s",B);

    int result = 1;

    int i=0;
    int C[26] = {0};
    int D[26] = {0};

    while(A[i]!='\0')
    {
        C[A[i]-'a']++;
        i++;
    }

    i=0;

    while(B[i]!='\0')
    {
        D[B[i]-'a']++;
        i++;
    }

    for(i=0;i<26;i++)
    {
        if(C[i]!=D[i]) result = 0;
    }

    printf("%d",result);

}

