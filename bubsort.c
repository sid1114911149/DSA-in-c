#include<stdio.h>
int main()
{
	int arr[100],n,a,m,k;
	printf("enter no of elements in array:");
	scanf("%d",&n);
	printf("enter elements:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("during sorting\n");
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				m=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=m;
			}
		}	
		for(int j=0;j<n;j++)
		{
			printf("%d\t",arr[j]);
		}
		printf("\n");
	 }
	 printf("after sorting\n");
	 for(int j=0;j<n;j++)
	 {
		printf("%d\t",arr[j]);
	 }
		printf("\n");
	return 0;
}		
		
	 		
