#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*new,*new2,*head,*tail,*head2,*tail2,*temp,*g,*k,*m,*i,*j;
void sort();
int main()
{
    int ch=1,n;
    int pos,count=0,p,count2=0;
    printf("enter 1 LINKED LIST:\n");
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
    ch=1;
    printf("enter 2 LINKED LIST:\n");
    while(ch)
    {
        new2=(struct node*)malloc(sizeof(struct node));
        printf("enter value:");
        scanf("%d",&new2->data);
        new2->next=NULL;
        if(head2==NULL)
        {
            head2=new2;
            tail2=new2;
        }
        else
        {
        
            tail2->next=new2;
            tail2=new2;
        }
        count2++;
        printf("enter 1 to enter another element else 0:");
        scanf("%d",&ch);
    }
    printf("entered elements before sorting:\n");
    printf("first linked list:\n");
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n"); 
    printf("second linked list:\n");
    temp=head2;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n"); 
    tail->next=head2;
    sort(head);
    printf("after merging and sorting the linked lists:\n");
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n"); 
    return 0;
}
void sort(struct node *i)
{
    int l;
    while( i!=NULL)
    {
        j=i->next;
        while(j!=NULL)
        {
            if(i->data>j->data)
            {
                l=i->data;
                i->data=j->data;
                j->data=l;
            }  
            j=j->next;
        }   
        i=i->next;
    }  
}