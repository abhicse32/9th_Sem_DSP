#include<stdio.h>
#include<math.h>

int main(){
	
	int a,b,k,c,n,h;
	int prm[100];
	
	prm[0] = 2; 
	n = 1;
	
	scanf("%d %d",&a, &b);
	
	if(a>b){
		c = a;
		a = b;
		b = c;
	}
	
	for(k = 2; k <= a; k++){
		
		if(a%k == 0){
			for(h = 0; h < n; h++){
				if(k%prm[h] == 0) {
					if((k == 2)&&(b%k == 0))
					printf("%d",k);
					break;
				}
				if(h == n-1) {
				prm[h] = k;
				if(b%k == 0) printf("%d ",k);
				if(n != 1) n++;
				}
			}	
		}
				
	}
		return 0;
}

