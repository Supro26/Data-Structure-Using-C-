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
struct node *reverse()
{
    if(start==NULL)
        printf("List is Empty!\n");
    else if(start->link==NULL)
        printf("List has only one node!\n");
    else{
        struct node *prev, *nxt, *curr;
        prev=NULL;
        curr=start;
        nxt=start->link;
        while(nxt!=NULL){
            curr->link=prev;
            prev=curr;
            curr=nxt;
            nxt=nxt->link;
        }
        curr->link=prev;
        start=curr;
        printf("Reversing the List...\n");
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
    printf("\nList: ");
	struct node *tmp;
	tmp=start;
	while(tmp != NULL)
	{
		printf("%d ",tmp->data);
		tmp=tmp->link;
	}
	printf("\n\n");
}
int main()
{
    int choice=1,data;
    while(choice>0){
        printf("Enter\n'1' to Insert at end\n'2' to Reverse\n'3' to Display\n'4' to Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d",&data);
                start=insert_end(data);
                break;
            case 2:
                reverse();
                break;
            case 3:
                display();
                break;
            case 4:
                choice=-999;
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}