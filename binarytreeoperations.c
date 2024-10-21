#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next,*prev;
}*root,*new,*temp;
struct node* newnode(int value)
{
    new=(struct node*)malloc(sizeof(struct node));
    new->next=new->prev=NULL;
    new->data=value;
    return new;
}
struct node * insertnode(struct node *n,int value)
{
    if(n==NULL)
    {
        n=newnode(value);
    }
    else if(value>n->data)
    {
        n->next=insertnode(n->next,value);
    }
    else if(value<n->data)
    {
        n->prev=insertnode(n->prev,value);
    }
    else
        return n;
}
struct node* binarysearch(struct node *s,int value)
{
    if(s!=NULL)
    {
        if(s->data==value)
        {
            return s;
        }
        else if(s->data>value)
        {
            return binarysearch(s->prev,value);
        }
        else if(s->data<value)
        {
            return binarysearch(s->next,value);
        }
    }    
    else
        return NULL;
}
struct node * findmin(struct node* min)
{
	if (min == NULL) 
	{
		return NULL;
	}
	else if (min->prev != NULL) 
	{
		return findmin(min->prev);
	}
	return root;
}
struct node* delete (struct node* del,int x)
{
	if (del == NULL)
		return NULL;
	if (x > del->data) 
	{
		del->next = delete (del->next, x);
	}
	else if (x < del->data) 
	{
		del->prev = delete (del->prev, x);
	}
	else 
	{
		if (del->prev == NULL && del->next == NULL) 
		{
			free(del);
			return NULL;
		}
		else if (del->prev== NULL|| del->next == NULL) 
		{
			if (del->prev == NULL) 
			{
				temp = del->next;
			}
			else 
			{
				temp = del->prev;
			}
			free(del);
			return temp;
		}
		else 
		{
			temp= findmin(del->next);
			del->data = temp->data;
		    del->next = delete (del->next, temp->data);
		}
	}
	return del;
}
void inorder(struct node *i)
{
    if(i!=NULL)
    {
        inorder(i->prev);
        printf("%d\t",i->data);
        inorder(i->next);
    }
}
void postorder(struct node *p)
{
    if(p!=NULL)
    {
        postorder(p->prev);
        postorder(p->next);
        printf("%d\t",p->data);
    }
}
void preorder(struct node *p)
{
    if(p!=NULL)
    {
        printf("%d\t",p->data);
        preorder(p->prev);
        postorder(p->next);
    }    
}
int main()
{
    int ch=1,n,s,d;
    while(ch)
    {
        printf("enter the element:");
        scanf("%d",&n);
        if(root==NULL)
        {
            root=insertnode(root,n);
        }
        else
        {
            insertnode(root,n);
        }
        printf("enter 1 to enter next element:");
        scanf("%d",&ch);
    }
    printf("enter element to be searched:");
    scanf("%d",&s);
    printf("want to delete a element:");
    scanf("%d",&ch);
    if(ch!=0)
    {
        printf("enter element to be deleted:");
        scanf("%d",&d);
        delete(root,d);
    }
    if(binarysearch(root,s)==NULL)
    {
        printf("%d is not found in the tree\n",s);
    }
    else
    {
        printf("%d is found in the tree\n",s);
    }
    printf("pre-order traversal of the tree:\n");
    preorder(root);
    printf("\n");
    printf("in-order traversal of the tree:\n");
    inorder(root);
    printf("\n");
    printf("post-order traversal of the tree:\n");
    postorder(root);
    printf("\n");
    return 0;
}