#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*arr[10],*temp;
int hashfunction(int n){
    return n%10;
}
struct node * insert(int n){
    struct node *temp=(struct node*)malloc(sizeof(struct node*));
    temp->next=NULL;
    temp->data=n;
    return temp;
}
struct node *create(struct node *temp,int d){
    if(temp==NULL){
        temp=insert(d);
    }else{
        temp->next=create(temp->next,d);
    }
    return temp;
}
int main(){
    int arr[]={234,35,56,3,7,4,5,467,2,1,0,678,3452};//13
    int a=arr[0],k=0;
    for(int i=1;i<13;i++){
        if(arr[i]>a)
            a=arr[i];
    }
    for(int i=0;i<k;i++){
        a=0;

    }
}