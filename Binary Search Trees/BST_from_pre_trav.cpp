#include <iostream>
#include <limits.h>
using namespace std;

struct node
{
    int key;
    node* p;
    node* left;
    node* right;
};

struct BST
{
    node* root;
};

void init(BST** b)
{
    (*b)->root=NULL;
}

node* create_node(int x)
{
    node* n=new node;
    n->key=x;
    n->p=NULL;
    n->left=NULL;
    n->right=NULL;
}

void ins_elem(BST** b, int e)
{
    node* n=create_node(e);
    node* y=NULL;
    node* x=(*b)->root;
    while(x!=NULL)
    {
        y=x;
        if(e<x->key)
            x=x->left;
        else
            x=x->right;
    }
    n->p=y;
    if(y==NULL)
        (*b)->root=n;
    else
        if(e<y->key)
            y->left=n;
        else
            y->right=n;
}

void inorder(node* x)
{
    if(x!=NULL)
    {
        inorder(x->left);
        cout << x->key << " ";
        inorder(x->right);
    }
}

void preorder(node* x)
{
    if(x!=NULL)
    {
        cout << x->key << " ";
        preorder(x->left);
        preorder(x->right);
    }
}

void postorder(node* x)
{
    if(x!=NULL)
    {
        postorder(x->left);
        postorder(x->right);
        cout << x->key << " ";
    }
}

node* sear_ch(BST** b, int y)
{
    node* x=(*b)->root;
    while(x!=NULL && x->key!=y)
        {
            if(y<x->key)
                x=x->left;
            else
                x=x->right;
        }
        return x;
}

int node_min(BST** b, node* n1)
{
    node* x=n1;
    node* y=NULL;
    while(x!=NULL)
    {
        y=x;
        x=x->left;
    }
    if(y!=NULL)
    {   return y->key;}
    else
    {
        cout << "Error : Invalid Node";
        return INT_MIN;
    }
}

int successor(BST** b, int x)
{
    node* n1=sear_ch(b, x);
    if(n1==NULL)
    {
        cout << "This element does not exist in the tree";
        return INT_MIN;
    }
    if(n1->right!=NULL)
    {
        return node_min(b, n1->right);
    }
    else
    {
        node* y=n1->p;
        while(y!=NULL && y->left!=n1)
        {
            n1=y;
            y=y->p;
        }
        if(y==NULL)
        {
            cout << x << " is the largest element in the tree and hence has no successor";
            return INT_MIN;
        }
        else
        {
            return y->key;
        }
    }
}

void transplant(BST **b, node* u, node* v)
{
    if(u->p==NULL)
        (*b)->root=v;
    else if((u->p)->left==u)
        (u->p)->left=v;
    else
        (u->p)->right=v;
    if(v!=NULL)
        v->p=u->p;
    u->p=NULL;
}

void delete_node(BST **b, node* z)
{
    if(z->left==NULL)
        transplant(b, z, z->right);
    else if(z->right==NULL)
        transplant(b, z, z->left);
    else
    {
        node* y=z->right;                                            //node* y=sear_ch(b, node_min(b, z->right));
        while(y->left!=NULL)
            y=y->left;
        if(z->right!=y)
        {
            transplant(b, y, y->right);
            y->right=z->right;
            (y->right)->p=y;
        }
        y->left=z->left;
        (y->left)->p=y;
        transplant(b, z, y);
    }
    z->left=NULL;
    z->right=NULL;
}

BST* tree_from_pre_trav(int* arr, int n)
{
    int i, j;
    node* n1[n];
    BST* b;
    init(&b);
    i=0;
    j=0;
    while(i<n)
    {
        while(arr[i]<arr[i+1])
        {
            n1[i]=create_node(arr[i]);
            if(i==0)
            {
                n1[i]->p=NULL;
            }
            else
            {
                n1[i]->p=n1[i-1];
                n1[i]->left=
            }
        }
    }
}
