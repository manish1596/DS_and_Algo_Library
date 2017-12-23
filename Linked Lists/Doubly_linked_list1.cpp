#include <iostream>
using namespace std;

struct node
{
    int data;
    node* prev;
    node* next;
};

void display(node** head)
{
    node *ptr=*head;
    cout << (*head)->data;
    while(ptr->next!=0)
        cout << ptr->data << " ";
    cout << "\n";
}


void inser_t(node** head, int nn, int x)
{
    node* temp;
    int i;
    i=1;
    if(*head==0)
    {
        (*head)->data=x;
        (*head)->prev=0;
        (*head)->next=0;
    }
    else
    {
        node *ptr=*head;
        node *n=new node;
        n->data=x;
        temp=*head;
        while(ptr!=0 && i<nn)
        {
            if(i==nn-1)
             temp=ptr;
            ptr=ptr->next;
            i++;
        }
        if(i==nn)
        {
            n->prev=temp;
            n->next=ptr;
            temp->next=n;
            ptr->prev=n;
        }
        else
            cout << "Insertion not possible at this node number";
    }
}


int main()
{
    node *n1;
    n1=new node;
    n1->prev=0;
    n1->data=2;
    n1->next=0;
    display(&n1);
    inser_t(&n1, 1, 7);
    display(&n1);
    inser_t(&n1, 2, 8);
    display(&n1);
    inser_t(&n1, 3, 9);
    display(&n1);
    return 0;
}
