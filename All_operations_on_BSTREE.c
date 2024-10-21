#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
}*root,*temp,*temp2;
struct node *insert(int d){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->right=temp->left=NULL;
    temp->data=d;
    return temp;
}
struct node *create(struct node *temp,int d){
    if(temp==NULL){
        temp=insert(d);
    }
    else if(temp->data>d){
        temp->left=create(temp->left,d);
    }
    else if(temp->data<d){
        temp->right=create(temp->right,d);
    }
    return temp;
}
struct node *create1(int d){
	if(root==NULL){
		root=create(root,d);
	}
	else{
		create(root,d);
	}		
}
struct node *searching(struct node *temp,int d){
    if(temp==NULL){
        printf("DATA NOT FOUND\n");
        return NULL;
    }
    else if(temp->data>d){
        searching(temp->left,d);
    }
    else if(temp->data<d){
        searching(temp->right,d);
    }
    else if(temp->data==d){
        printf("%d FOUND IN THE LIST\n",d);
    }
}
void preorder(struct node *temp){
    if(temp!=NULL){
        printf("%d\t",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}
void inorder(struct node *temp){
    if(temp!=NULL){
        inorder(temp->left);
       	printf("%d\t",temp->data);
        inorder(temp->right);
    }
}
void postorder(struct node *temp){
    if(temp!=NULL){
        postorder(temp->left);
        postorder(temp->right);
        printf("%d\t",temp->data);
    }
}
int maxdepth(struct node *temp){
    if(temp==NULL){
        return 0;
    }
    int ldepth=maxdepth(temp->left);
    int rdepth=maxdepth(temp->right);
    if(ldepth>rdepth)
        return ldepth+1;
    else
        return rdepth+1;    
}
struct node* getSuccessor(struct node* curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

// This function deletes a given data x from
// the give BST and returns modified root of
// the BST (if it is modified)
struct node * delNode(struct node *temp, int x)
{

    // Base case
    if (temp == NULL)
        return temp;

    // If data to be searched is in a subtree
    if (temp->data > x)
        temp->left = delNode(temp->left, x);
    else if (temp->data < x)
        temp->right = delNode(temp->right, x);

    // If root matches with the given data
    else {

        // Cases when root has 0 children
        // or only right child
        if (temp->left == NULL) {
            struct node *temp2 = temp->right;
            free(temp);
            return temp2;
        }

        // When root has only left child
        if (temp->right == NULL) {
            struct node *temp2 = temp->left;
            free(temp);
            return temp2;
        }

        // When both children are present
        struct node *succ = getSuccessor(temp);
        temp->data = succ->data;
        temp->right = delNode(temp->right, succ->data);
    }
    return temp;
}
void findmin(struct node *temp){
	if(temp->left==NULL){
		printf("minimum element in the given BST is:%d\n",temp->data);
		return ;
	}
	temp=temp->left;
	findmin(temp);
}
void findmax(struct node *temp){
	if(temp->right==NULL){
		printf("maximum element in the given BST is:%d\n",temp->data);
		return ;
	}
	temp=temp->right;
	findmax(temp);
}		
void currentlevel(struct node *temp,int l){
    if(temp==NULL){
        return ;
    }
    if(l==1){
        printf("%d ",temp->data);
    }
    else{
        currentlevel(temp->left,l-1);
        currentlevel(temp->right,l-1);
    }
}
void bfs(struct node *temp){
    int h=maxdepth(root);
    for(int i=1;i<=h;i++){
        currentlevel(temp,i);
    }
}
int main(){
    int ch=1,d;
    create1(5);
    create1(3);
    create1(12);
    create1(8);
    create1(15);
    create1(1);
    create1(4);
    create1(19);
    create1(13);
    do{
    printf("ENTER \n1 FOR DISPLAY\n2 FOR INSERTION\n3 FOR DELETION\n4 FOR SEARCHING\n5 FOR FINDING HEIGHT\n6 FOR FIND MAXIMUM\n7 FOR FIND MINIMUM\n8 FOR EXITING:");
    scanf("%d",&ch);
    switch(ch){
        case 1:printf("PREORDER:");
                preorder(root);
               printf("\n");
               printf("INORDER:");
               inorder(root);
               printf("\n");
               printf("POSTORDER:");
               postorder(root);
               printf("\n");
               break;
        case 2://insertion();
        	printf("enter value to be inserted:");
    		scanf("%d",&d);
    		create1(d);
               break;
        case 3: printf("enter number to be deleted:");
                scanf("%d",&d);
                delNode(root,d);
                break;
        case 4: printf("enter number to be searched:");
                scanf("%d",&d);
                searching(root,d);
                break;
        case 5: printf("HEIGHT OF THE TREE IS:%d\n",maxdepth(root));
                break;
        case 6:findmax(root);
        	break;
        case 7:findmin(root);
        	break;	
        case 8:printf("exiting...\n");
               break;       
        default:printf("NO COMMAND FOUND\n");
               break;        
    }
    }while(ch!=8);
    printf("BFS OF  BINARY SEARCH TREE:");
    bfs(root);
    return 0;
}
