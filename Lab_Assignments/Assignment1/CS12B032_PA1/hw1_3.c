#include <stdio.h>
#define size 100005
int primes[size];
void sieve(){
	int i,j;
	primes[1]=primes[0]=1;
	for(i=2;i<size;i++)
		if(!primes[i])
			for(j=(i<<1);j<size;j+=i)
				primes[j]=1;
	primes[0]=2;
	for(i=1,j=3;j<size;j+=2)
		if(!primes[j])
			primes[i++]=j;

}
int main(){
	sieve();
	int i=0;
	// for(;i<1000;i++)
	// 	printf("%d ",primes[i]);
	// printf("\n");
	int m,n;
	scanf("%d%d",&m,&n);
	i=0;
	while(m>1 && n>1){
		int temp=primes[i];
		int prev_m=m,prev_n=n;
		while(m>1 && !(m%temp))
			m/=temp;
		while(n>1 && !(n%temp))
			n/=temp;
		i++;
		if(prev_n>n && prev_m>m)
			printf("%d ",temp);
	} 
	printf("\n");
	return 0;
}