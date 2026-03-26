#include<stdio.h>
#include <stdlib.h> 

typedef struct Node {
    float data;
    struct Node *next;
} Node;

void sortedInsert(Node** sorted_head, Node* new_node) {
    if (*sorted_head == NULL || (*sorted_head)->data >= new_node->data) {
        new_node->next = *sorted_head;
        *sorted_head = new_node;
    } else {
        Node* curr = *sorted_head;
        while (curr->next != NULL && curr->next->data < new_node->data) {
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
    }
}

Node* insertionSort(Node* head) {
    Node* sorted = NULL;
    Node* curr = head;

    while (curr != NULL) {
        Node* next_node = curr->next;
        sortedInsert(&sorted, curr);
        curr = next_node;        
    }
    return sorted;
}

void insertAtEnd(Node** head_ref, float new_data) {
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
void Bucket_S(float *arr,int n)
{
    Node **bucket;
    bucket=calloc(n, sizeof(struct Node*));
    for(int i=0;i<n;i++)
    {
        insertAtEnd(&bucket[(int)(n*arr[i])],arr[i]);          
    }
    for(int i=0;i<n;i++)
    {
        bucket[i]=insertionSort(bucket[i]);
    }
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(bucket[i]==NULL)
            {
                continue;
            }
            else{
                while(bucket[i] != NULL)
                {
                    arr[j]=bucket[i]->data;
                    bucket[i]=delete_start(bucket[i]);
                    j++;
                } 
                bucket[i]=NULL;    
            }
    }
    free(bucket);

}
int main()
{
    float arr[]={0.12,0.55,0.3,0.77,0.1,0.8,0.6,0.4};
    Bucket_S(arr,8);
    for(int i=0;i<8;i++)
    {
        printf("%.2f ",arr[i]);
    }
    printf("\n");
    return 0;  
}