#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"Tree.h"
int heightCount(tree *node)
{
    if(node == NULL)
        return 0;
    else if(leafnode(node))
        return 1;
    else if(node->left == NULL && node->right != NULL)
        return 1 + heightCount(node->right);
    else if(node->left != NULL && node->right == NULL)
        return 1 + heightCount(node->left);
    else
    {
        int leftHeight = heightCount(node->left);
        int rightHeight = heightCount(node->right);
        if(leftHeight >= rightHeight)
        {
            return 1 + leftHeight;
        }
        else
        {
            return 1 + rightHeight;
        }
    }
}
int balanceFac(tree *node)
{
    int leftHeight = heightCount(node->left);
    int rightHeight = heightCount(node->right);
    int BF= leftHeight - rightHeight;
    return BF;
}
tree *LLRotate(tree *root)
{
    tree *tmp=root->right->left;
        root->right->left = root;
        root=root->right;
        root->left->right = tmp;
    return root;
}
tree *RRRotate(tree *root)
{
    tree *tmp=root->left->right;
        root->left->right = root;
        root=root->left;
        root->right->left = tmp;
    return root;
}
tree *RLRotate(tree *root)
{
    tree *tmp=root->right->left->right;
    tree *mid=root->right;
    root->right=mid->left;
    mid->left->right=mid;
    mid->left = tmp;
    return LLRotate(root);
}
tree *LRRotate(tree *root)
{
    tree *tmp=root->left->right->left;
    tree *mid=root->left;
    root->left=mid->right;
    mid->right->left=mid;
    mid->right = tmp;
    return RRRotate(root);
}
tree *BalancingI(tree *root,int data)
{
        int BF=balanceFac(root);
        if(BF>1 && data<root->left->data)
        {
            root = RRRotate(root);
        }
        else if(BF<-1 && data>root->right->data)
        {
            root = LLRotate(root);
        }
        else if(BF>1 && data>root->left->data)
        {
            root = LRRotate(root);
        }
        else if(BF<-1 && data<root->right->data)
        {
            root = RLRotate(root);
        }
    return root;
}
tree *BalancingD(tree *root,int data)
{
        int BF=balanceFac(root);
        if(BF>1 && data>root->left->data)
        {
            root = RRRotate(root);
        }
        else if(BF<-1 && data<root->right->data)
        {
            root = LLRotate(root);
        }
        else if(BF>1 && data<root->left->data)
        {
            root = LRRotate(root);
        }
        else if(BF<-1 && data>root->right->data)
        {
            root = RLRotate(root);
        }
    return root;
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
    printf("Enter the value to be deleted: ");
    int del;
    scanf("%d",&del);
    root=deleteNode(root,del);
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    return 0;
}