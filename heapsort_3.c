#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define M 1000
static int arr[M],size=-1;
void print(){
    if(size==-1){
        printf("UNDERFLOW\n");
        return ;
    }
    for(int i=0;i<=size;i++){
        printf("%d,",arr[i]);
    }
    printf("\n");
}
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void arrange(int arr1[],int s){
    if(s==0){
        return ;
    }
    int index=s;
    while(index>=1){
        int parent=(index-1)/2;
        if(arr1[parent]<arr1[index]){
            swap(&arr1[parent],&arr1[index]);
            index=parent;
        }else{
            return ;
        }
    }
}
void insert(int arr1[],int s,int d){
    if(size==M-1){
        printf("OVERFLOW\n");
        return ;
    }
    s++;
    arr1[s]=d;
    arrange(arr1,s);
}
void merge(int arr1[],int n){
    if(size==M-1 || n==-1){
        return ;
    }
    for(int i=0;i<n;i++){
        size++;
        insert(arr,size,arr1[i]);
    }
}
void arrange2(int arr1[],int s){
    int index=0;
    int large,lchild,rchild;
    while(index<s/2){
        lchild=2*index+1;
        rchild=2*index+2;
        large=index;
        if(arr1[lchild]>arr1[rchild]){
            large=lchild;
        }else{
            large=rchild;
        }
        if(arr1[large]>arr1[index]){
            swap(&arr1[large],&arr1[index]);
            index=large;
        }else{
            return ;
        }
    }
}
void heapsort(int arr1[],int s){
    if(s==-1){
        printf("UNDERFLOW\n");
        return ;
    }
    for(int i=s;i>0;){
        swap(&arr1[0],&arr1[i]);
        i=i-1;
        arrange2(arr1,i);
    }
}
int main(){
    int n,k,arr1[M];
    printf("enter n:");
    scanf("%d",&n);
    printf("enter k:");
    scanf("%d",&k);
    int arr2[k][n];
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            arr2[i][j]=rand()%1000;
            insert(arr1,j-1,arr2[i][j]);
        }
        heapsort(arr1,n-1);
        merge(arr1,n);
        for(int j=0;j<n;j++){
            arr2[i][j]=arr1[j];
        }
    }
    heapsort(arr,size);
    print();
    return 0;
}