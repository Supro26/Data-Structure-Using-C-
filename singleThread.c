//Single Threaded BST for inorder... BRAVOOO
#include<stdio.h>
#include<stdlib.h>
#include"Tree2.h"
tree *inorderSuccessor(tree *node)
{
    tree *curr=node->left;
    while(curr && curr->right)
    {
        curr=curr->right;
    }
    return curr;
}
tree *Threading(tree *node)
{
    if(node==NULL)
        return node;
    if(!leafnode(node))
    {
        tree *thnode=inorderSuccessor(node);
        if(thnode)
        {
            thnode->t_flag=1;
            thnode->right=node;
            node->left=Threading(node->left);
            if(node->t_flag == 0)
                node->right=Threading(node->right);
        }
    }
    else    return node;
return node;
}
tree *Iterate(tree *node)
{
    while(node->left)
    {
        node=node->left;
    }
    return node;
}
void inorder_in_loop(tree *root)
{
    tree *temp=Iterate(root);
    while(temp && temp->right)
    {
        if(temp->t_flag == 0)
        {
            printf("%d ",temp->data);
            temp=Iterate(temp->right);
        }
        else{
            printf("%d ",temp->data);
            temp=temp->right;
        }
    }
    if(!temp)
        printf("Empty Tree!!\n");
    else
        printf("%d\n",temp->data);
}
int main()
{
    int r,i;
    printf("Enter the Root Value: ");
    scanf("%d",&r);
    root=insertNode(root,r);
    printf("Enter the number of sub nodes to be inserted: ");
    scanf("%d",&i);
    for(int j=0;j<i;j++)
    {
        int val;
        printf("Enter the value to be inserted: ");
        scanf("%d",&val);
        root=insertNode(root,val);
    }
    root=Threading(root);
    printf("Inorder : ");
    inorder_in_loop(root);
    return 0;
}


