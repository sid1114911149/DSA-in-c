#include<stdio.h>
#include<stdio.h>
#define M 100
static int arr[M];
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
void create() 
{
    printf("QUEUE is created successfully.\n");
}    
void enqueue()
{
    int n;
    if(rear<M-1)
    {
        printf("enter element:");
        scanf("%d",&n);
        if(front==-1)
        {
            front++;
            rear++;
            arr[front]=n;
        }
        else
        {
            rear++;
            arr[rear]=n;
        }
    }
    else
    {
        printf("NO SUFFICIENT SPACE\n");
    }    
}
void display()
{
    if(front<=rear)
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d\t",arr[i]);
        }
    }
    else
        printf("UNDERFLOW\n");    
    printf("\n");
}
void dequeue()
{
    if(front>rear||front==-1||rear==-1)
    {
        printf("UNDERFLOW\n");
        front=-1;
        rear=-1;
    }
    else
    {
        printf("popped element is %d\n",arr[front]);
        front++;  
    }    
}
void queuefront()
{
	if(front<=rear && front!=-1)
		printf("front element of the queue is:%d\n",arr[front]);
	else
		printf("UNDERFLOW\n");	
}	
void queuerear()
{
	if(front<=rear && front!=-1)
		printf("rear element of the queue is:%d\n",arr[rear]);
	else
		printf("UNDERFLOW\n");	
}	
void queuecount()
{
    if(front>rear|| front==-1)
        printf("UNDERFLOW");
    else
        printf("no of elements in the queue is %d",rear-front+1);    
}