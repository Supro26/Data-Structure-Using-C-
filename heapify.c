#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int *arr;
int *Heapify(int *a,int size)
{
    int left,right;
    int temp=0;
    for(int j=size/2;j>=0;j--)
    {
        int i=j;
        while(i<size)
        {
            left=(i*2)+1;
            right=(i*2)+2;
            if(right<size)
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
            else if(left<size)
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
    }
    printf("ARRAY :");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    // for(int i=size;i>0;i--)
    // {
        arr=Heapify(arr,size);
    // }
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}