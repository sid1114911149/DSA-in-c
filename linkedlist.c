#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*new,*head,*tail;
int main()
{
    head=(struct node*)malloc(sizeof(struct node));
    printf("enter the value:");
    scanf("%d",&head->data);
    head->next=NULL;
    printf("entered  value is:%d",head->data);
    return 0;
}