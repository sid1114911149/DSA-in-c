#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*front,*rear,*temp,*new;
void create();
void queuefront();
void queuerear();
void enqueue();
void dequeue();
void display();
void queuecount();
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
    new=(struct node *)malloc(sizeof(struct node));
    new->next=NULL;
    if(new!=NULL)
    {
        printf("enter element:");
        scanf("%d",&new->data);
        if(front==NULL)
        {
            front=new;
            rear=new;
        }
        else
        {
            rear->next=new;
            rear=new;
        }
    }
    else
    {
        printf("NO SUFFICIENT SPACE\n");
    }    
}
void dequeue()
{
    if(front==NULL)
    {
        printf("UNDERFLOW\n");
    }
    else if(front==rear)
    {
        printf("popped element is %d\n",front->data);
        front=NULL;
        rear=NULL;
    }
    else
    {
        printf("popped element is %d\n",front->data);
        temp=front;
        front=front->next;
        temp->next=NULL;
    }    
}
void queuefront()
{
	if(front!=NULL)
		printf("front element of the queue is:%d\n",front->data);
	else
		printf("UNDERFLOW\n");	
}	
void queuerear()
{
	if(rear!=NULL)
		printf("rear element of the queue is:%d\n",rear->data);
	else
		printf("UNDERFLOW\n");	
}	
void queuecount()
{
    if(rear==NULL)
        printf("UNDERFLOW");
    else
    {
        int i=0;
        temp=front;
        while(temp!=NULL)
        {
            temp=temp->next;
            i++;
        }
        printf("no of elements in the queue is %d",i);   
    }     
}
void display()
{
    if(rear!=NULL)
    {
        temp=front;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
    else
        printf("UNDERFLOW");    
    printf("\n");
}