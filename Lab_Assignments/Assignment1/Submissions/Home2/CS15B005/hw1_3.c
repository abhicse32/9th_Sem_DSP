 #include <stdio.h>

int prime(int p){
    int j;
    if(p==2)return 1;
    for(j=2;j<p;j++){
        if((p%j)==0)
            return 0;
    }
    return 1;
}
int main(void) {
	int a,b,i;
	scanf("%d %d",&a,&b);
	for(i=2;i<(a+1);i++){if(((a%i)==0) && ((b%i)==0) &&(prime(i)==1)) printf("%d ",i);}
	return 0;
}
