#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"stack.h"
bool isChar(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int priority(char ch)
{
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}
bool isOperator(char ch)
{
    return (ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-');
}
void InfixtoPostfix(char *infix,char *postfix,int len,stack *sta)
{
    int j=0;
    for(int i=0;i<len;i++)
    {
        char ch=infix[i];
        if(isChar(ch))
        {
            postfix[j++] = ch;
        }
        else if(ch== '(')
        {
            push(sta,ch);
        }
        else if(ch==')')
        {
            while(!isEmpty(sta) && peek(sta)!='(')
            {
                postfix[j++] = pop(sta);
            }
            pop(sta);
        }
        else if(isOperator(ch))
        {
            while(!isEmpty(sta) && priority(ch)<=priority(peek(sta)))
            {
                postfix[j++] = pop(sta);
            }
            push(sta,ch);
        } 
    }
    while(!isEmpty(sta))
    {
        postfix[j++] = pop(sta);
    }
    postfix[j] = '\0';
}
int main()
{
    stack *sta;
    sta = (stack*)malloc(sizeof(stack));
    initialize(sta);
    printf("Enter the number of characters:");
    int n;
    scanf("%d",&n);
    char infix[n+1];
    char postfix[n+1];
    printf("Enter the infix expression:");
    scanf("%s",infix);
    int len = strlen(infix)+1;
    InfixtoPostfix(&infix[0],&postfix[0],len,sta);
    printf("The postfix expression is: %s\n",postfix);
    return 0;
}
