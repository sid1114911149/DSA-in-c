#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define M 2000
struct node {
    int data;
    struct node *next;
}*arr[10],*temp,*temp2;
static int countb=0,counta=0,countw=0;
struct node *newnode(int d){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->data=d;
    return temp;
}
struct node *create(struct node *temp,int d)
{
    if(temp==NULL){
        temp=newnode(d);
    }else{
        temp->next=create(temp->next,d);
    }
    return temp;
}
void push(int i,int d){
    if(arr[i]==NULL){
        arr[i]=create(arr[i],d);
    }else{
        create(arr[i],d);
    }
}
int pop(int i)
{
    int a=arr[i]->data;
    arr[i]=arr[i]->next;
    return a;
}
void radixsort(int arr1[],int *ptr,int n){
    int l,count=0,k,allcount=0;
    l=arr1[0];
    for(int i=1;i<n;i++)
    {
        if(l<arr1[i])
        {
            l=arr1[i];
        }
    }
    while(l>0)
    {
        l=l/10;
        count++;
    }
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<n;j++)
        {
            k=arr1[j];
            for(int a=0;a<i;a++)
            {
                k=k/10;
            }
            k=k%10; 
                switch(k)
                {
                    case 0: 
                            push(0,arr1[j]);
                            break;
                    case 1: 
                            push(1,arr1[j]);
                            break;
                    case 2: 
                            push(2,arr1[j]);
                            break;
                    case 3: 
                            push(3,arr1[j]);
                            break;
                    case 4: 
                            push(4,arr1[j]);
                            break;
                    case 5: 
                            push(5,arr1[j]);
                            break;
                    case 6: 
                            push(6,arr1[j]);
                            break;
                    case 7: 
                            push(7,arr1[j]);
                            break;
                    case 8: 
                            push(8,arr1[j]);
                            break;
                    case 9: 
                            push(9,arr1[j]);
                            break;                                                                        
                }
            allcount++;    
        }
        for(int m=0;m<n;m++)
        {
            if(arr[0]!=NULL)
                arr1[m]=pop(0);
            else if(arr[1]!=NULL)
                arr1[m]=pop(1);    
            else if(arr[2]!=NULL)
                arr1[m]=pop(2);
            else if(arr[3]!=NULL)
                arr1[m]=pop(3);
            else if(arr[4]!=NULL)
                arr1[m]=pop(4);
            else if(arr[5]!=NULL)
                arr1[m]=pop(5);
            else if(arr[6]!=NULL)
                arr1[m]=pop(6);
            else if(arr[7]!=NULL)
                arr1[m]=pop(7);
            else if(arr[8]!=NULL)
                arr1[m]=pop(8); 
            else if(arr[9]!=NULL)
                arr1[m]=pop(9);    
            allcount++;                                    
        }
    }  
    *ptr=allcount;
}
void total_function(int n){
    int arr1[n];
    char ch[60]="\n\t\tAFTER SORTING THE ARRAY USING COUNT SORT\n";
    char ch2[60]="\n\t\tBEFORE SORTING THE ARRAY \n";
    FILE *f1,*f2;
    f1=fopen("temp.txt","a");
    fprintf(f1,"%s",ch2);
    for(int i=0;i<n;i++){
        fprintf(f1,"%d,",rand()%1000);
    }
    fclose(f1);
    f1=fopen("temp.txt","r");
    for(int i=0;i<n;i++){
        fscanf(f1,"%d,",&arr1[i]);
    }
    fclose(f1);
    radixsort(arr1,&counta,n);
    printf("total no of steps when input size is %d in average case is:%d\n",n,counta);
    f1=fopen("temp.txt","a");
    fprintf(f1,"%s",ch);
    for(int i=0;i<n;i++){
        fprintf(f1,"%d,",arr1[i]);
    }
    radixsort(arr1,&countb,n);
    printf("total no of steps when input size is %d in best case is:%d\n",n,countb);
    fprintf(f1,"%s",ch);
    for(int i=0;i<n;i++){
        fprintf(f1,"%d,",arr1[i]);
    }
    radixsort(arr1,&countw,n);
    printf("total no of steps when input size is %d in worst case is:%d\n",n,countw);
    fprintf(f1,"%s",ch);
    for(int i=0;i<n;i++){
        fprintf(f1,"%d,",arr1[i]);
    }
    fclose(f1);
    printf("time complexity of the radix sort algorithm is:O(%dn)\n",countw/n);
    printf("array is sorted successfully...\n");
}
int main(){
    for(int i=0;i<3;i++){
        counta=0;
        countb=0;
        countw=0;
        total_function(1000+rand()%500);
    }
    return 0;
}