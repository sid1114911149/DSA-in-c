#include<stdio.h>
#include<stdlib.h>
int arr[5],top,max=5;
void push(int data);
void pop();
int main()
{
    top=-1;
    int data;
    printf("enter elements:");
    for(int i=0;i<6;i++)
    {
        scanf("%d",&data);
        push(data);
    }
    printf("entered elements:\n");
    for(int i=0;i<6;i++)
    {
        pop();
    }
    return 0;
}
void push(int data)
{
    if(top==max-1)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        top+=1;
        arr[top]=data;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        printf("%d\t",arr[top]);
        top-=1;
    }
}