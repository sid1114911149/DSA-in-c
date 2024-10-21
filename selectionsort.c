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
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				m=arr[i];
				arr[i]=arr[j];
				arr[j]=m;
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
		
	 		
