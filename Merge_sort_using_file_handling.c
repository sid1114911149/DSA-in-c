#include<stdio.h>
#include<math.h>
#define M 2000
void bsort(int arr[],int l,int h,int m);
void bquick(int arr[],int l,int h);
void wsort(int arr[],int l,int h,int m);
void wquick(int arr[],int l,int h);
void revsort(int arr[],int l,int h);
static int bcount=0,wcount=0;
int main(){
	FILE *f,*fw,*fb;
	f=fopen("temp.txt","w");
	int arr[M];
	for(int i=0;i<M;i++){
		arr[i]=rand()%M;
		if(i%30==0){
			fprintf(f,"\n");
		}
		fprintf(f,"%d,",arr[i]);
	}
	fclose(f);
	bquick(arr,0,M-1);
	bcount=0;
	bquick(arr,0,M-1);
	fb=fopen("tempb.txt","w");
	fprintf(fb,"\n BEST CASE ASCENDING ORDER\n");
	for(int i=0;i<M;i++){
		if(i%30==0){
			fprintf(fb,"\n");
		}	
		fprintf(fb,"%d,",arr[i]);
	}
	fclose(fb);
	revsort(arr,0,M-1);
	wquick(arr,0,M-1);
	fw=fopen("tempw.txt","w");
	fprintf(fw,"\n WORST CASE ASCENDING ORDER\n");
	for(int i=0;i<M;i++){
		if(i%30==0){
			fprintf(fw,"\n");
		}	
		fprintf(fw,"%d,",arr[i]);
	}
	fclose(fw);
	printf("NO OF COMPARISIONS IN BEST CASE IS:%d\n",bcount);
	printf("NO OF COMPARISIONS IN WORST CASE IS:%d\n",wcount);
return 0;
}
void bsort(int arr[],int l,int h,int m){
	int left_length=m-l+1;
    int right_length=h-m;
    int temp_left[left_length];
    int temp_right[right_length];
    for(int i=0;i<left_length;i++)
    {
        temp_left[i]=arr[l+i];
    }
    for(int i=0;i<right_length;i++)
    {
        temp_right[i]=arr[m+1+i];
    }
    for(int i=0,j=0,k=l;k<=h;k++)
    {
		bcount++;
        if(((i<left_length)&&temp_left[i]<=temp_right[j])||(j>=right_length))
        {
            arr[k]=temp_left[i];
            i++;
        }
        else
        {
            arr[k]=temp_right[j];
            j++;
        }  
    }
}
void bquick(int arr[],int l,int h){
	if(l<h){
		int m=l+(h-l)/2;
		bquick(arr,l,m);
		bquick(arr,m+1,h);
		bsort(arr,l,h,m);
	}
}
void wsort(int arr[],int l,int h,int m){
	int left_length=m-l+1;
    int right_length=h-m;
    int temp_left[left_length];
    int temp_right[right_length];
    for(int i=0;i<left_length;i++)
    {
        temp_left[i]=arr[l+i];
    }
    for(int i=0;i<right_length;i++)
    {
        temp_right[i]=arr[m+1+i];
    }
    for(int i=0,j=0,k=l;k<=h;k++)
    {
		wcount++;
        if(((i<left_length)&&temp_left[i]<=temp_right[j])||(j>=right_length))
        {
            arr[k]=temp_left[i];
            i++;
        }
        else
        {
            arr[k]=temp_right[j];
            j++;
        }  
    }
}
void wquick(int arr[],int l,int h){
	if(l<h){
		int m=l+(h-l)/2;
		wquick(arr,l,m);
		wquick(arr,m+1,h);
		wsort(arr,l,h,m);
	}
}
void revsort(int arr[],int l,int h){
	for(int i=l;i<h;i++){
		for(int j=l;j<h;j++){
			if(arr[j]<arr[j+1]){
				int t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}	
	}
}				
