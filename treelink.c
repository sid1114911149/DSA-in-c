#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*root,*head,*tail,*new,*temp,*new1,*temp2,*new2;
void createroot(struct node *new);
void create(struct node *new);
void print(struct node *i,struct node *j);
static int count=0;
int main()
{
    int n,ch=1;
    //printf("enter elements of the tree:");
    createroot(root);
    temp=root;
    while(temp->next!=NULL || temp->prev!=NULL)
    {
        if(temp->prev!=NULL)
            create(temp->prev);
        if(temp->next!=NULL)
            create(temp->next);  
        temp=temp->prev;
        if(temp->next==NULL || temp->prev==NULL)  
        {
            temp=temp->next->next;
        }                
    }
    printf("entered elements:");
    return 0;
}
void createroot(struct node *new)
{
    int n;
    new=(struct node *)malloc(sizeof(struct node));
    new->next=NULL;
    new->prev=NULL;
    printf("enter the root:");
    scanf("%d",&new->data);
    printf("enter 1 to enter its left child:");
    scanf("%d",&n);
    if(n!=0)
    {
        new1=(struct node *)malloc(sizeof(struct node));
        new1->next=NULL;
        new1->prev=NULL;
        new->prev=new1;
        printf("enter element:");
        scanf("%d",&new1->data);
    }
    printf("enter 1 to enter its right child:");
    scanf("%d",&n);
    if(n!=0)
    {
        new2=(struct node *)malloc(sizeof(struct node));
        new2->next=NULL;
        new2->prev=NULL;
        new->next=new2;
        printf("enter element:");
        scanf("%d",&new2->data);
    }
    count++;
}
void create(struct node *new)
{
    int n;
    printf("enter 1 to enter its left child:");
    scanf("%d",&n);
    if(n!=0)
    {
        new1=(struct node *)malloc(sizeof(struct node));
        new1->next=NULL;
        new1->prev=NULL;
        new->prev=new1;
        printf("enter element:");
        scanf("%d",&new1->data);
    }
    printf("enter 1 to enter its right child:");
    scanf("%d",&n);
    if(n!=0)
    {
        new2=(struct node *)malloc(sizeof(struct node));
        new2->next=NULL;
        new2->prev=NULL;
        new->next=new2;
        printf("enter element:");
        scanf("%d",&new2->data);
    }
    count++;
}
void print(struct node *i,struct node *j)
{
    
    if(i!=NULL)
    {
        printf("%d\t",i->data);
    }
    else
        printf("\t\t");
    if(j!=NULL)
    {
        printf("%d",j->data);
    }
}