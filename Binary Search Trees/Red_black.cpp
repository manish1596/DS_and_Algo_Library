#include <iostream>
#include <limits.h>
using namespace std;

struct node
{
    int key;
    node* p;
    node* left;
    node* right;
    char color;
};

struct RBT
{
    node* root;
    node* nil;
    void init()
    {
        nil=new node;
        nil->p=NULL;
        nil->left=NULL;
        nil->right=NULL;
        nil->color='b';
        nil->key=INT_MIN;
        root=nil;
    }
};

node* create_node(RBT* r, int x)
{
    node* n=new node;
    n->key=x;
    n->left=r->nil;
    n->p=r->nil;
    n->right=r->nil;
    n->color='r';
    return n;
}

void leftrot(RBT** r, node* x)
{
    node* y=x->right;
    x->right=y->left;
    if(y->left!=(*r)->nil)
        (y->left)->p=x;
    y->p=x->p;
    if(x->p==(*r)->nil)
        {
            y->p=(*r)->nil;
            (*r)->root=y;
        }
    else
    {
        if((x->p)->left==x)
            (x->p)->left=y;
        else
            (x->p)->right=y;
    }
    x->p=y;
    y->left=x;
}

void rightrot(RBT** r, node* y)
{
    node* x=y->left;
    y->left=x->right;
    if(x->right!=(*r)->nil)
        (x->right)->p=y;
    x->p=y->p;
    if(y->p==(*r)->nil)
        {
            x->p=(*r)->nil;
            (*r)->root=x;
        }
    else
    {
        if((y->p)->left==y)
            (y->p)->left=x;
        else
            (y->p)->right=x;
    }
    y->p=x;
    x->right=y;
}

void rbt_ins_fixup(RBT** r, node* z)
{
    node* y;
    while((z->p)->color=='r')
    {
        if(((z->p)->p)->left==z->p)
        {
            y=((z->p)->p)->right;
            if(y->color=='r')
            {
                (z->p)->color='b';
                y->color='b';
                ((z->p)->p)->color='r';
                z=(z->p)->p;
            }
            else
            {
                if((z->p)->right==z)
                {
                    z=z->p;
                    leftrot(r, z);
                }
                (z->p)->color='b';
                ((z->p)->p)->color='r';
                rightrot(r, (z->p)->p);
            }
        }
        else
        {
            y=((z->p)->p)->left;
            if(y->color=='r')
            {
                (z->p)->color='b';
                y->color='b';
                ((z->p)->p)->color='r';
                z=(z->p)->p;
            }
            else
            {
                if((z->p)->left==z)
                {
                    z=z->p;
                    rightrot(r, z);
                }
                (z->p)->color='b';
                ((z->p)->p)->color='r';
                leftrot(r, (z->p)->p);
            }
        }
    }
    ((*r)->root)->color='b';
}

void ins_RBT(RBT** r, int k)
{
    node *a=create_node((*r), k);
    node* x=(*r)->root;
    node* y=(*r)->nil;
    while(x!=(*r)->nil)
    {
        y=x;
        if(k<x->key)
            x=x->left;
        else
            x=x->right;
    }
    a->p=y;
    if(y==(*r)->nil)
    {
        (*r)->root=a;
    }
    else
    {
        if(k<y->key)
            y->left=a;
        else
            y->right=a;
    }
    rbt_ins_fixup(r, a);
}

void inorder(RBT** r, node* x)
{
    if(x!=(*r)->nil)
    {
        inorder(r, x->left);
        cout << x->key << " ";
        inorder(r, x->right);
    }
}

int main()
{
    RBT* r1=new RBT;
    r1->init();
    for(int i=9724; i>0; i -= 2)
        ins_RBT(&r1, i);
    inorder(&r1, r1->root);
    return 0;
}
