//deletion and insertion on max heap
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int *arr;
int *InsertMaxHeap(int *a,int pos)
{
    int i=pos;
    while(i)
    {
        if(pos%2==0)
            i=(pos/2)-1;
        else
            i=pos/2;
        if(a[i] < a[pos])
        {
            int tmp=a[i];
            a[i]=a[pos];
            a[pos]=tmp;
            pos=i;
        }
        else
            break;
    }
    return a;
}
int *DeleteMaxHeap(int *a,int size)
{
    int temp;
    temp=a[0];
    a[0]=a[size-1];
    a[size-1]=temp;
    int i=0;
    int left,right;
    while(i<size-1)
    {
        left=(i*2)+1;
        right=(i*2)+2;
        if(right<size-1)
        {
            if(a[right]>a[left] && a[right]>a[i])
            {
                temp=a[i];
                a[i]=a[right];
                a[right]=temp;
                i=right;
            }
            else if(a[left]>a[right] && a[left]>a[i])
            {
                temp=a[i];
                a[i]=a[left];
                a[left]=temp;
                i=left;
            }
            else
                break;
        }  
        else if(left<size-1)
        {
            if(a[left]>a[i])
            {
                temp=a[i];
                a[i]=a[left];
                a[left]=temp;
                i=left;
            }
            else
                break;
        }
        else
            break;       
    }
    return a;
}
int main()
{
    printf("enter the number of inputs:");
    int size;
    scanf("%d",&size);
    arr=(int *)malloc(size*sizeof(int));
    for(int i=0;i<size;i++)
    {
        printf("Enter the element %d: ",i+1);
        scanf("%d",&arr[i]);
        InsertMaxHeap(arr,i);
    }
    printf("ARRAY Representation :");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Do you want to delete element[1/0] : ");
    int choice;
    scanf("%d",&choice);
    if(choice)
    {
        DeleteMaxHeap(arr,size);
        size--;
    }
    printf("ARRAY Representation :");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
