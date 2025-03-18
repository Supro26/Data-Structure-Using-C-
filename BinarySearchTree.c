#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tree
{
    char data;
    struct tree *left;
    struct tree *right;
}tree;

tree *root=NULL;

tree *leafnode(tree *leaf,int data)
{
        if(leaf->data >= data && leaf->left != NULL)
        {
            return leafnode(leaf->left,data);
        }
        else if(leaf->data < data && leaf->right != NULL)
        {
            return leafnode(leaf->right,data);
        }
        else{
            return leaf;
        }
}

tree *insertNode(int data)
{
    tree *temp=(tree*)malloc(sizeof(tree));
    temp->data=data;
    temp->left=temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
        // root->data=temp->data;
        // root->left=root->right=NULL;
    }
    else{
        tree *m=leafnode(root,data);
        if(m->data >= data)
            m->left=temp;
        else
            m->right=temp;
    }
    return root;
}
void preorder(tree *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
    else
        return;
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
    printf("Preorder of the constructed tree is: ");  
    preorder(root);
    printf("\n");
    return 0;
}