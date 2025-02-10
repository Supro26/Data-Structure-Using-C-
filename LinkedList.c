// all inserting methodes and display of a singular LinkedList ..
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
struct node *insert_start(int data)
{
	struct node *tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=data;
	tmp->link=NULL;
	if(start == NULL)
	{
		start=tmp;
		printf("Inserting %d at the start.....\n",tmp->data);
	}
	else{
		tmp->link=start;
		start=tmp;
		printf("Inserting %d at the start.....\n",tmp->data);
	}
	return start;
}
struct node *insert_any(int data, int pos)
{
	struct node *tmp;
	struct node *m1;
	struct node *m2;
	tmp=(struct node*)malloc(sizeof(struct node));
	m1=start;
    m2=start->link;
	tmp->data=data;
	for(int i=1;i<(pos-1);i++)
	{	
		m1=m1->link;
        m2=m2->link;
	}
    m1->link=tmp;
	tmp->link=m2;
    printf("Inserting %d at position %d.....\n",tmp->data,pos);
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
	printf("Enter '1'=insert at end\n'2'=insert at start\n'3'=insert at any position\n'4'=to print\n'5'=to stop\n");
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
                printf("Enter the data:\n");
				scanf("%d",&d);
				start=insert_start(d);
				break;
			case 3:
				printf("Enter the data:\n");
				scanf("%d",&d);
				printf("Enter the position(it will add before that position):\n");
				scanf("%d",&p);
				insert_any(d,p);
				break;
			case 4:
				display();
				break;
            case 5:
                n=-999;
                break;
			default:
				printf("Invalid Input!");
			}
	}
	return 0;
}