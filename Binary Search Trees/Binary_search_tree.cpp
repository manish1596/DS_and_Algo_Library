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


int main()
{
    /*BST* b=new BST;
    init(&b);
    ins_elem(&b, 9);
    ins_elem(&b, 600);
    inorder(b->root);
    //ins_elem(&b, 700);
    cout << "\n";
    inorder(b->root);
    cout << "\n" <<"***" << node_min(&b, b->root) << "***";
    ins_elem(&b, 7);
    inorder(b->root);
    cout << "\n";
    for(int i=1000; i>0; i-=2)
        ins_elem(&b, i);
    inorder(b->root);
    cout << "\n";
    node* n1=sear_ch(&b, 498);
    cout << n1->key;
    cout << "\n" << successor(&b, 600) << "\n";
    cout << "***" << node_min(&b, b->root) << "***";
    delete_node(&b, sear_ch(&b, 234));
    inorder(b->root);
    delete_node(&b, sear_ch(&b, 236));
    inorder(b->root);
    for(int e=350; e<=600; e+=2)
        delete_node(&b, sear_ch(&b, e));
    inorder(b->root);*/
    int x, y, z;
    node* temp;
    BST* b=new BST;
    init(&b);
    while(x!=8)
    {
        cout << "\nPress 1 for insertion in the tree, \n2 for preorder traversal, \n3 for postorder traversal, \n4 for inorder traversal, \n5 for deleting a node, \n6 for searching a key, \n7 for finding the succesor of a key and \n8 for exit\n";
        cin >> x;
        switch(x)
        {
        case 1:
            cout << "Enter the element to be inserted : ";
            cin >> y;
            ins_elem(&b, y);
            break;
        case 2:
            preorder(b->root);
            break;
        case 3:
            postorder(b->root);
            break;
        case 4:
            inorder(b->root);
            break;
        case 5:
            cout << "Enter the element to be deleted : ";
            cin >> y;
            temp=sear_ch(&b, y);
            if(temp==NULL)
            {
                cout << "This element does not exist in the tree";
                break;
            }
            else
            {
                delete_node(&b, temp);
                cout << "Node deleted";
                break;
            }
        case 6:
            cout << "Enter the element to be searched : ";
            cin >> y;
            temp=sear_ch(&b, y);
            if(temp==NULL)
            {
                cout << "This element does not exist in the tree";
                break;
            }
            else
            {
                cout << "Element found in the tree";
                break;
            }
        case 7:
            cout << "Enter the element : ";
            cin >> y;
            z=successor(&b, y);
            cout << "Successor is " << z;
            break;
        }
    }
    return 0;
}
