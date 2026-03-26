#include<stdio.h>
#include <stdlib.h> 

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void insertAtEnd(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = new_data;    
    new_node->next = NULL;  
    if((*head_ref) == NULL)
    {
        (*head_ref) = new_node;
    }
    else{
        Node *m;
		m=(*head_ref);
		while(m->next != NULL)
		{
			m=m->next;
		}
		m->next=new_node;
    } 
}
Node *delete_start(Node *start)
{
	start=start->next;
    return start;
}

void Radex_Sort(int *arr, int n,int d)
{
    Node** bin;
    bin=calloc(10, sizeof(struct Node*));
    int div=1;
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<n;j++)
        {
            int pos=(arr[j] / div ) % 10;
            insertAtEnd(&bin[pos],arr[j]);          
        }
        div*=10;
        int j=0;
        for(int k=0;k<10;k++)
        {
            if(bin[k]==NULL)
            {
                continue;
            }
            else{
                while(bin[k] != NULL)
                {
                    arr[j]=bin[k]->data;
                    bin[k]=delete_start(bin[k]);
                    j++;
                } 
                bin[k]=NULL;    
            }
        }

    }
    free(bin);
}
int main()
{
    int arr[]={12,55,3,77,10,8,60,40};
    Radex_Sort(arr,8,2);
    for(int i=0;i<8;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}