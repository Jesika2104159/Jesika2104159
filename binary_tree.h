#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int val)
{
    struct node *nn=(struct node*)malloc(sizeof(struct node));
    nn->data=val;
    nn->left=NULL;
    nn->right=NULL;
}

void lc(struct node *r ,int val)
{
    struct node *p=create(val);
    r->left=p;
}

void rc(struct node*r,int val)
{
    struct node *p=create(val);
    r->right=p;
}
