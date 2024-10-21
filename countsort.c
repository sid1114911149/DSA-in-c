#include<stdio.h>
#include<stdlib.h>
#define M 1000
int main(){
    int n,arr[M],arr2[M],max;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        arr[i]=rand()%1000;
    }
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int *C=(int *)malloc(sizeof(int)*(max+1));
    for(int i=0;i<=max;i++){
        C[i]=0;
    }
    for(int i=0;i<n;i++){
        C[arr[i]]++;
    }
    for(int i=1;i<=max;i++){
        C[i]+=C[i-1];
    }
    for(int i=0;i<n;i++){
        arr2[C[arr[i]]]=arr[i];
        C[arr[i]]--;
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr2[i]);
    }
    printf("\n");
    return 0;
}