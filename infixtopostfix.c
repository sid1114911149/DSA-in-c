#include<stdio.h>
#include<stdlib.h>
#include<string.h>
static int top=-1,top2=-1,top3=-1;
#define M 100
char arr[M],arr2[M],arr3[M];
int check(char *k);
void push(char c);
void pushpost(char c);
int pop();
int main()
{
    char ch[100],*c;
    int count=0;
    printf("enter infix expression:");
    fgets(ch,100,stdin);
    if(check(ch))
    {
        c=ch;
        while(*c!='\0')
        {
            if(*c=='('||*c=='{'||*c=='[')
                push(*c);
            else if((*c>='a'&&*c<='z')||(*c>='A'&&*c<='Z')||(*c>='0'&&*c<'9'))
                pushpost(*c);
            else if((*c=='*'||*c=='+'||*c=='-'||*c=='/')&& count==0)
                printf("it is not a infix expression\n"); 
            else if((*c=='*'||*c=='/')&&(arr[top]=='-'||arr[top]=='+'))
                push(*c);
            else if((*c=='*'||*c=='/')&&(arr[top]=='*'||arr[top]=='/'))   
            {
                pushpost(pop());
                push(*c);
            }    
            else if((*c=='+'||*c=='-')&&(arr[top]=='-'||arr[top]=='+'||arr[top]=='*'||arr[top]=='/')) 
            {
                pushpost(pop());
                push(*c);
            }
            else if(*c==']'||*c==')'||*c=='}')
            {
                while(arr[top]!='('||arr[top]!='['||arr[top]!='{')
                {
                    pushpost(pop());
                }
                pop();
            }
            count++;
            c++;
        }
        while(top!=-1)
        {
            pushpost(pop());
        }
        printf("entered infix expression is balanced\n");
        printf("the postfix expression for the given infix expression is:");
        for(int i=0;i<=top2;i++)
        {
            printf("%c",arr2[i]);
        }
    }   
    else
    {
        printf("entered infix expression is not balanced\n");
    } 
    return 0;
}
void push(char c)
{
    if(top>=M-1)
    {
        printf("OVERFLOW\n");
        return ;
    }
    else
    {
        top+=1;
        arr[top]=c;
    }
}
int pop()
{
    int c;
    if(top==-1)
    {
        printf("UNDERFLOW\n");
    }
    else
    {
        c=top;
        top-=1;
        return arr[c];
    }
}
void pushpost(char c)
{
    if(top2>=M-1)
    {
        printf("OVERFLOW\n");
        return ;
    }
    else
    {
        top2+=1;
        arr2[top2]=c;
    }
}
int check(char *k)
{
    while(*k!='\0')
    {
        if(*k=='('||*k=='['||*k=='{')
        {
            top3+=1;
            arr3[top3]=*k;
        }
        else if(*k==')'||*k==']'||*k=='}')
        {
            if(*k!=arr3[top3])
                return 0;
            else
                top3-=1;    
        }
        k++;
    }
    return 1;
}

