#include<stdio.h>
#include"List.h"
#include<stdlib.h>
#include"Polynomial.h"

int main(){

	int option = 0;

//	scanf("%d",&option);	
	
	Polynomial* p1;
	Polynomial* p2;
    
	p1 = (Polynomial*)malloc(sizeof(Polynomial)); 
	p2 = (Polynomial*)malloc(sizeof(Polynomial)); 
    
   p1->exponents = llist_new();
   p1->coeffs = llist_new();
   p2->exponents = llist_new();
   p2->coeffs = llist_new();
	

//	printf("Hello");

	while(option != -1){
	
		int t,t1,t2,k,a,i;
		
		scanf("%d",&option);
			
		switch(option){
			
			case 1 : {
				
				scanf("%d",&t);
				for(i = 0; i < t; i++){
					scanf("%d",&a);
					llist_append(p1->exponents,a);
					}
				for(i = 0; i < t; i++){
					scanf("%d",&a);
					llist_append(p1->coeffs,a);
					}
										
				print_polynomial(*p1);

				(p1->exponents)->head = NULL;		
				(p2->exponents)->head = NULL;		
				(p1->coeffs)->head = NULL;		
				(p2->coeffs)->head = NULL;	
		
				break;
			}
			
			case 2 : {
				
				scanf("%d",&t);
				for(i = 0; i < t; i++){
					scanf("%d",&a);
					llist_append(p1->exponents,a);
					}
				for(i = 0; i < t; i++){
					scanf("%d",&a);
					llist_append(p1->coeffs,a);
					}
					
				printf("%d\n",get_degree(*p1));

				(p1->exponents)->head = NULL;		
				(p1->coeffs)->head = NULL;		

				break;
			}
				
			case 3 : {

				scanf("%d",&t1);
				for(i = 0; i < t1; i++){
					scanf("%d",&a);
					llist_append(p1->exponents,a);
					}
				for(i = 0; i < t1; i++){
					scanf("%d",&a);
					llist_append(p1->coeffs,a);
					}
					
				scanf("%d",&t2);
				for(i = 0; i < t2; i++){
					scanf("%d",&a);
					llist_append(p2->exponents,a);
					}
				for(i = 0; i < t2; i++){
					scanf("%d",&a);
					llist_append(p2->coeffs,a);
					}
				print_polynomial(add(*p1,*p2));

				(p1->exponents)->head = NULL;		
				(p2->exponents)->head = NULL;		
				(p1->coeffs)->head = NULL;		
				(p2->coeffs)->head = NULL;	

				break;
			
			}
			
			case 4 : {

				scanf("%d",&t1);
				for(i = 0; i < t1; i++){
					scanf("%d",&a);
					llist_append(p1->exponents,a);
					}
				for(i = 0; i < t1; i++){
					scanf("%d",&a);
					llist_append(p1->coeffs,a);
					}
					
					
				scanf("%d",&t2);
				for(i = 0; i < t2; i++){
					scanf("%d",&a);
					llist_append(p2->exponents,a);
					}
				for(i = 0; i < t2; i++){
					scanf("%d",&a);
					llist_append(p2->coeffs,a);
					}
				print_polynomial(subtract(*p1,*p2));

				(p1->exponents)->head = NULL;		
				(p2->exponents)->head = NULL;		
				(p1->coeffs)->head = NULL;		
				(p2->coeffs)->head = NULL;	

				break;
			}
			
			case 5 : {
				int t1,t2;
				scanf("%d",&t1);
				for(i = 0; i < t1; i++){
					scanf("%d",&a);
					llist_append(p1->exponents,a);
					}
				for(i = 0; i < t1; i++){
					scanf("%d",&a);
					llist_append(p1->coeffs,a);
					}
					
				scanf("%d",&t2);
				for(i = 0; i < t2; i++){
					scanf("%d",&a);
					llist_append(p2->exponents,a);
					}
				for(i = 0; i < t2; i++){
					scanf("%d",&a);
					llist_append(p2->coeffs,a);
					}
				print_polynomial(multiply(*p1,*p2));

				(p1->exponents)->head = NULL;		
				(p2->exponents)->head = NULL;		
				(p1->coeffs)->head = NULL;		
				(p2->coeffs)->head = NULL;	

				break;
			}
			
			case 6 : {
				
				scanf("%d",&t);
				for(i = 0; i < t; i++){
					scanf("%d",&a);
					llist_append(p1->exponents,a);
					}
				for(i = 0; i < t; i++){
					scanf("%d",&a);
					llist_append(p1->coeffs,a);
					}
				scanf("%d",&k);	
					
				printf("%lld\n",evaluate(*p1,k));

				(p1->exponents)->head = NULL;		
				(p1->coeffs)->head = NULL;		

				break;
			
			}
					
		}
			
	}
}
