
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} stack;

void initialize(stack *sta) {
    sta->top = -1;
}

bool isEmpty(stack *sta) {
    return sta->top == -1;
}

bool isFull(stack *sta) {
    return sta->top == MAX - 1;
}

void push(stack *sta, int n) {
    if (isFull(sta)) {
        printf("Stack Overflow!!\n");
        return;
    }
    sta->arr[++sta->top] = n;
    printf("Pushed %d in the Stack\n", n);
}

int pop(stack *sta) {
    if (isEmpty(sta)) {
        printf("Stack Underflow!!\n");
        return -1;
    }
    int popped = sta->arr[sta->top--];
    printf("Popped %d from the Stack\n", popped);
    return popped;
}

int peek(stack *sta) {
    if (isEmpty(sta)) {
        printf("Stack is empty!!\n");
        return -1;
    }
    return sta->arr[sta->top];
}

void print(stack *sta) {
    if (isEmpty(sta)) {
        printf("Stack is empty!!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= sta->top; i++) {
        printf("%d ", sta->arr[i]);
    }
    printf("\n");
}

int main() {
    stack st;  // Declare a normal stack variable
    initialize(&st);

    int val = 1, pval, tval;
    printf("Enter:\n'1' to push\n'2' to pop\n'3' to peek\n'4' to re-initialize\n'5' to print\n");

    while (val > 0) {
        printf("\nEnter choice: ");
        scanf("%d", &val);

        switch (val) {
            case 1:
                printf("Enter the value:\n");
                int a;
                scanf("%d", &a);
                push(&st, a);
                break;
            case 2:
                pval = pop(&st);
                break;
            case 3:
                tval = peek(&st);
                printf("Top element: %d\n", tval);
                break;
            case 4:
                initialize(&st);
                printf("Stack re-initialized!\n");
                break;
            case 5:
                print(&st);
                break;
            default:
                printf("Invalid Input!!\n");
                val = -999;
        }
    }
    return 0;
}