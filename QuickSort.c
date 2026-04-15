#include<stdio.h>
 int partition(int arr[],int l,int h)
    {
        int pivot=arr[l];
        int i=l,j=h;
        while(i<j)
        {
            do{
                i++;
            }while(arr[i]<=pivot);
            do{
                j--;
            }while(arr[j]>pivot);
            if(i<j)
            {
                int tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
            else{
                int tmp=arr[j];
                arr[j]=pivot;
                arr[l]=tmp;
            }
        }
        return j;
    }
 void QuickS(int arr[],int l,int h)
    {
        if(l<h)
        {
            int j=partition(arr,l,h);
            QuickS(arr,l,j);
            QuickS(arr,j+1,h);
        }
    }
    int main() {
        int arr[]={5,13,77,12,1,37,90,28};
        QuickS(arr,0,8);
        for(int i=0;i<8;i++)
        {
            printf("%d ",arr[i]);
        }
    }
