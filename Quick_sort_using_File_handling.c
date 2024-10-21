#include<stdio.h>
#include<math.h>
#define M 2000
void wquick(int arr[],int l,int h);
int wsort(int arr[],int l,int h);
int bsort(int arr[],int l,int h);
void bquick(int arr[],int l,int h);
int rsort(int arr[],int l,int h);
void rquick(int arr[],int l,int h);
void swap(int *a,int *b);
void revsort(int arr[],int l,int h);
static int bcount=0,wcount=0,rcount=0;
int main(){
	FILE *f,*fw,*fb,*fr;
	f=fopen("temp.txt","w");
	int arr[M];
	for(int i=0;i<M;i++){
		arr[i]=(rand()%M);
		if(i%30==0){
			fprintf(f,"\n");
		}
		fprintf(f,"%d,",arr[i]);
	}
	fclose(f);
	bquick(arr,0,M-1);
	bcount=0;
	fb=fopen("tempb.txt","w");
	fprintf(fb,"\n BEST CASE ASCENDING ORDER\n");
	bquick(arr,0,M-1);
	for(int i=0;i<M;i++){
		if(i%30==0){
			fprintf(fb,"\n");
		}	
		fprintf(fb,"%d,",arr[i]);
	}
	fclose(fb);
	revsort(arr,0,M-1);
	fw=fopen("tempw.txt","w");
	fprintf(fw,"\n WORST CASE ASCENDING ORDER\n");
	wquick(arr,0,M-1);
	for(int i=0;i<M;i++){
		if(i%30==0){
			fprintf(fw,"\n");
		}	
		fprintf(fw,"%d,",arr[i]);
	}
	fclose(fw);
	fr=fopen("tempr.txt","w");
	fprintf(fr,"\n CASE OF CHOOSING RANDOM PIVOT ASCENDING ORDER\n");
	rquick(arr,0,M-1);
	for(int i=0;i<M;i++){
		if(i%30==0){
			fprintf(fr,"\n");
		}	
		fprintf(fr,"%d,",arr[i]);
	}
	fclose(fr);
	printf("NO OF COMPARISIONS IN BEST CASE IS:%d\n",bcount);
	printf("NO OF COMPARISIONS IN WORST CASE IS:%d\n",wcount);
	printf("NO OF COMPARISIONS IN RANDOM CASE IS:%d\n",rcount);
return 0;
}
void swap(int *a,int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
int bsort(int arr[],int l,int h){
	int i=l,j=h;
	int mid=l+(h-l)/2;
	int pivot=arr[mid];
	while(i<j){
		
		while(i<=h-1 && arr[i]<=pivot){
			i++;
			bcount++;
		}
		while(j>=l+1 && arr[j]>=pivot){
			j--;
			bcount++;
		}
		if(i<j){
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[mid],&arr[j]);
	return j;
}
int wsort(int arr[],int l,int h){
	int i=l,j=h;
	int pivot=arr[l];
	while(i<j){
		while(i<=h-1 && arr[i]<=pivot){
			wcount++;
			i++;
		}
		while(j>=l+1 && arr[j]>=pivot){
			wcount++;
			j--;
		}
		if(i<j){
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[l],&arr[j]);
	return j;
}
void bquick(int arr[],int l,int h){
	if(l<h){
		int j=bsort(arr,l,h);
		bquick(arr,l,j-1);
		bquick(arr,j+1,h);
	}
}
void wquick(int arr[],int l,int h){
	if(l<h){
		int j=wsort(arr,l,h);
		wquick(arr,l,j-1);
		wquick(arr,j+1,h);
	}
}
int rsort(int arr[],int l,int h){
	int i=l,j=h;
	int mid=(rand()%(M-1));
	int pivot=arr[mid];
	while(i<j){
		
		while(i<=h-1 && arr[i]<=pivot){
			i++;
			rcount++;
		}
		while(j>=l+1 && arr[j]>=pivot){
			j--;
			rcount++;
		}
		if(i<j){
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[mid],&arr[j]);
	return j;
}
void rquick(int arr[],int l,int h){
	if(l<h){
		int j=rsort(arr,l,h);
		rquick(arr,l,j-1);
		rquick(arr,j+1,h);
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
