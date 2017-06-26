#include "Polynomial.h"
#include "List.h"
#include <math.h>
#include <stdio.h>

/*function to return the degree of the polynomial*/
int get_degree(Polynomial p){
	int len= llist_size(p.exponents);
	return llist_get(p.exponents,len-1);
}
// print Polynomial
void print_polynomial(Polynomial p){
	Node* temp_exp= (p.exponents)->head;
	Node* temp_coeff=(p.coeffs)->head;
	if(!temp_exp)
		return;
	while(temp_coeff && !(temp_coeff->data)){
		temp_coeff= temp_coeff->next;
		temp_exp= temp_exp->next;
	}
	if(temp_exp->data==0)
		printf("%d ",temp_coeff->data);
	else printf("%dx^%d ",temp_coeff->data,temp_exp->data);
	temp_exp=temp_exp->next;
	temp_coeff= temp_coeff->next;
	char sign;
	while(temp_exp){
		sign='+';
		if(temp_coeff->data){
			if(temp_coeff->data < 0){
				sign='-';
				temp_coeff->data= -1*temp_coeff->data;
			}
			printf("%c %dx^%d ",sign,temp_coeff->data,temp_exp->data);
		}
		temp_exp=temp_exp->next;
		temp_coeff= temp_coeff->next;
	}
	printf("\n");
}

/*Multiply two polynomials and return the result*/
Polynomial multiply(Polynomial p1, Polynomial p2){
	Polynomial res_p;
	res_p.exponents= llist_new();
	res_p.coeffs= llist_new();
	Node* p1_exp= p1.exponents->head;
	Node* p1_coeffs= p1.coeffs->head;
	
	while(p1_exp){
		Polynomial temp;
		temp.exponents= llist_new();
		temp.coeffs= llist_new();
		Node* p2_exp= p2.exponents->head;
		Node* p2_coeffs= p2.coeffs->head;
		while(p2_exp){
			llist_append(temp.exponents,p2_exp->data+ p1_exp->data);
			llist_append(temp.coeffs,p1_coeffs->data* p2_coeffs->data);
			p2_exp= p2_exp->next;
			p2_coeffs= p2_coeffs->next;
		}
		res_p= add(res_p,temp);
		p1_exp=p1_exp->next;
		p1_coeffs= p1_coeffs->next;
	}
	return res_p;
}

/*add_aux*/
void add_aux(Polynomial res_p, Node* src_exp, Node* src_coeffs){
	while(src_exp){
		llist_append(res_p.exponents,src_exp->data);
		llist_append(res_p.coeffs, src_coeffs->data);
		src_exp= src_exp->next;
		src_coeffs= src_coeffs->next;
	}
}

/*Add two polynomials and return the result*/
Polynomial add(Polynomial p1, Polynomial p2){
	Node* p1_exp= p1.exponents->head;
	Node* p2_exp= p2.exponents->head;
	Node* p1_coeffs= p1.coeffs->head;
	Node* p2_coeffs= p2.coeffs->head;

	Polynomial res_p;
	res_p.exponents= llist_new();
	res_p.coeffs= llist_new();

	while(p1_exp && p2_exp){
		//printf("%d %d %d %d\n",p1_exp->data,p1_coeffs->data,p2_exp->data,p2_coeffs->data);
		if(p1_exp->data == p2_exp->data){
			int sum_= p1_coeffs->data + p2_coeffs->data;
			llist_append(res_p.exponents,p1_exp->data);
			llist_append(res_p.coeffs,sum_);
			p1_exp= p1_exp->next;
			p1_coeffs= p1_coeffs->next;
			p2_exp= p2_exp->next;
			p2_coeffs= p2_coeffs->next;

		}else if((p1_exp->data) > (p2_exp->data)){
			llist_append(res_p.exponents,p2_exp->data);
			llist_append(res_p.coeffs, p2_coeffs->data);
			p2_exp= p2_exp->next;
			p2_coeffs= p2_coeffs->next;
		}else{
			llist_append(res_p.exponents,p1_exp->data);
			llist_append(res_p.coeffs, p1_coeffs->data);
			p1_exp= p1_exp->next;
			p1_coeffs= p1_coeffs->next;
		}
	}
	add_aux(res_p, p1_exp, p1_coeffs);
	add_aux(res_p, p2_exp, p2_coeffs);
	return res_p;
}

/*Subtract second Polynomial from first*/
Polynomial subtract(Polynomial p1, Polynomial p2){
	Node* p2_coeffs= (p2.coeffs)->head;
	while(p2_coeffs){
		p2_coeffs->data= p2_coeffs->data*-1;
		p2_coeffs= p2_coeffs->next;
	}
	return add(p1,p2);
}

/*Evaluate Polynomial at var=k and return the result*/
long long evaluate(Polynomial p, int k){
	Node* p_exp= (p.exponents)->head;
	Node* p_coeffs= (p.coeffs)->head;
	long long res=0;
	while(p_exp){
		res+=(p_coeffs->data*(long long)pow(k,p_exp->data));
		p_exp= p_exp->next;
		p_coeffs= p_coeffs->next;
	}
	return res;
}