#include<stdio.h>
#include<math.h>

struct complx{
float r;
float i;
};

//typedef struct complx complx;

void add( struct complx c1, struct complx c2){
	struct complx add;
//	struct complx c1;
//	struct complx c2;
	//c1.r=p1.r;
	//c1.i=p1.i;	
	//c1.r=p1.r;
	//c1.i=p1->i;
	add.r=c1.r+c2.r;
	add.i=c1.i+c2.i;
	printf("%f  + %fi\n",add.r,add.i);
}

void sub(struct complx c1,struct complx c2){
	struct complx sub;

	sub.r=c1.r-c2.r;
	sub.i=c1.i-c2.i;
	printf("%f + %fi\n",sub.r,sub.i);
}

void mul(struct complx c1,struct complx c2){
	struct complx mul;
//	struct complx c1;
//	struct complx c2;
	mul.r=c1.r*c2.r-c1.i*c2.i;
	mul.i=c1.i*c2.r+c1.r*c2.i;
	printf("%f + %fi\n",mul.r,mul.i);
}

void div(struct complx c1,struct complx c2){
	struct complx div;
//	struct complx c1;
//	struct complx c2;
	div.r=(c1.r*c2.r+c1.i*c2.i)/(c2.r*c2.r+c2.i*c2.i);
	div.i=(c1.i*c2.r-c1.r*c2.i)/(c2.r*c2.r+c2.i*c2.i);
	printf("%f + %fi\n",div.r,div.i);
}

void mod(struct complx c1,struct complx c2){
	float mod;
//	struct complx c1;
//	struct complx c2;
	mod=sqrt((c1.r-c2.r)*(c1.r-c2.r)+(c1.i-c2.i)*(c1.i-c2.i));
	//mod=(c1.r*c2.r+c1.i*c2.i)/(c2.r*c2.r+c2.i*c2.i);
	//mod=(c1.i*c2.r-c1.r*c2.i)/(c2.r*c2.r+c2.i*c2.i);
	printf("%f\n",mod);
}

int main(){
	struct complx c1;
	struct complx c2;
	int o;
	scanf("%f%f",&c1.r,&c1.i);
	scanf("%f%f",&c2.r,&c2.i);
	for(;1;){
		scanf("%d",&o);
		if(o==1){
			add(c1,c2);
		}
		else if(o==2){
			sub(c1,c2);
		}
		else if(o==3){
			mul(c1,c2);
		}
		else if(o==4){
			div(c1,c2);
		}
		else if(o==5){
			mod(c1,c2);
		} 
		else if(o==0||o==-1){
			break;
		}
	}
	return 0;
}
