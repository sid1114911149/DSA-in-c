#include<stdio.h>
#include<stdio.h>
#define M 5
static int arr[M];
int isfull();
void create();
void queuefront();
void queuerear();
void enqueue();
void dequeue();
void display();
void queuecount();
static int front=-1,rear=-1;
int main()
{
    int instruct;
    do 
    {
        printf("\nMenu:\n");
        printf("1. CREATE\n");
        printf("2. ENQUEUE\n");
        printf("3. DEQUEUE\n");
        printf("4. VIEW FRONT ELEMENT\n");
        printf("5. VIEW REAR ELEMENT\n");
        printf("6. VIEW NO OF ELEMENTS\n");
        printf("7. DISPLAY\n");
        printf("8. EXIT\n");
        printf("Enter your choice: ");
    	scanf("%d",&instruct);
    	switch(instruct)
    	{
    		case 1:
    			create();
    			break;
    		case 2:
    			enqueue();
    			break;	
        	case 3:
        		dequeue();
  			break;
    		case 4:
  			queuefront();
  			break;
  		case 5:
  			queuerear();
  			break;
            	case 6:
                	queuecount();
                	break;    
  		case 7:
  			display();
  			break;
  		case 8:
  			printf("exiting...\n");
  			break;	
  		default:
  			printf("NO COMMAND FOUND");
  			break;
    	}
    }while(instruct!=8);						  
    return 0;
} 
int isfull()
{
	if(rear>=front)
	{
		if(M==rear-front+1)
			return 1;
		else 
			return 0;
	}
    else
    {
        if(front-rear>1)
            return 0;
        else
            return 1;    			
	}
}    		
void create() 
{
    printf("QUEUE is created successfully.\n");
}    
void enqueue()
{
    if(isfull())
    {
        printf("OVERFLOW\n");   
        return; 
    }
    int n;
    if((rear<M-1))
    {
        printf("enter element:");
        scanf("%d",&n);
        if(front==-1)
        {
            front++;
        }  
        if(front==0)
        {  
        	rear++;
        	arr[rear]=n; 
        }
        else if(front!=0 && rear<front)
        {
        	rear++;
        	arr[rear]=n; 
        }	 
    }
    else if(rear>=M-1 && front!=0)
    {
        rear=-1;
        enqueue();
    }    
}
void display()
{
    if(rear==-1 && front==-1)
    {
        printf("UNDERFLOW\n");    
    }
    else if(front<=rear)
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d\t",arr[i]);
        }
    }
    else if(rear<front)
    {
        for(int i=front;i<M;i++)
        {
            printf("%d\t",arr[i]);
        }
        for(int i=0;i<=rear;i++)
        {
            printf("%d\t",arr[i]);
        }
    }
    printf("\n");
}
void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("UNDERFLOW\n");
    }
    else if(front==M-1 && rear==M-1)
    {
        printf("Popped element is %d\n",arr[front]);
        front=-1;
        rear=-1;
    }
    else if(front==M-1 && front>rear)
    {
        printf("Popped element is %d\n",arr[front]);
        front=0;
    }
    else if(front<rear)
    {
        printf("Popped element is %d\t",arr[front]);
        front++;
    }    
}
void queuefront()
{
	if(rear==-1 && front ==-1)
		printf("UNDERFLOW\n");	
	else
		printf("Front element of the queue is:%d\n",arr[front]);
}	
void queuerear()
{
	if(rear==-1 && front==-1)
		printf("UNDERFLOW\n");	
	else
		printf("Rear element of the queue is:%d\n",arr[rear]);
}	
void queuecount()
{
    int k;
    if(rear==-1 && front==-1)
        printf("UNDERFLOW");
    else
    {
        if(front>rear)
        {
            k=M-front+rear+1;
        }
        else
        {
            k=rear-front+1;
        }
        printf("No of elements in the queue is %d",k); 
    }       
}