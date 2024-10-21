#include<stdio.h>
#include<stdlib.h>
#define M 100
int arr0[M],arr1[M],arr2[M],arr3[M],arr4[M],arr5[M],arr6[M],arr7[M],arr8[M],arr9[M];
int f0=-1,r0=-1,f1=-1,r1=-1,f2=-1,r2=-1,f3=-1,r3=-1,f4=-1,r4=-1,f5=-1,r5=-1,f6=-1,r6=-1,f7=-1,r7=-1,f8=-1,r8=-1,f9=-1,r9=-1;
void push(int arr[],int n,int *f,int *r);
int pop(int arr[],int *f,int *r);
int main()
{
    int arr[M],n,l,count=0,k,a;
    printf("enter the number of elements in the array:");
    scanf("%d",&n);
    printf("enter elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    l=arr[0];
    for(int i=1;i<n;i++)
    {
        if(l<arr[i])
        {
            l=arr[i];
        }
    }
    while(l>0)
    {
        l=l/10;
        count++;
    }
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<n;j++)
        {
            k=arr[j];
            for(int a=0;a<i;a++)
            {
                k=k/10;
            }
            k=k%10; 
                switch(k)
                {
                    case 0: 
                            push(arr0,arr[j],&f0,&r0);
                            break;
                    case 1: 
                            push(arr1,arr[j],&f1,&r1);
                            break;
                    case 2: 
                            push(arr2,arr[j],&f2,&r2);
                            break;
                    case 3: 
                            push(arr3,arr[j],&f3,&r3);
                            break;
                    case 4: 
                            push(arr4,arr[j],&f4,&r4);
                            break;
                    case 5: 
                            push(arr5,arr[j],&f5,&r5);
                            break;
                    case 6: 
                            push(arr6,arr[j],&f6,&r6);
                            break;
                    case 7: 
                            push(arr7,arr[j],&f7,&r7);
                            break;
                    case 8: 
                            push(arr8,arr[j],&f8,&r8);
                            break;
                    case 9: 
                            push(arr9,arr[j],&f9,&r9);
                            break;                                                                        
                }
        }
        for(int m=0;m<n;m++)
        {
            if(f0!=-1)
                arr[m]=pop(arr0,&f0,&r0);
            else if(f1!=-1)
                arr[m]=pop(arr1,&f1,&r1);    
            else if(f2!=-1)
                arr[m]=pop(arr2,&f2,&r2);
            else if(f3!=-1)
                arr[m]=pop(arr3,&f3,&r3);
            else if(f4!=-1)
                arr[m]=pop(arr4,&f4,&r4);
            else if(f5!=-1)
                arr[m]=pop(arr5,&f5,&r5);
            else if(f6!=-1)
                arr[m]=pop(arr6,&f6,&r6);
            else if(f7!=-1)
                arr[m]=pop(arr7,&f7,&r7);
            else if(f8!=-1)
                arr[m]=pop(arr8,&f8,&r8); 
            else if(f9!=-1)
                arr[m]=pop(arr9,&f9,&r9);   
           // printf("%d\n",arr[m]);                                 
        }
    }  
    printf("elements after sorting:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }  
    return 0;
}
void push(int arr[],int n,int *f,int *r)
{
    if(*r==M)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        if(*f==-1)
        {
            *f+=1;
            *r+=1;
            arr[*f]=n;
        }
        else
        {
            *r+=1;
            arr[*r]=n;
        }
    }
}
int pop(int arr[],int *f,int *r)
{
        int k=*f;
        if(*f==*r)
        { 
            *f=-1;
            *r=-1;
            return arr[k];
        }
        else
            *f+=1;
        return arr[k];
}