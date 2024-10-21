#include<stdio.h>
#include<stdlib.h>
struct node{
    int data,height;
    struct node *left,*right;
}*root,*temp,*temp2;
int getheight(struct node *temp){
    if(temp==NULL){
        return 0;
    }
    return temp->height;
}
int max(int a,int b){
    return a>b?a:b;
}
int get_balance_factor(struct node *temp){
    if(temp==NULL){
        return 0;
    }
    return getheight(temp->left)-getheight(temp->right);
}
struct node *leftrotate(struct node *temp){
    struct node *temp2=temp->right;
    temp->right=temp2->left;
    temp2->left=temp;
    temp->height=max(getheight(temp->right),getheight(temp->left));
    temp2->height=max(getheight(temp2->right),getheight(temp2->left));
    return temp2;
}
struct node *rightrotate(struct node *temp){
    struct node *temp2=temp->left;
    temp->left=temp2->right;
    temp2->right=temp;
    temp->height=max(getheight(temp->right),getheight(temp->left));
    temp2->height=max(getheight(temp2->left),getheight(temp->right));
    return temp2;
}
struct node *create_node(int d){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->right=temp->left=NULL;
    temp->height=1;
    temp->data=d;
    return temp;
}
struct node *insert(struct node *temp,int d){
    if(temp==NULL){
        temp=create_node(d);
    }else if(temp->data>d){
        temp->left=insert(temp->left,d);
    }else if(temp->data<d){
        temp->right=insert(temp->right,d);
    }
    temp->height=1+max(getheight(temp->left),getheight(temp->right));
    int bf=get_balance_factor(temp);
    if(bf>1 && d<temp->left->data){
        return rightrotate(temp);
    }
    if(bf<-1 && d>temp->right->data){
        return leftrotate(temp);
    }
    if(bf>1 && d>temp->left->data){
        temp=leftrotate(temp);
        return rightrotate(temp);
    }
    if(bf<-1 && d<temp->right->data){
        temp=rightrotate(temp);
        return leftrotate(temp);
    }
    return temp;
}
struct node *getsucc(struct node *temp){
    temp=temp->right;
    while(temp!=NULL && temp->left!=NULL){
        temp-temp->left;
    }
    return temp;
}
struct node *delete(struct node *temp,int d){
    if(temp==NULL){
        return temp;
    }
    else if(d<temp->data){
        temp->left=delete(temp->left,d);
    }
    else if(d>temp->data){
        temp->right=delete(temp->right,d);
    }
    else{
       if((temp->left==NULL) || temp->right==NULL){
            struct node *temp2=temp->left?temp->left:temp->right;
            if(temp2==NULL){
                temp2=temp;
                temp=NULL;
            }
            else{
                *temp=*temp2;
            }
            free(temp);
       }
       else{
            struct node *succ=getsucc(temp);
            temp->data=succ->data;
            temp->right=delete(temp->right,succ->data);
       }
    }
    if(temp==NULL){
        return temp;
    }
    temp->height=1+max(getheight(temp->left),getheight(temp->right));
    int bf=get_balance_factor(temp);
    //left-left case
    if (bf > 1 && get_balance_factor(temp->left) >= 0)
        return rightrotate(temp);

    // Left Right Case
    if (bf > 1 && get_balance_factor(temp->left) < 0)
    {
        temp->left =  leftrotate(temp->left);
        return rightrotate(temp);
    }
    // Right Right Case
    if (bf < -1 && get_balance_factor(temp->right) <= 0)
        return leftrotate(temp);

    // Right Left Case
    if (bf < -1 && get_balance_factor(temp->right) > 0)
    {
        temp->right = rightrotate(temp->right);
        return leftrotate(temp);
    }
    return temp;
}
void inorder(struct node *temp){
    if(temp==NULL){
        return ;
    }
    inorder(temp->left);
    printf("%d ",temp->data);
    inorder(temp->right);
}
void preorder(struct node *temp){
    if(temp==NULL){
        return ;
    }
    printf("%d ",temp->data);
    preorder(temp->left);
    preorder(temp->right);
}
void postorder(struct node *temp){
    if(temp==NULL){
        return ;
    }
    postorder(temp->left);
    postorder(temp->right);
    printf("%d ",temp->data);
}
int main(){
    int ch=1,n;
    root=insert(root,9);
    root=insert(root,5);
    root=insert(root,2);
    root=insert(root,10);
    root=insert(root,7);
    root=insert(root,13);
    root=insert(root,17);
    root=insert(root,16);
    printf("PREORDER:");
                preorder(root);
                printf("\n");
    root=delete(root,7);
    root=delete(root,10);
    printf("PREORDER:");
                preorder(root);
                printf("\n");
   /* do{
        printf("ENTER\n1 FOR INSERTION\n2 FOR DELETION\n3 FOR DISPLAY\n4 FOR EXIT:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("enter number to be inserted:");
                    scanf("%d",&n);
                    root=insert(root,n);
                    break;
            case 2:printf("enter number to be deleted:");
                    scanf("%d",&n);
                    root=delete(root,n);
                    break;
            case 3:printf("PREORDER:");
                preorder(root);
                printf("\n");
                printf("INORDER:");
                inorder(root);
                printf("\n");
                printf("POSTORDER:");
                postorder(root);
                printf("\n");   
                break;
            case 4:printf("EXITING...\n");
                    break;
            default:printf("NO COMMAND FOUND\n");
                break;                
        }
    }while(ch!=4);*/
    return 0;
}
