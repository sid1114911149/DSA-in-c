#include<stdio.h>
int main()
{
    int arr[10][10],arr2[5][5],r,c,n,m;
    int k=0;
    printf("enter no of rows:");
    scanf("%d",&r);
    printf("enter no of columns:");
    scanf("%d",&c);
    printf("enter a sparse matrix:");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]!=0)
            {
                arr2[0][k]=i;
                arr2[1][k]=j;
                arr2[2][k]=arr[i][j];
                k++;
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<k;j++)
        {
            printf("%d\t",arr2[i][j]);
        }
        printf("\n");
    }
    return 0;
}