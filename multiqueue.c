#include<stdio.h>
#include<stdlib.h>
static int arr1[100],arr2[100],arr3[100],arr4[100];
static int f1=-1,r1=-1,f2=-1,r2=-1,f3=-1,r3=-1,f4=-1,r4=-1;
void enqueue(int *front,int *rear,int *arr,int n);
void dequeue(int *front,int *rear,int *arr);
void display(int *front,int *rear,int *arr);
int main()
{
    int n,list[100];;
    printf("enter no of elements in the list:");
    scanf("%d",&n);
    printf("enter elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&list[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(list[i]<10)
            enqueue(&f1,&r1,arr1,list[i]);
        else if(list[i]>=10 && list[i]<=19)
            enqueue(&f2,&r2,arr2,list[i]);
        else if(list[i]>=20 && list[i]<=29)
            enqueue(&f3,&r3,arr3,list[i]);
        else if(list[i]>=30)
            enqueue(&f4,&r4,arr4,list[i]);            
    }
    printf("entered elements below 10:");
    display(&f1,&r1,arr1);
    printf("entered elements below 20 and above 10:");
    display(&f2,&r2,arr2);
    printf("entered elements below 30 and above 20:");
    display(&f3,&r3,arr3);
    printf("entered elements above 30:");
    display(&f4,&r4,arr4);
    return 0;
}
void enqueue(int *front,int *rear,int *arr,int n)
{
    if(*rear<100)
    {
        if(*front==-1)
        {
            *front+=1;
            *rear+=1;
            arr[*front]=n;
        }
        else
        {
            *rear+=1;
            arr[*rear]=n;
        }
    }
    else
    {
        printf("NO SUFFICIENT SPACE\n");
    }    
}
void display(int *front,int *rear,int *arr)
{
    if(*rear<=100 && *front!=-1)
    {
        for(int i=*front;i<=*rear;i++)
        {
            printf("%d\t",*(arr+i));
        }
    }
    else
        printf("UNDERFLOW\n");    
    printf("\n");
}
void dequeue(int *front,int *rear,int *arr)
{
    if(*front>*rear)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        printf("popped element is %d\n",*(arr+*front));
        *front+=1;  
    }    
}