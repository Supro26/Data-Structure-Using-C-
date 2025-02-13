// deleting duplicate values that comes before the last occurrence and display it..
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
struct node *delete_double()
{
	if(start==NULL)
	{
		printf("The Link List is Empty\n");
	}
    else if(start->link == NULL)
    {
        printf("Only one element in List!!\n");
        return start;
    }
    else{
	struct node *v=NULL;//value for checking
	v=start;
	struct node *prev=NULL;//1st pointer	
	struct node *nxt=NULL;//2nd pointer	
    int flag;
	while(v->link !=NULL)
	{
        nxt=v->link;
        flag=1;
		while(nxt != NULL)
		{
			if(v->data == nxt->data)
			{
                if(v==start)
                {
                    start=start->link;
                    break;
                }
                else{
                    prev->link=v->link;
                    flag=0;
                    break;
                }
			}
            else{			
                nxt=nxt->link;
            }
		}
        if(flag)
            prev=v;
        v=v->link;
        }
        printf("Deleting all buplicate values...\n");
	}
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
	int n,d;
	n=1;
	printf("Enter '1' to insert\n'2' to delete all duplicate values\n'3' to print\n'4' to stop\n");
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
				delete_double();
				break;
			case 3:
                display();
				break;
			case 4:
                n=-999;
                break;
            default:
				printf("Invalid Input!");
			}
	}
	return 0;
}