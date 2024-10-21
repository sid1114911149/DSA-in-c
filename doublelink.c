#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*head,*tail,*new,*new1,*temp;
int main()
{
    int ch=1;
    //head->prev=NULL;
   // temp=head;
    while(ch)
    {
        new=(struct node*)malloc(sizeof(struct node));
        printf("enter element:");
        scanf("%d",&new->data);
        new->next=NULL;
        new->prev=temp;
        //head->prev=NULL;
        if(head==NULL)
        {
            head=new;
            tail=new;
        }
        else
        {
            tail->next=new;
           // tail->prev=temp;
            tail=new;
        }
        temp=new;
        printf("enter 1 to enter another element else 0:");
        scanf("%d",&ch);
    }
    //tail->next=NULL;
    printf("entered elements :\n");
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
    printf("entered elements in reverse order:\n");
    temp=tail;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->prev;
    }
    return 0;
    
}