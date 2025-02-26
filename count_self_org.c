// self organized linked list with counting occurrence..
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    int count;
    struct node *link;
    };
struct node *start=NULL;
struct node *insert_end(int data)
{
	struct node *tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=data;
    tmp->count=0;
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
    if(data == start->data)
    {
            printf("data found!\n");
            start->count++;
            return start;
    }
    else{
        struct node *tmp1,*tmp2;
        tmp1=start;
        tmp2=NULL;
        while(tmp1 != NULL)
        {
            if(tmp1->data == data)
            {
                printf("data found!\n");
                tmp2->link=tmp1->link;
                flag=0;
                tmp1->count++;
                struct node *m1,*m2;
                m1=start;
                m2=NULL;
                while(m1 != NULL)
                {
                    if(tmp1->count > m1->count)
                    {
                        if(m1 == start)
                        {
                            tmp1->link=start;
                            start=tmp1;
                            return start; 
                        }
                        tmp1->link=m1;
                        m2->link=tmp1;
                        return start;
                    }
                    m2=m1;
                    m1=m1->link;
                }
                m2->link=tmp1;
                tmp1->link=NULL;
                return start;
            }
            else{
                tmp2=tmp1;
                tmp1=tmp1->link;
            }
        }   
    if(flag)
        printf("data not found!\n");
    return start;
    }
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
    printf("Enter:\n'1' to search for data \n'2' to display the reorganized list\n'3' to exit\n");
    while(p>0)
    {
        printf("Enter your choice: ");
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
                break;
            case 3:
                p=-999;
                break;
            default:
                printf("Invalid Input!\n");
        }
    }
    return 0;
}