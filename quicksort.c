#include<stdio.h>
#include<stdlib.h>
int partition(int arr[],int l,int h);
void quicksort(int arr[],int l,int h);
void swap(int *a,int *b);
int main()
{
    int n=29,arr[100]={3,14,16,20,8,31,22,12,33,1,4,9,10,5,13,7,24,2,41,26,18,334,36,25,15,27,32,35,39};
    printf("enter no of elements:");
    scanf("%d",&n);
    printf("enter elements :");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("entered elements before sorting:");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    quicksort(arr,0,n-1);
    printf("entered elements after sorting:");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    return 0;
}
void swap(int *a,int *b)
{
    int s;
    s=*a;
    *a=*b;
    *b=s;
}
int partition(int arr[],int l,int h)
{
    int j=h,i=l,pivot=arr[l];
    while(i<j)
    {
        while(arr[j]>=pivot && j>=l+1)
            j--;
        while(arr[i]<=pivot && i<=h-1)
            i++;
        if(i<j)
            swap(&arr[i],&arr[j]);
    }
    swap(&arr[l],&arr[j]);
    for(int i=0;i<6;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    return j;
}
void quicksort(int arr[],int l,int h)
{
    int j;
    if(l<=h)
    {
        j=partition(arr,l,h);
        quicksort(arr,l,j-1);
        quicksort(arr,j+1,h);
    }
}
