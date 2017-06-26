#include<stdio.h>

int gcd(int number1, int number2);

void find_divisors(int divisor);

void main() {
    int number1, number2, common_divisor;
    scanf("%d %d", &number1, &number2);
    common_divisor = gcd(number1, number2);
    find_divisors(common_divisor);
}

int gcd(int number1, int number2) {
    if (number1 == 0)
        return number2;
    else if (number2 == 0)
        return number1;
    else if (!(number1 & 1) && !(number2 & 1))
        return gcd(number1 >> 1, number2 >> 1) << 1;
    else if (!(number1 & 1) && (number2 & 1))
        return gcd(number1 >> 1, number2);
    else if ((number1 & 1) && !(number2 & 1))
        return gcd(number1, number2 >> 1);
    else if (number1 > number2)
        return gcd(number1 - number2, number2);
    else
        return gcd(number1, number2 - number1);
}

void find_divisors(int divisor) {
    static int prime[100], i, j,index=0,flag=1;
    if (!(divisor%2))
        prime[index++]=2;
    for (i=3; i <= divisor; i+=2) {
        if (!(divisor%i)){
            flag=1;
            for(j=0;prime[j]!=0;j++){
                if (!(i%prime[j])){
                    flag=0;
                    break;
                }
            }
            if (flag){
                prime[index++]=i;
            }
        }
    }
    for(i=0;prime[i]!=0;i++){
        printf("%d ",prime[i]);
    }
    printf("\n");
}
