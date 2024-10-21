#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
    int height;
}*root,*temp,*temp2;
int getheight(struct node *temp){
    if(temp==NULL){
        return 0;
    }
    return temp->height;
}
struct node * createnode(int d){
    struct node * temp=(struct node *)malloc(sizeof(struct node));
    temp->right=temp->left=NULL;
    temp->height=1;
    temp->data=d;
    return temp;
}
int getbalancefactor(struct node * temp){
    if(temp==NULL){
        return 0;
    }
    return getheight(temp->left)-getheight(temp->right);
}
int max(int a,int b){
    return a>b?a:b;
}
struct node *rightrotate(struct node *temp){
    struct node *temp2=temp->left;
    temp->left=temp2->right;
    temp2->right=temp;
    temp->height=max(getheight(temp->right),getheight(temp->left))+1;
    temp2->height=max(getheight(temp2->right),getheight(temp2->left))+1;
    return temp2;
}
struct node *leftrotate(struct node *temp){
    struct node *temp2=temp->right;
    temp->right=temp2->left;
    temp2->left=temp;
    temp->height=max(getheight(temp->right),getheight(temp->left))+1;
    temp2->height=max(getheight(temp2->right),getheight(temp2->left))+1;
    return temp2;
}
struct node *insert(struct node *temp,int d){
    if(temp==NULL){
        temp=createnode(d);
    }else if(temp->data>d){
        temp->left=insert(temp->left,d);
    }else if(temp->data<d){
        temp->right=insert(temp->right,d);
    }
    //return temp;
    temp->height=1+(max(getheight(temp->left),getheight(temp->right)));
    int bf=getbalancefactor(temp);
    //left left
    if(bf>1 && d<temp->left->data){
        return rightrotate(temp);
    }
    //right right
     if(bf<-1 && d>temp->right->data){
        return leftrotate(temp);
    }
    //right left
    if(bf>1 && d>temp->left->data){
        temp->left=leftrotate(temp->left);
        return rightrotate(temp);
    }
    //left right
    if(bf<-1 && d<temp->right->data){
        temp->right=rightrotate(temp->right);
        return leftrotate(temp);
    }
    return temp;
}
void preorder(struct node *temp){
    if(temp==NULL){
        return ;
    }
    printf("%d\t",temp->data);
    preorder(temp->left);
    preorder(temp->right);
}
void inorder(struct node *temp){
    if(temp==NULL){
        return ;
    }
    inorder(temp->left);
    printf("%d\t",temp->data);
    inorder(temp->right);
}
void postorder(struct node *temp){
    if(temp==NULL){
        return ;
    }
    postorder(temp->left);
    postorder(temp->right);
    printf("%d\t",temp->data);
    
}
int main(){
    struct node *root=NULL;
    int ch=1,n;
    while(ch){
    	printf("enter value:");
    	scanf("%d",&n);
    	root=insert(root,n);
    	printf("enter 1 to re-enter:");
    	scanf("%d",&ch);
    }
    printf("PREORDER:");
    preorder(root);
    printf("\n");
    printf("INORDER:");
    inorder(root);
    printf("\n");
    printf("POSTORDER:");
    postorder(root);
    printf("\n");
    return 0;
}
