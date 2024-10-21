#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void sort(int arr[],int n);
void rsort(int arr[],int n);
int main(){
    FILE *f,*t1,*t2;
    int n;
    printf("enter n:");
    scanf("%d",&n);
    int arr[n],k;
    f=fopen("temp.txt","w");
    t1=fopen("temp1.txt","w");
    t2=fopen("temp2.txt","w");
    for(int i=0;i<n;i++){
        if(i%30==0){
            fprintf(f,"\n",n);
        }
        arr[i]=rand()%(n);
        fprintf(f,"%d,",arr[i]);
    }
    sort(arr,n);
    for(int i=0;i<n;i++){
        if(i%30==0){
            fprintf(t1,"\n",n);
        }
        fprintf(t1,"%d,",arr[i]);
    }
    printf("\n");
    rsort(arr,n);
    for(int i=0;i<n;i++){
        if(i%30==0){
            fprintf(t2,"\n",n);
        }
        fprintf(t2,"%d,",arr[i]);
    }
    fclose(t2);
    fclose(t1);
    fclose(f);
    return 0;
}
void sort(int arr[],int n){
    int key,j,count=0;
    for(int i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>=key){
            arr[j+1]=arr[j];
            j--;
            count++;
        }
        arr[j+1]=key;
    }
    printf("NO OF COMPARISIONS IN BEST CASE IS %d\n",count);
}
void rsort(int arr[],int n){
    int key,j,count=0;
    for(int i=n-2;i>=0;i--){
        key=arr[i];
        j=i+1;
        while(j<n && arr[j]>=key){
            arr[j-1]=arr[j];
            j++;
            count++;
        }
        arr[j-1]=key;
    }
     printf("NO OF COMPARISIONS IN WORST CASE IS %d\n",count);
}