#include<stdio.h>
#include<stdlib.h>
double power(double x,int n){
    if(n==1){
        return x;
    }
    if(n%2==0){
        double m=power(x,n/2);
        return m*m;
    }else{
        double m=power(x,(n-1)/2);
        return m*m*x;
    }
}
int main(){
    int n,x;
    printf("enter base and exponent:");
    scanf("%d %d",&x,&n);
    printf("%d^%d=%lf\n",x,n,power(x,n));
    return 0;
}