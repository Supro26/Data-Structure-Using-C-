// Double Circular LinkedList Insertion & Display...
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *prev;
    struct node *next;
}node;
node *start=NULL;
node *insert(int data,int f)
{
    node *new;
    new=(node*)malloc(sizeof(node));
    new->data=data;
    if(start==NULL)
    {
        new->prev=new;
        new->next=new;
        start=new;
        return start;
    }
    new->next=start;
    new->prev=start->prev;
    start->prev=new;
    new->prev->next=new;
    if(f)
        start=new;
    return start;    
}
node *insert_any(int data, int pose)
{
    node *new;
    new=(node*)malloc(sizeof(node));
    new->data=data;
    if(start==NULL)
    {
        new->prev=new;
        new->next=new;
        start=new;
        return start;
    }
    node *temp=start;
    for(int i=1;i<pose-1;i++)
        temp=temp->next;
    new->next=temp->next;
    new->prev=temp;
    temp->next->prev=new;
    temp->next=new;
    return start;
}
void display()
{
	if(start==NULL)
	{
		printf("The Link List is Empty\n");
		return;
	}
    printf("\nList: ");
	struct node *tmp;
	tmp=start;
	while(tmp->next != start)
	{
		printf("%d ",tmp->data);
		tmp=tmp->next;
	}
    printf("%d ",tmp->data);
	printf("\n\n");
}
int main()
{
    int choice=1,data;
    while(choice>0){
        printf("Enter\n'1' to Insert at end\n'2' to insert at start\n'3' to Insert at any Position\n'4' to display\n'5' to exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d",&data);
                insert(data,0);
                break;
            case 2:
                printf("Enter the data to be inserted: ");
                scanf("%d",&data);
                insert(data,1);
                break;
            case 3:
                printf("Enter the data to be inserted: ");
                scanf("%d",&data);
                int pos;
                printf("Enter the position to insert: ");
                scanf("%d",&pos);
                insert_any(data,pos);
                break;
            case 4:
                display();
                break;
            case 5:
                choice=-999;
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
