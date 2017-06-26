#include<stdio.h>
#include<math.h>
int fact(long long int n,long long int f){
//	printf("enter fact %lld %lld \n",n,f);
	if(n%f==0){
		return 1;
	}
	else{
		return 0;
	}
}
int prime(long long int n){
//	printf("enter prime %lld \n",n);
	for(long long int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	long long int n1,n2;
//	printf("0");
	scanf("%lld%lld",&n1,&n2);//scanf("%lld,%lld",&n1,&n2); This is wrong
//	printf("n2 = %lld \n",n2);
//	printf("1");
	for(long long int i=2;((i<=n1)&&(i<=n2));i++){
//		printf("enter 1 %lld \n",i);
		if(fact(n1,i)==1){			
			if(fact(n2,i)==1){
//				printf("enter 2 %lld \n",i);
			//	if(prime(n1)==1){
			//		printf("enter 3 %lld \n",i);
				if(prime(i)==1){
//					printf("enter 4 %lld \n",i);
					printf("%lld ",i);
				}
	//		}
			}
		}
	}
	return 0;
}
