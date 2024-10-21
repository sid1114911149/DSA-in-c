#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head,*tail,*temp,*temp2,*temp3,*temp4;
struct node *newnode(int d){
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=d;
    return temp;
}
struct node *construct(struct node *first,struct node *last){
    temp=first;
    temp3=first;
    temp2=temp;
    while(temp3!=last){
        temp->data=temp3->data;
        temp3=temp3->next;
        temp->next=temp3;
    }
    temp->data=temp3->data;
    temp->next=NULL;
    return temp2;
}
void sort(struct node *first,struct node *last,struct node *mid){
    struct node *llist=construct(first,mid),*rlist=construct(mid->next,last);
    temp=first;
    temp2=llist;
    temp3=rlist;
    int n;
    while(temp2!=NULL || temp3!=NULL){
        if(temp2->data<temp3->data || (temp2!=NULL && temp3==NULL)){
            n=temp2->data;
            temp2=temp2->next;
        }else{
            n=temp3->data;
            temp3=temp3->next; 
        }
        if(first==NULL){
            first=newnode(n);
            last=first;
        }else{
            temp4=newnode(n);
            tail->next=temp4;
            tail=temp;
        }
    }
}
struct node *calmid(struct node *first,struct node *last){
    temp=first;
    temp2=first;
    while(temp2!=last && temp2->next!=last){
        temp=temp->next;
        temp2=temp2->next->next;
    }
    return temp;
}
void merge(struct node *first,struct node *last){
    if(first!=last){
        struct node *mid=calmid(first,last);
        merge(first,mid);
        merge(mid->next,last);
        sort(first,last,mid);
    }
}
void print(struct node *temp){
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main(){
    int n,d;
    printf("enter no of elements in the list:");
    scanf("%d",&n);
    printf("enter elements of the list:");
    for(int i=0;i<n;i++){
        scanf("%d",&d);
        if(head==NULL){
            head=newnode(d);
            tail=head;
        }else{
            temp=newnode(d);
            tail->next=temp;
            tail=temp;
        }
    }
    merge(head,tail);
    print(head);
    return 0;
}