#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int *arr;
int *maxheap(int *a,int pos)
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
        maxheap(arr,i);
    }
    printf("ARRAY Representation :");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}