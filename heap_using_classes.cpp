#include<iostream>
#include <queue>
using namespace std;
class heapnode{
    public:
    int data;
    heapnode *right,*left,*parent;
    heapnode(int val){
        data=val;
        right=NULL;
        left=NULL;
        parent=NULL;
    }
};
heapnode *lastparent(heapnode *root){ 
    queue<heapnode *> q;
    q.push(root);
    heapnode *temp;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if(temp->left && temp->right){
            q.push(temp->left);
            q.push(temp->right);
        }
        else{
            break;
        }
    }
    return temp;
}
void swap(heapnode *a,heapnode *b){
    int t=a->data;
    a->data=b->data;
    b->data=t;
}
class Heap{
    heapnode *root;
    public:
    Heap(){
        root=NULL;
    }
    void upheapify(heapnode *temp){
        if(temp->parent==NULL){
            return ;
        }
        heapnode * temp2=temp->parent;
        while(temp2->data<temp->data ){
            swap(temp,temp2);
            temp=temp2;
            temp2=temp->parent;
            if(temp2==NULL){
                return ;
            }
        }
    }
    void add(int data){
        heapnode*newnode=new heapnode(data);
        cout<<"inserting "<<data<<"\n";
        if(root==NULL){
            root=newnode;
            return ;
        }
        heapnode *lpar=lastparent(root);
        if(lpar->left==NULL){
            lpar->left=newnode;
            newnode->parent=lpar;
        }
        else{
            lpar->right=newnode;
            newnode->parent=lpar;
        }
        upheapify(newnode);
    }
    void printinorder(heapnode *temp){
        if(temp==NULL){
            return ;
        }
        printinorder(temp->left);
        cout<<temp->data<<" ";
        printinorder(temp->right);
    }
    void print(){
        cout<<"printing data:";
        printinorder(root);
    }
};
int main(){
    Heap h;
    h.add(34);
    h.add(76);
    h.add(854);
    h.add(321);
    h.add(786);
    h.print();
    return 0;
}