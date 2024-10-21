#include<stdio.h>
#include<stdlib.h>
#define M 1000
static int front=-1,rear=-1;
struct node{
    int data;
    struct node *left,*right,*parent;
}*root,*temp,*temp2,*temp3,*queue[M];
struct node *new(int d){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->left=temp->right=temp->parent=NULL;
    temp->data=d;
    return temp;
}
void push(struct node *temp){
    if(temp==NULL){
        return ;
    }
    if(front==-1){
        front++;
    }
    rear++;
    queue[rear]=temp;
    printf("pushed %d\n",temp->data);
    push(temp->left);
    push(temp->right);
}
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void arrange(struct node *temp){
    if(temp->parent==NULL || temp==NULL){
        return ;
    }
    while(temp!=NULL && temp->parent!=NULL){
        temp2=temp->parent;
        if(temp->data>temp2->data){
            swap(&temp->data,&temp2->data);
            temp=temp2;
        }
        else{
            return ;
        }
    }
}
struct node * create(struct node *temp,int d){
    if(temp==NULL){
        temp=new(d);
        printf("hello %d\n",temp->data);
        temp3=temp;
    }
    else{
        int k;
        front=-1;
        rear=-1;
        push(root);
        if(rear%2!=0){
           k=(rear-1)/2;
           temp2=queue[k];
           temp3=new(d);
           temp2->right=temp3;
           temp3->parent=temp2;
        }
        else{
            k=(rear/2)+1;
            temp2=queue[k];
            temp3=new(d);
            temp2->left=temp3;
            temp3->parent=temp2;
        }
        arrange(temp3);
    }
    return temp3;
}
void create1(int d){
    if(root==NULL){
        root=create(root,d);
    }
    else{
        create(root,d);
    }
}
void print(struct node *temp){
    if(temp==NULL){
        printf("nothing\n");
        return ;
    }
    front=-1;
    rear=-1;
    push(root);
    for(int i=front;i<=rear;i++){
        printf("%d,",queue[i]);
    }
    printf("\n");
}
int main(){
    create1(1);
    create1(2);
    create1(3);
    create1(4);
    create1(5);
    create1(6);
    create1(7);
    create1(8);
    create1(9);
    create1(0);
    print(root);
    return 0;
}

