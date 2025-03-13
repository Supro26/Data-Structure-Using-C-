#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct node{
	int data;
	struct node *link;
}node;
node *front=NULL;
node *rear=NULL;

bool isempty() {
    if(front == NULL && rear ==NULL)
        return true;
    else
        return false;
}
node* inqueue(int data,int size)
{
	node *tmp;
	tmp=(node*)malloc(sizeof(node));
    if(isempty())
    {
        front=tmp;
        rear=tmp;
        tmp->data=data;
        tmp->link=front;
        printf("Inserting %d in the Queue...\n",data);
        return rear;
    }
    node *m;
    m=front;
    int c=1;
    while(m->link != front)
    {
    	c++;
    	m=m->link;
    }   	
    if(c < size)
    { 
        tmp->data=data;
        rear->link=tmp;
        rear=tmp;
        tmp->link=front;
        printf("Inserting %d in the Queue...\n",data);
    }
    else{
        printf("Queue Overflow!\n");
    }
    return rear;    
}
node* dequeue()
{
    if(isempty())
        printf("Queue Underflow!\n");
    else if(front->link == front)
    {
    	printf("Deleting %d from the Queue...\n",front->data);
    	node*n=front;	
    	front=NULL;
    	rear=NULL;
    	free(n);
    }
    else{
    	printf("Deleting %d from the Queue...\n",front->data);
    	node *m2=front;	
    	rear->link=m2->link;
    	front=rear->link;
    	free(m2);
    }
    return front;    
}
void display()
{
    if(isempty())
        printf("Queue is empty!\n");
    else{
    node *m;
    m=front;
	while(m->link != front)
    	{
    		printf("%d ",m->data);
    		m=m->link;
    	}
    printf("%d\n",m->data);
	}
}
int main()
{
	int size;
    printf("Enter the size of the queue:\n");
    scanf("%d",&size);
    int val=1;
    while (val > 0) {
    	printf("Enter \n'1' to insert \n'2' to delete \n'3' to print \n'4' to stop\n");
        printf("\nEnter choice: ");
        scanf("%d", &val);
        switch(val)
        {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                inqueue(val,size);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Queue: ");
                display();
                break;
            case 4:
                val=-999;
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
 }