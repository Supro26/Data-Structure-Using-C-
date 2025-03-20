#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"Tree.h"
bool leafnode(tree *node)
{
    if(node->left == NULL && node->right == NULL)
        return true;
    else
        return false;
}
tree *LeftSubNode(tree *root)
{
    if(root->right == NULL)
        return root;
    else    
        return LeftSubNode(root->right);
}
tree *RightSubNode(tree *root)
{
    if(root->left == NULL)
        return root;
    else    
        return RightSubNode(root->left);
}
tree *deleteNode(tree *root,int data)
{
    if(root->data > data)
    {
        root->left=deleteNode(root->left, data);
    }
    else if(root->data < data)
    {
        root->right=deleteNode(root->right, data);
    }
    else{
        if(leafnode(root))
            return NULL;
        else if(root->left == NULL)
            return root->right;
        else if(root->right == NULL)
        {
            return root->left;
        }
            tree *temp1=LeftSubNode(root->left);
            tree *temp2=RightSubNode(root->right);
            if(leafnode(temp1))
            {
                root->data=temp1->data;
                root->left=deleteNode(root->left,temp1->data);
            }
            else if(leafnode(temp2))
            {
                root->data=temp2->data;
                root->right=deleteNode(root->right,temp2->data);
            }
            else{
                root->data=temp1->data;
                root->left=deleteNode(root->left,temp1->data);
            }

    }
    return root;
}
int main()
{
    int r,i;
    printf("Enter the Root Value: ");
    scanf("%d",&r);
    insertNode(r);
    printf("Enter the number of sub nodes to be inserted: ");
    scanf("%d",&i);
    for(int j=0;j<i;j++)
    {
        int val;
        printf("Enter the value to be inserted: ");
        scanf("%d",&val);
        insertNode(val);
    }
    printf("Inorder of the constructed tree is: ");  
    inorder(root);
    printf("\n");
    printf("Enter the value to be deleted: ");
    int val;    
    scanf("%d",&val);
    root=deleteNode(root,val);
    printf("Inorder of the modified tree is: ");
    inorder(root);
    return 0;
}