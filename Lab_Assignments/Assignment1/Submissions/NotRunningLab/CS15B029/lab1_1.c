#include<stdio.h>
#include<math.h>
  struct comp{
         float p,q;
};
  struct comp addn(struct comp com1,struct comp com2){
         struct comp soln;
         
         soln.p = com1.p + com2.p;
         soln.q = com1.q + com2.q;
         return soln;}
  struct comp subt(struct comp com1,struct comp com2){
         struct comp soln;
         
         soln.p = com1.p - com2.p;
         soln.q = com1.q - com2.q;
         return soln;}
  struct comp prod(struct comp com1,struct comp com2){
         struct comp soln;

         soln.p = com1.p*com2.p - com1.q*com2.q;
         soln.q = com1.p*com2.q + com1.q*com2.p;
         return soln;}
  struct comp divi(struct comp com1,struct comp com2){
         struct comp soln;

         soln.p = (com1.p*com2.p + com1.q*com2.q)/(com2.p*com2.p + com2.q*com2.q);
         soln.q = (com1.q*com2.p - com1.p*com2.p)/(com2.p*com2.p + com2.q*com2.q);
         return soln;}
  float dist(struct comp com1,struct comp com2){
        float d;
         d=sqrt(((com1.p-com2.p)*(com1.p-com2.p))+((com1.q-com2.q)*(com1.q-com2.q)));
        return d;}
  int main(){
          struct comp c1;
         struct comp c2;
         struct comp c3;
         float d;
   
        int c;
       
     while(c!=0)
{  scanf("%f%f",&c1.p,&c1.q);
   scanf("%f%f",&c2.p,&c2.q); 
       scanf("%d",&c);
        
    switch(c){
      case 1:c3=addn(c1,c2); break;
      case 2:c3=subt(c1,c2); break;
      case 3:c3=prod(c1,c2); break;
      case 4:c3=divi(c1,c2); break;
      case 5:d=dist(c1,c2);printf("%.6f\n",d); break;}
      if(c3.q<0)
        printf("%f - %fi\n",c3.p,-c3.q);
        else
        printf("%f + %fi\n",c3.p,c3.q);
}
 return 0;
}
      

              
