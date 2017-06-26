#include <stdio.h>
#include <stdlib.h>
#include "Polynomial.h"
void scan(LList* lst, int t){
	int temp,i;
	for(i=0;i<t;i++){
		scanf("%d",&temp);
		llist_append(lst,temp);
	}
}

int main(){
	Polynomial p1, p2, res;
	int op,n,t1,t2,temp;
	int i,j,k,l;
	while(1){
		scanf("%d",&op);
		if(op==-1)
			break;
		else{
			p1.exponents = llist_new();
			p1.coeffs= llist_new();
			scanf("%d",&t1);
			scan(p1.exponents,t1);
			scan(p1.coeffs,t1);
			switch(op){
				case 1: print_polynomial(p1); break;
				case 2: printf("%d\n",get_degree(p1)); break;
				case 3: 
				case 4:
				case 5:
					p2.exponents=llist_new();
					p2.coeffs= llist_new();
					scanf("%d",&t1);
					scan(p2.exponents,t1);
					scan(p2.coeffs,t1);
					if(op==3)
						res=add(p1,p2);
					else if(op==4)
						res=subtract(p1,p2);
					else
						res=multiply(p1,p2);
					print_polynomial(res);
					break;

				case 6:
					 scanf("%d",&k);
					 printf("%lld\n",evaluate(p1,k));
				default: break;
			}
		}
	}
}	