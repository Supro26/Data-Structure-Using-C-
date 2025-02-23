#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct{
    int front,rear;
    int size;
    int *arr;
}queue;
queue *qu;
queue* initialize()
{
    qu->front = -1;
    qu->rear = -1;
    qu->size = 0;
    return qu;
}
bool isempty() {
    if(qu->front == -1)
        return true;
    else
        return false;
}
queue* inqueue(int data)
{
    if(isempty())
        qu->front++;
    if(qu->rear !=  qu->size-1)
        qu->arr[++qu->rear]=data;
    else
        printf("Queue Overflow!\n");
    return qu;
}
queue* dequeue()
{
    if(isempty())
        printf("Queue Underflow!\n");
    if(qu->front <= qu->rear)
        qu->front++;
    else
        printf("Queue is empty!\n");
    return qu;    
}
void display()
{
    for(int i=qu->front; i<=qu->rear; i++)
        printf("%d ", qu->arr[i]);
    printf("\n");
}
int main()
{
    qu=(queue *)malloc(sizeof(queue));
    initialize();
    printf("Enter the size of the array:\n");
    scanf("%d",&qu->size);
    qu->arr=(int*)malloc(qu->size*sizeof(int));
    int val=1;
    printf("Enter \n'1' to insert \n'2' to delete \n'3' to print \n'4' to stop\n");
    while (val > 0) {
        printf("\nEnter choice: ");
        scanf("%d", &val);
        switch(val)
        {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                inqueue(val);
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