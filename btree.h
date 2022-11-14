#include <stdio.h>
#include<stdlib.h>

int main(){
    
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
  

struct node *lc(struct node *r ,int val)
{
    struct node *p=create(val);
    r->left=p;
}

struct node *rc(struct node*r,int val)
{
    struct node *p=create(val);
    r->right=p;
}
void inorder(struct node*root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}

void preorder(struct node*root)
{
    if(root==NULL)
    return;
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node*root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}

int t_search(struct node*r ,int val)
{
    int r1, r2;
    if(r==NULL)
    return(0);
    if(r->data==val)
    return(1);
    r1=t_search(r->left,val);
    if(r1!=0)
    return(1);
    r2=t_search(r->right,val);
    if(r2!=0)
    return(1);
}
  
void search(struct node *r, int val)
{
    int x=t_search(r,val);
    if(x==0)
    printf("Element %d NOT found in tree!!",val);
    else
    printf("Element %d found in the tree");
}
 
  int c=0;
int count(struct node *r)
{
    if (r==NULL)
    return;
    c++;
    count(r->left);
    count(r->right);
    return(c);
}
  
   int max(struct node*r)
{
    int result;
    if(r==NULL)
    return(0);
    else
    {
        if(r->left==NULL && r->right==NULL)
        return(r->data);
        else
        {
            if(max(r->left) > max(r->right));
             result=r->left->data;
            if(max(r->left) <max(r->right));
             result=r->right->data;
            if(result>r->data)
            return(result);
            else
            return(r->data);
        }
    }
       
 void del(struct node* r)
{
    if(r->left==NULL && r->right==NULL)
     free(r);
     else
     {
         del(r->left);
         del(r->right);
     }
}
       
       void print(int arr[],int index)
{
    for(int i=0 ; i<=index ; i++ )
    printf("%d \t",arr[i]);
    printf("NULL\n");
}

void path(struct node *root,int arr[] ,int index)
{
    if(root==NULL)
    return;
    else
    {
    arr[index]=root->data;
    if(root->left==NULL && root->right==NULL)
    print(arr , index);
    path(root->left,arr,index+1);
    path(root->right,arr,index+2);

    }

}
