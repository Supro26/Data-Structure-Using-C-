
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top1;
    int top2;
} stack;

bool isEmpty(stack *sta) {
    return sta->top1 == -1;
}

bool isFull(stack *sta) {
    return sta->top2 == MAX - 1;
}

void push(stack *sta, int n, int f) {
    if (isFull(sta)) {
        printf("Stack Overflow!!\n");
        return;
    }
    if(f==1)
    {
        if(sta->top2==sta->top1)
        {
            sta->arr[++sta->top1] = n;
            ++sta->top2;
        }
        else{
            for(int i=sta->top1+1;i<=sta->top2;i++)
            {
                sta->arr[i+1]=sta->arr[i];
            }
            sta->top2++;
            sta->arr[++sta->top1]=n;
        }
        printf("Pushed %d in the 1st Stack\n", n);
    }
    else if(f==2)
    {
        sta->arr[++sta->top2] = n;
        printf("Pushed %d in the 2nd Stack\n", n);
    }
}
int peek(stack *sta, int f) {
    if (isEmpty(sta)) {
        printf("Stack is empty!!\n");
        return -1;
    }
    if(f==1)
        return sta->arr[sta->top1];
    else
        return sta->arr[sta->top2];
}

void print(stack *sta) {
    if (isEmpty(sta)) {
        printf("Stack is empty!!\n");
        return;
    }
    printf("Stack 1 elements: ");
    for (int i = 0; i <= sta->top1; i++) {
        printf("%d ", sta->arr[i]);
    }
    printf("\n");
    printf("Stack 2 elements: ");
    for (int i = sta->top1+1; i <= sta->top2; i++) {
        printf("%d ", sta->arr[i]);
    }
    printf("\n");
}

int main() {
    stack st;
    st.top1=-1;
    st.top2=-1;
    int val = 1, tval,flag;
    printf("Enter:\n'1' to push\n'2' to peek\n'3' to print\n");

    while (val > 0) {
        printf("\nEnter choice: ");
        scanf("%d", &val);

        switch (val) {
            case 1:
                printf("Type '1' to push in stack1 & '2' to push in stack2:\n");
                scanf("%d",&flag);
                printf("Enter the value:\n");
                int a;
                scanf("%d", &a);
                push(&st, a, flag);
                break;
            case 2:
                printf("Which stack you want to peek?(enter '1' or '2'):\n");
                scanf("%d",&flag);
                tval = peek(&st,flag);
                printf("Top element: %d\n", tval);
                break;
            case 3:
                print(&st);
                break;
            default:
                printf("Invalid Input!!\n");
                val = -999;
        }
    }
    return 0;
}