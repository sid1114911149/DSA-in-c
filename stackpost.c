#include<stdio.h>
#include<stdlib.h>
#include<string.h>
static int top=-1;
int arr[100];
void push(int k);
int main()
{
    char ch[100];
    char *c;
    printf("enter expression::");
    scanf("%s",&ch);
    c=ch;
    int m,k;
    while(*c!='\0')
    {
        if(isdigit(*c)||(*c>='a'&&*c<='z')||(*c>='A'&&*c<='Z'))
        {
            *c-=48;
            push(*c);
        }
        else
        {
            k=arr[top];
            m=arr[top-1];
            top-=1;
            if(*c=='*')
            {
                arr[top]=k*m;
            }
            else if(*c=='/')
            {
                arr[top]=m/k;
            }
            else if(*c=='+')
            {
                arr[top]=k+m;
            }
            else if(*c=='-')
            {
                arr[top]=m-k;
            }
        }
        c++;
    }
    printf("result is %d",arr[top]);
    return 0;
} 
void push(int k)
{
	if(top<=100)
        {
            top++;
            arr[top]=k;
            printf("%d\n",arr[top]);
        } 
        else
        {
            printf("OVERFLOW\n");   
        }
}

