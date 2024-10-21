 #include<stdio.h>
 #include<math.h>
 #define N 100
 void sort(int a[],int n);
 void sort_recur(int a[],int l,int r);
 void merge_sorted_array(int a[],int l,int m,int r);
 int main()
 {
    int n,a[100]={3,14,16,20,8,31,22,12,33,1,4,9,10,5,13,7,24,2,41,26,18,334,36,25,15,27,32,35,39};
    sort(a,24);
    for(int i=0;i<N;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    printf("%d\n",a[22]);
    return 0;
 }
 void sort(int a[],int n)
 {
    sort_recur(a,0,n-1);
 }
 void sort_recur(int a[], int l, int r)
 {
    if(l<r)
    {
        int m=l+(r-l)/2;
        sort_recur(a,l,m);
        sort_recur(a,m+1,r);
        merge_sorted_array(a,l,m,r);
    }     
 }
 void merge_sorted_array(int a[],int l,int m,int r)
 {
    int left_length=m-l+1;
    int right_length=r-m;
    int temp_left[left_length];
    int temp_right[right_length];
    for(int i=0;i<left_length;i++)
    {
        temp_left[i]=a[l+i];
    }
    for(int i=0;i<right_length;i++)
    {
        temp_right[i]=a[m+1+i];
    }
    for(int i=0,j=0,k=l;k<=r;k++)
    {
        if(((i<left_length)&&temp_left[i]<=temp_right[j])||(j>=right_length))
        {
            a[k]=temp_left[i];
            i++;
        }
        else
        {
            a[k]=temp_right[j];
            j++;
        }  
    }
            for(int k=0;k<6;k++)
            {
                printf("%d\t",a[k]);
            }
            printf("\n");
 }