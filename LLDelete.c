// all deleting methodes and display of a singular LinkedList ..
#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *link;
};
struct node *start=NULL;
struct node *insert_end(int data)
{
	struct node *tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=data;
	tmp->link=NULL;
	if(start == NULL)
	{
		start=tmp;
		printf("Inserting %d at the end.....\n",tmp->data);
	}
	else{
		struct node *m;
		m=start;
		while(m->link != NULL)
		{
			m=m->link;
		}
		m->link=tmp;
		printf("Inserting %d at the end.....\n",tmp->data);
	}
	return start;
}
struct node *delete_start()
{
    if(start==NULL)
	{
		printf("The Link List is Empty\n");
	}
    else
    {
        printf("Deleting the value %d...\n",start->data);
	    start=start->link;
    }
    return start;
}
struct node *delete_end()
{
    if(start==NULL)
	{
		printf("The Link List is Empty\n");
	}
    else if(start->link == NULL)
    {
        start=NULL;
    }
    else{
        struct node *m;
        m=start;
        while(m->link !=NULL)
        {
            if(m->link->link == NULL)
            {
                printf("Deleting the value %d...\n",m->link->data);
                m->link=NULL;
            }
            else
            {
                m=m->link;
            }
        }
    }
    return start;

}
struct node *delete_any_position(int a)
{
	struct node *prev;
	struct node *cur;
	prev=NULL;
	cur=start;
	for(int i=1;i<a;i++)
	{
		prev=cur;
		cur=cur->link;
	}
    printf("Deleting the value %d...\n",cur->data);
	prev->link=cur->link;
	free(cur);
    return start;
}
void display()
{
	if(start==NULL)
	{
		printf("The Link List is Empty\n");
		return;
	}
	struct node *tmp;
	tmp=start;
	while(tmp != NULL)
	{
		printf("%d ",tmp->data);
		tmp=tmp->link;
	}
	printf("\n");
}
int main()
{
	int n,d,p;
	n=1;
	printf("Enter '1'=insert\n'2'=delete from start\n'3'=delete from end\n'4'=delete from any position\n'5'=to print\n'6'=to stop\n");
	while(n>0)
	{	
        printf("Enter choice:");	
		scanf("%d",&n);
		switch (n){
			case 1:
                printf("Enter the data:\n");
				scanf("%d",&d);
				insert_end(d);
				break;
			case 2:
				delete_start();
				break;
			case 3:
				delete_end();
				break;
			case 4:
                printf("Enter the position(it will delete that position data):\n");
                int pos;
                scanf("%d",&pos);
                delete_any_position(pos);
                break;
            case 5:
                display();
				break;          
			case 6:
                n=-999;
                break;
            default:
				printf("Invalid Input!");
			}
	}
	return 0;
}