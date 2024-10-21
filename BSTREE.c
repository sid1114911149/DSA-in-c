#include<stdio.h>
#include<stdlib.h>
#define M 1000
static int arr[M],size=-1;
void create(){
	printf("BST CREATED SUCCESSFULLY\n");
	return ;
}
void insert(int index,int d){
	if(index>size || size==-1){
		size=index;
		arr[index]=d;
		return ;
	}else if(arr[index]>d){
		index=2*index+1;
		insert(index,d);
	}else if(arr[index]<d){
		index=2*index+2;
		insert(index,d);
	}			
}
void search(int index,int d){
	if(index>size || size==-1){
		printf("element not found\n");
		return ;
	}
	if(arr[index]>d){
		search(2*index+1,d);
	}
	else if(arr[index]<d){
		search(2*index+2,d);
	}else{
		printf("element found\n");
	}				
	return ;
}
int main(){
	int ch=1;
	while(ch){
		printf("enter element:");
		scanf("%d",&ch);
		insert(0,ch);
		printf("enter 1 for insertion else 0:");
		scanf("%d",&ch);
	}
	printf("enter number to be searched:");
	scanf("%d",&ch);
	search(0,ch);	
	return 0;
}					
		
