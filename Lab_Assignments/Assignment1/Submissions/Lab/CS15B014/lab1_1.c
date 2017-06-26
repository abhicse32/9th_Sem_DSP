//Implement Abstract Data Type(ADT) Complex Number and associated operations on them
// name D Teja Vardhan Reddy   CS15B014  date 8/8/16
#include<stdio.h>
#include<math.h>
typedef struct complex {
	float f;
	float d;
} comp;

void sub(comp x,comp y){    /*performs subraction*/
	if(x.d-y.d>0)
		printf("%f+%fi",x.f-y.f,x.d-y.d);
	else
		printf("%f%fi",x.f-y.f,x.d-y.d);
}
void add(comp x,comp y){   /* perfrms addition*/
	if(x.d+y.d>0)
		printf("%f+%fi",x.f+y.f,x.d+y.d);
	else
		printf("%f%fi",x.f+y.f,x.d+y.d);
}
void mul(comp x,comp y){		/* performs multiplication*/
	if(x.d*y.f+x.f*y.d>0)
		printf("%f+%fi",x.f*y.f-x.d*y.d,x.d*y.f+y.d*x.f);
	else
		printf("%f%fi",x.f*y.f-x.d*y.d,x.d*y.f+y.d*x.f);
}
void div(comp x,comp y){		/*performs division*/
	comp z;
	int t;
	t=(y.f)*(y.f)+(y.d)*(y.d);
	z.f=y.f/t;
	z.d=-y.d/t;
	mul(x,z);
}
void dist(comp x,comp y){			/*finds distance*/
	float t;
	t=(x.f-y.f)*(x.f-y.f)+(x.d-y.d)*(x.d-y.d);
	printf("%.8f",sqrt(t));
}
int main(){     			/* main function*/
	int i=1;
	while(i==1){
		comp x,y;
		scanf("%f%f",&x.f,&x.d);
		scanf("%f%f",&y.f,&y.d);
		int t;
		scanf("%d",&t);
		if(t==-1||t==0)
		return 0;
		else{
			switch(t)			// switch statement
			{
				case 1:add(x,y);break;
				case 2:sub(x,y);break;  		//function call
				case 3:mul(x,y);break;
				case 4:div(x,y);break;
				case 5:dist(x,y);break;
				default:printf("INVALID");
			}
		}
	}
	return 0;
}

