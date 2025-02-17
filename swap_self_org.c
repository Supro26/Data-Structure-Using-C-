// self organized linked list with swaping nodes (using two pointers)
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
struct node *slf_org(int data)
{
    int flag=1;
    if(start->link == NULL)
    {
        if(data == start->data)
            printf("data found!\n");
        else
            printf("data not found!\n");
    }
    else{
        struct node *tmp,*prev;
        tmp=start;
        prev=NULL;
        while(tmp->link != NULL)
        {
            if(tmp == start && tmp->data == data)
            {                          
                    printf("data found!\n");
                    flag=0;
                    break;
            }
            if(tmp->link->data == data)
            {
                printf("data found!\n");
                if(prev == NULL)
                {
                    prev=tmp->link;
                    tmp->link=tmp->link->link;
                    prev->link=tmp;
                    start=prev;
                }
                else{
                    prev->link=tmp->link;
                    tmp->link=tmp->link->link;
                    prev->link->link=tmp;
                }
            flag=0;
            break;
           }
            prev=tmp;
            tmp=tmp->link;
        }
    }
    if(flag)
        printf("data not found!\n");
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
    int n;
    printf("How many datas You want to insert?\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int data;
        printf("Enter the data : ");
        scanf("%d",&data);
        start=insert_end(data);
    }
    display();
    int p=1;
    printf("Enter '1' to search for data \n '2' to display the reorganized list\n");
    while(p>0)
    {
        scanf("%d",&p);
        switch(p)
        {
            case 1:
                printf("Enter the value:");
                int d;
                scanf("%d",&d);
                slf_org(d);
                 break;
            case 2:
                display();
                p=-999;
                break;
            default:
                printf("Invalid Input!\n");
        }
    }
    return 0;
}