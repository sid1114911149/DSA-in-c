#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[100],n,m;
    printf("enter the size of the array:");
    scanf("%d",&n);
    printf("enter elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("entered elements before sorting:");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        m=arr[i];
        for(int j=i-1;j>=0;j--)
        {
            if(m<arr[j])
            {
                arr[j+1]=arr[j];
                arr[j]=m;
            }
            for(int k=0;k<6;k++)
            {
                printf("%d\t",arr[k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("\n");
    printf("entered elements after sorting:");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}