#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define M 1000
static int queue[M],arr[M][2],front=-1,rear=-1,size=-1;
void enqueue(int a){
    if(rear==M-1){
        return ;
    }
    if(front==-1){
        front++;
    }
    rear++;
    queue[rear]=a;
}
int dequeue(){
    int t=front;
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front++;
    }
    return queue[t];
}
void print(){
    if(size==-1){
        return ;
    }
    for(int i=0;i<=size;i++){
        printf("element is %d priority is %d\n",arr[i][0],arr[i][1]);
    }
    printf("\n");
}
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void arrange(){
    if(size==-1){
        return ;
    }
    int index=size;
    while(index>=1){
        int parent =(index-1)/2;
        if(arr[parent][1]<arr[index][1]){
            swap(&arr[parent][1],&arr[index][1]);
            swap(&arr[parent][0],&arr[index][0]);
        } 
        index=parent;
    }
}
void insert(int a,int p){
    if(size==M-1){
        return ;
    }
    size++;
    arr[size][0]=a;
    arr[size][1]=p;
    arrange();
}
void add(){
    if(rear==-1){
        return ;
    }
    int k;
    for(int i=front;i<=rear;i++){
        k=rand()%100;
        insert(queue[i],k);
    }
}
int find(int a){
    for(int i=front;i<=rear;i++){
        if(queue[i]==a){
            return i;
        }
    }
}
void arrange2(int index){
    if(size==-1){
        return ;
    }
    int large;
    int lchild,rchild;
    int i,j;
    while(index<(size+1)/2){
        large=index;
        lchild=2*index+1;
        rchild=2*index+2;
        if(rchild<=size && arr[lchild][1]<=arr[rchild][1]){
            if(arr[lchild][1]==arr[rchild][1]){
                i=find(arr[lchild][0]);
                j=find(arr[rchild][0]);
                if(i<j){
                    large=lchild;
                }
                else{
                    large=rchild;
                }
            }
            else{
                large=rchild;
            }
        }else if(lchild<=size){
            large=lchild;
        }
        if(arr[large][1]<=arr[index][1]){
            if(arr[large][1]==arr[index][1]){
                i=find(arr[large][0]);
                j=find(arr[index][0]);
                if(i>j){
                    large=index;
                }
            }
            else{
                large=index;
            }
        }
        if(large!=index){
            swap(&arr[index][0],&arr[large][0]);
            swap(&arr[index][1],&arr[large][1]);
            index=large;
        }
        else{
            return ;
        }
    }
}
void deletemax(){
    if(size==-1){
        return ;
    }
    printf("element is %d priority is %d is deleted\n",arr[0][0],arr[0][1]);
    arr[0][0]=arr[size][0];
    arr[0][1]=arr[size][1];
    size--;
    arrange2(0);
}
int main(){
    int k;
    for(int i=0;i<100;i++){
        k=rand()%1000;
        enqueue(k);
    }
    for(int i=front;i<=rear;i++){
        printf("%d,",queue[i]);
    }
    printf("\n");
    add();
    print();
    k=size;
    for(int i=0;i<=k;i++){
        deletemax();
    }
    return 0;
}