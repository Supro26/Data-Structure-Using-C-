#include<stdio.h>
#include <stdlib.h> 

typedef struct Node {
    int data;
    int col;// 0 = 'black' & 1 = 'red'
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} node;

node *root=NULL;
node *NIL;
void initializeNIL() {
    NIL = (node*)malloc(sizeof(node));
    NIL->col = 0;//NIL always black
    NIL->data = -9999;
    NIL->left = NIL->right = NIL->parent = NIL; 
}
node *Left_Rotate(node *root,node *a)
{
    node *b=a->right;
    a->right=b->left;
    if(b->left != NIL)  b->left->parent=a;
    b->parent=a->parent;
    if(a->parent == NIL)    root=b;
    else if(a == a->parent->left)   a->parent->left=b;
    else    a->parent->right=b;
    b->left=a;
    a->parent=b;
    return root;
}
node *Right_Rotate(node *root,node *b)
{
    node *a=b->left;
    b->left=a->right;
    if(a->right != NIL)  a->right->parent=b;
    a->parent=b->parent;
    if(b->parent == NIL)    root=a;
    else if(b == b->parent->right)   b->parent->right=a;
    else    b->parent->left=a;
    a->right=b;
    b->parent=a;
    return root;
}
node *FixInsertion(node *root, node *a)
{
    while(a->parent->col == 1)
    {
        if(a->parent == a->parent->parent->left)
        {
            node *unc=a->parent->parent->right;
            if(unc->col == 1)
            {
                a->parent->col = unc->col = 0;
                a->parent->parent->col = 1;
                a=a->parent->parent;
            }
            else{
                if( a == a->parent->right)
                {
                    a=a->parent;
                    root = Left_Rotate(root,a);
                }
                a->parent->col=0;
                a->parent->parent->col=1;
                root = Right_Rotate(root,a->parent->parent);
            }
        }
        else{
            node *unc=a->parent->parent->left;
            if(unc->col == 1)
            {
                a->parent->col = unc->col = 0;
                a->parent->parent->col = 1;
                a=a->parent->parent;
            }
            else{
                if( a == a->parent->left)
                {
                    a=a->parent;
                    root = Right_Rotate(root,a);
                }
                a->parent->col=0;
                a->parent->parent->col=1;
                root = Left_Rotate(root,a->parent->parent);
            }
        }
    }
    root->col=0;
    return root;
}
node *Insertion(node *root,int data)
{
    if(root==NULL)
    {
        node *temp=(node*)malloc(sizeof(node));
        temp->col=0;//root always black
        temp->data=data;
        temp->left=temp->right=temp->parent=NIL;
        root=temp;
        return root;
    }
    node *m=root;//temp
    node *pm=NULL;//parent temp
    while(m!=NIL)
    {
        pm=m;
        if(data > m->data)
        {
            m=m->right;
        }
        else{
            m=m->left;
        }
    }
    node *temp=(node*)malloc(sizeof(node));
    temp->col=1;//red by default
    temp->parent=pm;
    if(pm->data > data)
    {
        pm->left = temp;
    }
    else{
        pm->right=temp;
    }
    temp->data=data;
    temp->left=temp->right=NIL;
    root = FixInsertion(root,temp);
    return root;
}
void printTree(node* root, int space) {
    if (root == NULL || root == NIL) return;
    space += 5;
    printTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) printf(" ");
    printf("%d(%s)\n", root->data, root->col == 1 ? "R" : "B");
    printTree(root->left, space);
}
void inorder(node* root) {
    if (root == NULL || root == NIL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
// Output should always be sorted!
int main()
{
    initializeNIL();
    root = Insertion(root,5);
    root = Insertion(root,18);
    root = Insertion(root,20);
    root = Insertion(root,6);
    root = Insertion(root,70);
    root = Insertion(root,30);
    root = Insertion(root,50);
    root = Insertion(root,3);
    root = Insertion(root,14);
    root = Insertion(root,26);
    root = Insertion(root,84);
    root = Insertion(root,10);
    root = Insertion(root,60);

    printTree(root,0);
    printf("\n\n");
    inorder(root);
    printf("\n");
    // printf("%d",root->data);
    return 0;
}
