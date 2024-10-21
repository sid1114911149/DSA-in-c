#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*new,*head,*tail,*temp,*p,*s;
int main()
{
    int ch=1,n;
    int pos,count=0,k;
    while(ch)
    {
        new=(struct node*)malloc(sizeof(struct node));
        printf("enter value:");
        scanf("%d",&new->data);
        new->next=NULL;
        if(head==NULL)
        {
            head=new;
            tail=new;
        }
        else
        {
        
            tail->next=new;
            tail=new;
        }
        count++;
        printf("enter 1 to enter another element else 0:");
        scanf("%d",&ch);
    }
    printf("before reversing elements:\n");
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
    n=count;
    temp=head;
    for(int i=0;i<count;i++)
    {
        p=temp;
        for(int j=0;j<n-1;j++)
        {
            p=p->next;
        } 
        if(i==0)
        {
            head=p;
            tail=p;
        }
        else 
        {
            tail->next=p;
            tail=p;
        }
        n--;
    }  
    tail->next=NULL;  
    printf("after reversing elements:\n");   
    temp=head;
    k=0;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    return 0;
}