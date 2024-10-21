#include<stdio.h>
#include<stdlib.h>
struct node
{
    float coef;
    int expo;
    struct node *next;
}*new,*new2,*head,*tail,*temp,*head2,*tail2,*temp3,*temp2,*k,*j,*head3,*tail3,*new3,*temp4;
void sort(struct node *i);
void display(struct node *i);
void add(struct node *i,struct node *j);
void multiply(struct node *i,struct node *k);
int main()
{
    int ch=1,n,k,m,c;
    int pos,count=0,count2=0,p;
    printf("enter  1 polynomial \n");
    while(ch)
    {
        new=(struct node*)malloc(sizeof(struct node));
        printf("enter coefficient:");
        scanf("%f",&new->coef);
        printf("enter exponent:");
        scanf("%d",&new->expo);
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
    sort(head);
    ch=1;
    printf("enter  2 polynomial\n");
    while(ch)
    {
        new2=(struct node*)malloc(sizeof(struct node));
        printf("enter coefficient:");
        scanf("%f",&new2->coef);
        printf("enter exponent:");
        scanf("%d",&new2->expo);
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
    sort(head2);
    printf("1 polynomial:\n");
    display(head);
    printf("2 polynomial:\n");
    display(head2);
    printf("enter 1 for addition and 2 for multiplication: ");
    scanf("%d",&k);
    if(k==1)
    {
        printf("sum of two polynomials:");
        add(tail,head2);  
        sort(head);
        display(head); 	
    }
    else
    {
        multiply(head,head2);
    }                
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
            if(i->expo==j->expo)
            {
                i->coef=i->coef+j->coef;
                k=i;
                while(k->next!=j)
                    k=k->next;
                k->next=j->next;    
            }    
            else if(i->expo<j->expo)
            {
                l=i->expo;
                i->expo=j->expo;
                j->expo=l;
                l=i->coef;
                i->coef=j->coef;
                j->coef=l;
            }  
            j=j->next;
        }   
        i=i->next;
    }  
}
void display(struct node *i)
{
    temp3=i;
    while(temp3!=NULL)
    {
        printf("(%0.1fx^%d)",temp3->coef,temp3->expo);
        temp3=temp3->next;
        if(temp3!=NULL)
        {
            printf("+");
        }
        else
        {
            printf("\n");
        }  
    }
}
void add(struct node *i,struct node *k)
{
    i->next=k;
}
void multiply(struct node *i,struct node *k)
{
    printf("product of two polynomials is:\n");
        while(i!=NULL)
        {
            j=k;
            while(j!=NULL)
            {
                new3=(struct node*)malloc(sizeof(struct node));
                new3->coef=i->coef*j->coef;
                new3->expo=i->expo+j->expo;
                new3->next=NULL;
                if(head3==NULL)
                {
                    head3=new3;
                    tail3=new3;
                }
                else
                {
        
                    tail3->next=new3;
                    tail3=new3;
                }
                j=j->next;
            }
            i=i->next;
        }
        tail3->next=NULL;
        sort(head3);
        display(head3);
}