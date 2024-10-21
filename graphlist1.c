#include<stdio.h>
#include<stdlib.h>
#define M 1000
static int rear=-1,front=-1,top=-1,queue[M],list[M],index=-1;
struct node{
    int data;
    //char ch[10];
    struct node *next;
}*temp,*arr[10],*t;
struct node *insert(int d){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=d;
    return temp;
}
struct node *create(struct node *temp,int d){
    if(temp==NULL){
        temp=insert(d);
    }
    else{
        temp->next=create(temp->next,d);
    }
    return temp;
}
struct node *create1(int a,int d){
    if(arr[a]==NULL){
        arr[a]=create(arr[a],d);
    }
    else{
        create(arr[a],d);
    }
    
}
void print(int i){
    t=arr[i];
    while(t!=NULL){
        if(t->next!=NULL)
            printf("%d->",t->data);
        else
            printf("%d",t->data);
        t=t->next;
    }
    printf("\n");
}
void enqueue(int a){
    if(rear==M-1){
        printf("OVERFLOW\n");
        return;
    }
    if(front==-1){
        front++;
    }
    rear++;
    queue[rear]=a;
}
int dequeue(){
    int t;
    if(front==rear){
        t=front;
        front=-1;
        rear=-1;
    }
    else{
        t=front;
        front++;
    } 
    //printf("dequeued %d\n",queue[t]);
    return queue[t];
}
int check1(int a){
    for(int i=0;i<=index;i++){
        if(a==list[i]){
            return 1;
        }
    }
    return 0;
}
int check(int a){
    int count1=0,count2=0;
    for(int i=0;i<=index;i++){
        if(a==list[i]){
            count1++;
        }
    }
    for(int i=front;i<=rear;i++){
        if(a==queue[i]){
            count2++;
        }
    }
    if(count1==0 && count2==0)
        return 0;
    return 1;
}
void addlist(){
    if(front!=-1 && !check1(queue[front])){
        index++;
        list[index]=dequeue();
        //printf("listed %d\n",list[index]);
    }    
}
void bfstraverse(int i,int n){
    if(i>=n || index==n-1){
        return;
    }
    temp=arr[i];
    int count=0;
    while(temp!=NULL){
            if(!check(temp->data) ||(index==-1 && front==-1)){
                enqueue(temp->data);
                //printf("enqueued %d\n",temp->data);
            }
            temp=temp->next;
        }
        addlist();
        while(count==0 && index<n){
            for(int j=0;j<n;j++){
                if(arr[j]->data==queue[front]){
                    bfstraverse(j,n);
                    count++;
                    break;
                }
            }
            if(count==0){
                addlist();
            }
        }
}
int main(){
    int n,m,d;
    printf("enter total no of nodes in the list:");
    scanf("%d",&n);
    printf("enter nodes one by one:\n");
    for(int i=0;i<n;i++){
        printf("enter node value:");
        scanf("%d",&d);
        create1(i,d);
        printf("enter no of nodes connected with %d:",d);
        scanf("%d",&m);
        printf("enter neighbouring nodes of %d:",d);
        for(int j=0;j<m;j++){
            scanf("%d",&d);
            create1(i,d);
        }    
    }
    for(int i=0;i<n;i++){
        print(i);
    }
    bfstraverse(0,n);
    for(int i=0;i<=index;i++){
        printf("%d\t",list[i]);
    }
    return 0;
}