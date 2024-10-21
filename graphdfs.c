#include<stdio.h>
#include<stdlib.h>
#define M 1000
static int stacks[M],top=-1,list[M],index=-1;
struct node{
    int data;
    struct node *next;
}*temp,*arr[100],*temp1;
struct node * insert(int d){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=d;
    return temp;
}
struct node *create(struct node* temp,int d){
    if(temp==NULL){
        temp=insert(d);
    }
    else{
        temp->next=create(temp->next,d);
    }
    return temp;
}
struct node* create1(int i,int d){
    if(arr[i]==NULL){
        arr[i]=create(arr[i],d);
    }
    else{
        create(arr[i],d);
    }
}
void push(int a){
    if(top==M-1){
        printf("OVERFLOW\n");
        return ;
    }
    top++;
    stacks[top]=a;
}
void pop(){
    if(top==-1){
        printf("OVERFLOW\n");
        return ;
    }
    printf("dequeued %d\n",stacks[top]);
    top--;
}
int check1(int a){
    for(int i=0;i<=index;i++){
        if(list[i]==a){
            return 1;
        }
    }
    return 0;
}
int check2(int a){
    for(int i=0;i<=top;i++){
        if(stacks[i]==a){
            return 1;
        }
    }
    return 0;
}
int check(int a){
    int count1=0,count2=0;
    for(int i=0;i<=index;i++){
        if(list[i]==a){
            count1++;
        }
    }
    for(int i=0;i<=top;i++){
        if(stacks[i]==a){
            count2++;
        }
    }
    if(count1==0 && count2==0){
        return 0;
    }
    return 1;
}
void addlist(){
    if(top!=-1){
        index++;
        list[index]=stacks[top];
        printf("listed %d\n",list[index]);
        pop();
    }
}
/*int getelement(int a,int n){
    for(int i=0;i<n;i++){
        if(arr[i]->data==a){
            return 1;
        }
    }
    return -1;
}*/
void dfstraverse(int i,int n){
    if(index==n-1 || i>=n){
        return ;
    }
    temp=arr[i];
    if(!check(temp->data)||(top==-1 && index==-1)){
        push(temp->data);
        printf("enqueued %d\n",temp->data);
    }
    if(top==n-1){
        for(int i=0;i<n;i++){
            addlist();
        }
        return ;
    }
    if(temp->next!=NULL){
        temp=temp->next;
        for(int i=0;i<n;i++){
            if(arr[i]->data==temp->data){
                if(!check(temp->data)){
                    dfstraverse(i,n);
                    return;
                }
                else if(temp->next==NULL){
                    break;
                }
                else{
                    temp=temp->next;
                    i=0;
                }
            }
    }
    }
    if(temp->next==NULL){
        if(!check1(temp->data) || index==-1){
            addlist();
        }
        else{
            pop();
        }
        if(top!=-1){
            for(int j=0;j<n;j++){
                if(arr[j]->data==stacks[top]){
                    dfstraverse(j,n);
                    return ;
                }
            }
        }
    }
    else{
        pop();
    }
}
void print(int n){
    for(int i=0;i<n;i++){
        temp=arr[i];
        while(temp!=NULL){
            if(temp->next==NULL){
                printf("%d\n",temp->data);
            }
            else{
                printf("%d->",temp->data);
            }
            temp=temp->next;
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
    print(n);
    dfstraverse(0,n);
    for(int i=0;i<=index;i++){
        printf("%d\t",list[i]);
    }
    return 0;
}