#include<stdio.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create (int v)
{
    struct node *p=(struct node *)malloc (sizeof(struct node));
    p->data=v;
    p->left=NULL;
    p->right=NULL;
    return(p);
}

struct node *lc (int v, struct node *r)
{
    struct node *p=create(v);
    r->left=p;
}

struct node *rc (int v, struct node *r)
{
    struct node *p=create(v);
    r->right=p;
}

void preorder(struct node *r)
{
    if(r=NULL)
        return;
    printf("%d  ",r->data);
    preorder(r->left);
    preorder(r->right);
}
main()
{
    struct node *root=(struct node *)malloc(sizeof(struct node));
    root=create(1);
    lc(2,root);
    rc(3,root);
    lc(4,root->left);
    rc(5,root->left);
    lc(6,root->right);
    lc(7,root->left->right);
    preorder(root);
 
}
    
    
