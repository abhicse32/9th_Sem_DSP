#include "Polynomial.h"
#include "List.h"
#include<stdlib.h>
#include<stdio.h>

int get_degree(Polynomial P){
	
	Polynomial* p = &P;
	
	return (llist_get(p->exponents,(llist_size(p->exponents))-1));
}

void print_polynomial(Polynomial P){

	Polynomial* p = &P;
		
	int i,coeff,exp;
	
	for(i = 0; i < llist_size(p->exponents); i++){

		coeff = llist_get(p->coeffs,i);
		exp = llist_get(p->exponents,i);
		if(coeff == 0) {
			llist_remove(p->coeffs,i);
			llist_remove(p->exponents,i);
			i--;
				if(llist_size(p->exponents) == 0){
					printf("0\n");
					return ;
					}

			continue;
		}
		if(exp != llist_get(p->exponents,0)){
			if(coeff > 0) printf(" + ");
			else if(coeff < 0) {
				printf(" - ");
				coeff = -coeff;
				}
		}
		if(exp == 0) printf("%d",coeff);
		else{
			printf("%dx^%d",coeff,exp);
		}
		
	}	
		printf(" \n");
		
		(p->exponents)->head = NULL;		
		(p->coeffs)->head = NULL;
		
		return ;	
}


Polynomial add(Polynomial P1, Polynomial P2){
	
	Polynomial* p1 = &P1;
	Polynomial* p2 = &P2;
	
	Polynomial* result;
	
	result = (Polynomial*)malloc(sizeof(Polynomial)); 
	
	result->exponents = llist_new();
	result->coeffs = llist_new();

	LList* e3 = result->exponents;
	LList* c3 = result->coeffs;	
	LList* e1 = p1->exponents;
	LList* e2 = p2->exponents;
	LList* c1 = p1->coeffs;
	LList* c2 = p2->coeffs;
	
	int n1 = llist_size(e1);	
	int n2 = llist_size(e2);
	
	int i,j;
	i = 0; j = 0;
	
		while((i < n1)||(j < n2)){
			

			
			if((i >= n1)&&(j < n2)) {	
			
						llist_append(e3,llist_get(e2,j));
						llist_append(c3,llist_get(c2,j));
						j++;	
			}
			
			if((i < n1)&&(j >= n2)){

						llist_append(e3,llist_get(e1,i));
						llist_append(c3,llist_get(c1,i));
						i++;
			}
			
			if((i < n1)&&(j < n2)){
				
				if(llist_get(e1,i) == llist_get(e2,j)) {
				
						llist_append(e3,llist_get(e1,i));
						llist_append(c3,llist_get(c1,i)+llist_get(c2,j));
						i++;
						j++;
					}
			}
			
			if((i < n1)&&(j < n2)){
			
				if(llist_get(e1,i) < llist_get(e2,j)){

						llist_append(e3,llist_get(e1,i));
						llist_append(c3,llist_get(c1,i));
						i++;
					}
			}
			
			if((i < n1)&&(j < n2)){
					
				if(llist_get(e1,i) > llist_get(e2,j)){

						llist_append(e3,llist_get(e2,j));
						llist_append(c3,llist_get(c2,j));
						j++;					
				}
			}
		}	
		
//		(p1->exponents)->head = NULL;		
//		(p2->exponents)->head = NULL;		
//		(p1->coeffs)->head = NULL;		
//		(p2->coeffs)->head = NULL;	
			
		
	return (*result);
}

Polynomial subtract(Polynomial P1, Polynomial P2){
	
	Polynomial* p1 = &P1;
	Polynomial* p2 = &P2;
	
	Polynomial* result;
	
	result = (Polynomial*)malloc(sizeof(Polynomial)); 
	
	result->exponents = llist_new();
	result->coeffs = llist_new();

	LList* e3 = result->exponents;
	LList* c3 = result->coeffs;	
	LList* e1 = p1->exponents;
	LList* e2 = p2->exponents;
	LList* c1 = p1->coeffs;
	LList* c2 = p2->coeffs;
	
	int n1 = llist_size(e1);	
	int n2 = llist_size(e2);
	
	int i,j;
	i = 0; j = 0;
	
		while((i < n1)||(j < n2)){
			

			
			if((i >= n1)&&(j < n2)) {	
			
						llist_append(e3,llist_get(e2,j));
						llist_append(c3,-llist_get(c2,j));
						j++;	
			}
			
			if((i < n1)&&(j >= n2)){

						llist_append(e3,llist_get(e1,i));
						llist_append(c3,llist_get(c1,i));
						i++;
			}
			
			if((i < n1)&&(j < n2)){
				
				if(llist_get(e1,i) == llist_get(e2,j)) {
				
						llist_append(e3,llist_get(e1,i));
						llist_append(c3,llist_get(c1,i)-llist_get(c2,j));
						i++;
						j++;
					}
			}
			
			if((i < n1)&&(j < n2)){
			
				if(llist_get(e1,i) < llist_get(e2,j)){

						llist_append(e3,llist_get(e1,i));
						llist_append(c3,llist_get(c1,i));
						i++;
					}
			}
			
			if((i < n1)&&(j < n2)){
					
				if(llist_get(e1,i) > llist_get(e2,j)){

						llist_append(e3,llist_get(e2,j));
						llist_append(c3,-llist_get(c2,j));
						j++;					
				}
			}
		}	
		
		(p1->exponents)->head = NULL;		
		(p2->exponents)->head = NULL;		
		(p1->coeffs)->head = NULL;		
		(p2->coeffs)->head = NULL;		
		
	return (*result);
}

Polynomial multiply(Polynomial P1, Polynomial P2){

	int i,j;
	
	Polynomial* p1 = &P1;
	Polynomial* p2 = &P2;
		
	Polynomial* result;
	Polynomial* temp;
	
	result = (Polynomial*)malloc(sizeof(Polynomial)); 
	temp = (Polynomial*)malloc(sizeof(Polynomial)); 
	
	result->exponents = llist_new();
	result->coeffs = llist_new();
	temp->exponents = llist_new();
	temp->coeffs = llist_new();

	LList* e3 = result->exponents;
	LList* c3 = result->coeffs;	
	LList* e1 = p1->exponents;
	LList* e2 = p2->exponents;
	LList* c1 = p1->coeffs;
	LList* c2 = p2->coeffs;

//	llist_append(e3,0);
//	llist_append(c3,0);
	
	int n1 = llist_size(e1);	
	int n2 = llist_size(e2);
	
	for(i = 0; i < n1; i++){
		
		int coeff = llist_get(c1,i);
		int exp = llist_get(e1,i);
		
		for(j = 0; j < n2; j++){
			llist_append(temp->exponents,(exp+llist_get(e2,j)));		
			llist_append(temp->coeffs,(coeff*llist_get(c2,j)));
			}
			
//		printf("%d %d %d %d\n",*temp,temp,*result,result);	
//		print_polynomial(*temp);	
//		print_polynomial(*result);
//		print_polynomial(add(*temp,*result));
		*result = add(*temp,*result);
//		print_polynomial(*result);
//		print_polynomial(add(*temp,*result));
		(temp->exponents)->head = NULL;
		(temp->coeffs)->head = NULL;
	}
	
		(p1->exponents)->head = NULL;		
		(p2->exponents)->head = NULL;		
		(p1->coeffs)->head = NULL;		
		(p2->coeffs)->head = NULL;	
		
	return (*result);
}

long long int evaluate(Polynomial P, int k){

	long long int sum = 0;
	int i;
	
	Polynomial* p = &P;

	LList* e1 = p->exponents;
	LList* c1 = p->coeffs;
	
	for(i = 0; i < llist_size(p->exponents); i++){
	
		int coeff = llist_get(c1,i);
		int exp = llist_get(e1,i);
	
		sum = sum + coeff*power(k,exp);		
	}
	
		(p->exponents)->head = NULL;		
		(p->coeffs)->head = NULL;


	return sum;
			
}

long long int power(int a, int exp){

	if(exp == 1) return a;
	if(exp == 0) return 1;
	if(exp%2 == 0) return (power(a,exp/2)*power(a,exp/2));
	return (a*power(a,exp/2)*power(a,exp/2));
}

	
