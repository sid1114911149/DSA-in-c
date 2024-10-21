#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define M 2000
static int arr[M],arr2[M],size,count=0;
void create(){
    size=-1;
    printf("heap created successfully\n");
}
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
void arrange(){
    int index=size;
    while(index>=1){
        int parent=(index-1)/2;
        if(arr[parent]<arr[index]){
            swap(&arr[index],&arr[parent]);
        }
        index=parent;
    }
}
void insert(int a){
    if(size==M-1){
        printf("OVERFLOW\n");
        return ;
    }
    size++;
    arr[size]=a;
    arrange(size);
}
void arrange2(int s){
    int index=0;
    int large=0;
    while(index<s/2){
        count++;
        int lchild=2*index+1;
        int rchild=2*index+2;
        if(arr[lchild]>arr[rchild]){
            large=lchild;
        }else{
            large=rchild;
        }
        if(arr[large]>arr[index]){
            swap(&arr[index],&arr[large]);
            index=large;
        }else{
            return ;
        }
    }
}
void sort(){
    for(int i=size;i>=0;){
        count+=1;
        swap(&arr[0],&arr[i]);
        i--;
        arrange2(i);
    }
    //print();
}
void rev(){
    for(int i=0;i<size/2;i++){
        swap(&arr[i],&arr[size-i]);
    }
}
int main(){
    FILE *f,*f1;
    int k;
    create();
    f=fopen("temp.txt","a");
    for(int i=0;i<2000;i++){
        fprintf(f,"%d,",rand()%3000);
    }
    fprintf(f,"\n");
    f1=fopen("temp.txt","r");
    for(int i=0;i<2000;i++){
        fscanf(f1,"%d,",&k);
        insert(k);
    }
    fclose(f1);
    //print();
    sort();
    for(int i=0;i<2000;i++){
        fprintf(f,"%d,",arr[i]);
    }
    count=0;
    sort();
    printf("NO OF COMPARISIONS FOR THE BEST CASE IS:%d\n",count);
    count=0;
    rev();
    sort();
    printf("NO OF COMPARISIONS FOR THE WORST CASE IS:%d\n",count);
    fprintf(f,"\n");
    fclose(f);
    return 0;
}
