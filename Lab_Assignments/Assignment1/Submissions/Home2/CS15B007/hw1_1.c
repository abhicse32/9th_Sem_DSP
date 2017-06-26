#include<stdio.h>

int main(){
	
	long int n,k;
	int i,j=0;
	scanf("%ld",&n);							
	int check[2*n-1],poss[n];
	int max,nextmax;
	for(k=2*n-2 ; k>n-2 ;k--){					//scanning the inputs
		scanf("%d",&check[k]);
	}
	for(k=2*n-2 ; k>0 ;k=k-2){				//forming an array to have the overview of comparisions
		if(check[k]>check[k-1])
			check[(k-1)/2]=check[k];
			
		else check[(k-1)/2]=check[k-1];
	}
	max=check[0];
	for(k=0 ; k<n-1 ; ){										//forming an array of comparisions of maximum number	
		if(check[k*2+1]<check[k*2+2]){
			poss[j]=check[k*2+1];
			j++;
			k=k*2+2;
		}
		else {
			poss[j]=check[k*2+2];
			j++;
			k=k*2+1;
		}
	}
	nextmax=poss[j-1];
	for(i=j-2 ; i>=0 ; i--){										//finding the next maximum from the array
		if(nextmax<poss[i]){nextmax=poss[i];}
	}
	printf("%d %d\n",max,nextmax);
	
	return 0;
}
