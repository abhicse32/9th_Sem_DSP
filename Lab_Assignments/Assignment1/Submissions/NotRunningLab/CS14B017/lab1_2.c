#include<stdio.h>
/*Max(int n, int a[n],int b[n]){

for(i=0;i<n){
if(a[i]>=a[i+1]){
b[j]=a[i];
}
else{
b[j]=a[i+1];
}
j++;
i++;
}
}
*/
int main(){
	int n,i=0;
	scanf("%d",&n);
	int a[n];
	//printf("%d",n);	
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);

	}
//	printf("bay");	
	//printf("%d",a[n+555]);		
	int b[(n)/2],c[(n)/2];
	if(n%2==0){
//		printf("even");

		for(i=0;i<(n)/2;i++){
			if(a[2*i]>=a[2*i+1]){
				b[i]=a[2*i];
				c[i]=a[2*i+1];
				//printf("%d",c[i]);
			}
			else if(a[2*i]<a[2*i+1]){
				b[i]=a[2*i+1];
				c[i]=a[2*i];
				//printf("%d",c[i]);
			}
		}		
	}

	else{

		for(i=0;i<((n-1)/2);i++){
			if(a[2*i]>=a[2*i+1]){
				b[i]=a[2*i];
				c[i]=a[2*i+1];
				//printf("%d",c[i]);
			}
			else{
				b[i]=a[2*i+1];
				c[i]=a[2*i];
				//printf("%d",c[i]);
			}
		}
		
		b[i]=a[n-1];
		c[i]=a[n-1];
//		printf("%d",i);
		
	}




/*else{
int b[n/2],c[n/2];
for(i=0;i<n/2;i=i++){
if(a[2*i]>=a[2*i+1]){
b[i]=a[2*i];
c[i]=a[2*i+1]
}
else{
b[i]=a[2*i+1];
c[i]=a[2*i];
}
}
*/
	int M=b[0],m=c[0];
//	printf("%d",m);
	for(i=0;i<(n+1)/2;i++){
		if(M<b[i]){
			M=b[i];
		}
		if(m>c[i]){
			m=c[i];
			//printf("%dA%da",m,i);
		}
	}
	printf("%d %d", m,M);
}