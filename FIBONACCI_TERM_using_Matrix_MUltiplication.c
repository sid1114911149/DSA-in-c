#include<stdio.h>
#include<stdlib.h>
#include <time.h> 
int fibonacci2(int n){
    if(n==1){
        return 0;
    }else if(n==2){
        return 1;
    }
    return fibonacci2(n-1)+fibonacci2(n-2);
}
int fibonacci(int arr[2][2],int arr2[2][2],int arr3[2][2],int n,int i){
    if(n==0){
        return 0;
    }
    if(n==1 || n==2){
        return 1;
    }
    if(i==n){
        return arr[0][1];
    }
    for(int j=0;j<2;j++){
        for(int k=0;k<2;k++){
            arr3[j][k]=0;
            for(int l=0;l<2;l++){
                arr3[j][k]+=arr[j][l]*arr2[l][k];
            }
        }    
    }
    for(int j=0;j<2;j++){
        for(int k=0;k<2;k++){
            arr[j][k]=arr3[j][k];
        }
    }
    return fibonacci(arr,arr2,arr3,n,i+1);
}
int main(){
    int arr[2][2]={{1,1},{1,0}},arr2[2][2]={{1,1},{1,0}},arr3[2][2];
    int n,m,i=2;
    printf("enter n:");
    scanf("%d",&n);
    clock_t t; 
    t = clock(); 
    if(n==1){
        m=0;
    }
    else if(n==2 || n==3){
        m=1;
    }
    else{
        m=fibonacci(arr,arr2,arr3,n,2);
    }
    printf("%d term of fibonacci series is:%d\n",n,m);
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("time took to find %d fibonacci term using matrix multiplication approach is %f seconds to execute \n",n, time_taken); 
    t = clock(); 
    m=fibonacci2(n);
    printf("%d term of fibonacci series is:%d\n",n,m);
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("time took to find %d fibonacci term using naive approach is %f seconds to execute \n",n, time_taken); 
    return 0;
}