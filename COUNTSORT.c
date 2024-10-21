#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define M 1000
static int countb=0,counta=0,countw=0;
void count(int arr[],int *ptr,int n){
    int allcount=0,max=arr[0],arr2[n];
    for(int i=1;i<M;i++){
        if(max<arr[i])
            max=arr[i];
    }
    max+=1;
    int arr1[max];
    for(int i=0;i<max;i++){
        arr1[i]=0;
    }
    for(int i=0;i<n;i++){
        arr1[arr[i]]+=1;
        allcount++;
    }
    for(int i=1;i<max;i++){
        arr1[i]+=arr1[i-1];
        allcount++;
    }
    for(int i=0;i<n;i++){
        arr2[arr1[arr[i]]]=arr[i];
        arr1[arr[i]]-=1;
        allcount++;
    }
    for(int i=0;i<n;i++){
        arr[i]=arr2[i];
        printf("%d ",arr2[i]);
    }
    *ptr=allcount;
}
void count2(int arr[],int n){
    int max=arr[0],a;
    for(int i=1;i<n;i++){
        if(max<arr[i])
            max=arr[i];
    }
    int *arr2=(int *)malloc(sizeof(int)*(max+1));
    for(int i=0;i<=max;i++){
        *(arr2+i)=0;
    }
    for(int i=0;i<n;i++){
        *(arr2+arr[i])+=1;
    }
    int j=max,k=0;
    while(j>=0){
        if(*(arr2+j)!=0){
            a=*(arr2+j);
            while(a>0){
                arr[k]=j;
                k++;
                a--;
            }
        }    
        j--;
    } 
    free(arr2);
}
void total_function(int n){
    char ch[60]="\n\t\tAFTER SORTING THE ARRAY USING COUNT SORT\n";
    char ch2[60]="\t\tBEFORE SORTING THE ARRAY \n";
    FILE *f1;
    int *arr=(int *)malloc(sizeof(int)*n);
    f1=fopen("temp.txt","w");
    fprintf(f1,"%s",ch2);
    for(int i=0;i<n;i++){
            fprintf(f1,"%d,",rand()%1000);
    }
    fclose(f1);
    f1=fopen("temp.txt","r");
    for(int i=0;i<n;i++){
        fscanf(f1,"%d,",arr[i]);
    }
    fclose(f1);
    count(arr,&counta,n);
    f1=fopen("temp.txt","a");
    fprintf(f1,"%s",ch);
    for(int i=0;i<n;i++){
        fprintf(f1,"%d,",arr[i]);
    }
    fclose(f1);
    printf("total no of steps when input size is %d in average case is:%d\n",n,counta);
    count(arr,&countb,n);
    printf("total no of steps when input size is %d in best case is:%d\n",n,countb);
    count2(arr,n);
    count(arr,&countw,n);
    printf("total no of steps when input size is %d in worst case is:%d\n",n,countw);
    printf("time complexity of the count sort algorithm is:O(%dn)\n",countw/n);
    printf("array is sorted successfully...\n");
    free(arr);
}

int main(){
    for(int i=0;i<3;i++){
            counta=0;
            countb=0;
            countw=0;
            total_function(M+rand()%500);
    }
    return 0;
}