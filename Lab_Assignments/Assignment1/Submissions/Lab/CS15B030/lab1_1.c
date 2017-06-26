#include <stdio.h>
#include <math.h>
#include <limits.h>
struct Cmplx {

    double a,b;

};

struct Cmplx add (struct Cmplx cmp1, struct Cmplx cmp2) {
    struct Cmplx ans;
    ans.a = cmp1.a + cmp2.a;
    ans.b = cmp1.b + cmp2.b;
    return ans;
}

struct Cmplx sub (struct Cmplx cmp1, struct Cmplx cmp2) {
    struct Cmplx ans;
    ans.a = cmp1.a - cmp2.a;
    ans.b = cmp1.b - cmp2.b;
    return ans;
}

struct Cmplx mul (struct Cmplx cmp1, struct Cmplx cmp2) {
    struct Cmplx ans;
    ans.a = cmp1.a * cmp2.a - cmp1.b * cmp2.b;
    ans.b = cmp1.a * cmp2.b + cmp1.b * cmp2.a;
    return ans;
}

struct Cmplx div (struct Cmplx cmp1, struct Cmplx cmp2) {
    struct Cmplx ans;
    double x = cmp2.a * cmp2.a + cmp2.b * cmp2.b;
    if(x==0){
     ans.a = ans.b = INT_MIN;
     return ans;
    }
    x = sqrt(x);
    ans.a = (cmp1.a * cmp2.a + cmp1.b * cmp2.b) / x;
    ans.b = (cmp2.a * cmp1.b - cmp1.a * cmp2.b) / x;
    return ans;
}

double dist (struct Cmplx cmp1, struct Cmplx cmp2) {
    double x, y;
    x = cmp1.a -cmp2.a ;
    y = cmp1.b - cmp2.b ;
    return sqrt(x*x + y*y);
}

int main(){
    struct Cmplx cmp1,cmp2,ans;
    while(1){
      scanf ("%lf%lf",&cmp1.a,&cmp1.b);
      scanf ("%lf%lf",&cmp2.a,&cmp2.b);
      int func;
      scanf ("%d",&func);
      if(func == 0 || func == -1){
        return 0;
      }
      if(func == 5){
        double res = dist(cmp1,cmp2);
        printf("%.6f\n",res);
        continue;
      }
      switch(func) {
          case 1:
            ans = add(cmp1,cmp2);
            break;
          case 2:
            ans = sub(cmp1,cmp2);
            break;
          case 3:
            ans = mul(cmp1,cmp2);
            break;
          case 4:
            ans = div(cmp1,cmp2);
            break;
      }
      if(ans.a == INT_MIN){
       printf("divide by zero error\n");
       continue;
      }
      printf("%f ",ans.a);
      if(ans.b < 0){
        printf("- %fi\n",-1*ans.b);
      } else if(ans.b >=0){
        printf("+ %fi\n",ans.b);
      }
    }
  return 0;
}
