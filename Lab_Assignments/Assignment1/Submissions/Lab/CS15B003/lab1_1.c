/*Various functions on Complex numbers using structures*/
#include<stdio.h>
#include<math.h>

struct comp				//Defining a structure
{ 
	float p,q;
};

struct comp add(struct comp comp1, struct comp comp2);
struct comp sub(struct comp comp1, struct comp comp2);
struct comp mult(struct comp comp1, struct comp comp2);
struct comp div(struct comp comp1, struct comp comp2);

float dist(struct comp comp1, struct comp comp2);

void main(){

		struct comp comp1;
		struct comp comp2;
		struct comp compr;

		int opt;
	
		while(1){					//Unless the user wants to exit, keeps looping in

		scanf("%f %f", &comp1.p, &comp1.q);
		scanf("%f %f", &comp2.p, &comp2.q);
		scanf("%d",&opt);

		if((opt==-1)||(opt==0)) return;		
		
		switch(opt){
		case 1 : { compr = add(comp1, comp2);
				   if(compr.q>=0)
			   	   printf("%f+%fi\n",compr.p, compr.q);
			   	   else 
			   	   printf("%f%fi\n",compr.p, compr.q);
			       break;}
		case 2 : { compr = sub(comp1, comp2);
			   	   if(compr.q>=0)
			   	   printf("%f+%fi\n",compr.p, compr.q);
			   	   else 
			   	   printf("%f%fi\n",compr.p, compr.q);
			       break;}
		case 3 : { compr = mult(comp1, comp2);
			   	   if(compr.q>=0)
			   	   printf("%f+%fi\n",compr.p, compr.q);
			   	   else 
			   	   printf("%f%fi\n",compr.p, compr.q);
			       break;}
		case 4 : { compr = div(comp1, comp2);
			   	   if(compr.q>=0)
			   	   printf("%f+%fi\n",compr.p, compr.q);
			   	   else 
			   	   printf("%f%fi\n",compr.p, compr.q);
			       break;}           
		case 5 : { printf("%f\n",dist(comp1, comp2));
			       break;}
		
		}

	}
	return;
}
	struct comp add(struct comp comp1, struct comp comp2){			//Adds the complex numbers
			struct comp result;
			result.p = comp1.p + comp2.p;
			result.q = comp1.q + comp2.q;
		
			return result;
		}
	struct comp sub(struct comp comp1, struct comp comp2){			//Subtracts the complex numbers numbers																
			struct comp result;
			result.p = comp1.p - comp2.p;
			result.q = comp1.q - comp2.q;
		
			return result;
		}
	struct comp mult(struct comp comp1, struct comp comp2){			//Multiplies the complex numbers
			struct comp result;
			result.p = ((comp1.p)*(comp2.p))-((comp1.q)*(comp2.q));
			result.q = ((comp1.p)*(comp2.q))-((comp1.q)*(comp2.p));
		
			return result;
		}
	struct comp div(struct comp comp1, struct comp comp2){			//Divides the complesx numbers
			struct comp result;
			float mod;
			mod = ((comp2.p)*(comp2.p)+(comp2.q)*(comp2.q));
			result.p = (((comp1.p)*(comp2.p))+((comp1.q)*(comp2.q)))/mod;
			result.q = (((comp1.q)*(comp2.p))-((comp1.p)*(comp2.q)))/mod;
		
			return result;
		}
	float dist(struct comp comp1, struct comp comp2){				//Finds the distance between two complex numbers
			float result;
			result = sqrt((comp1.p - comp2.p)*(comp1.p - comp2.p)+(comp1.q - comp2.q)*(comp1.q - comp2.q));
			return result;
		}

