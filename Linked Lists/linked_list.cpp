#include <iostream>
#define nullptr 0
using namespace std;

struct node
{
    int info;
    node *link;
};

void addinfo(node **head_ref, int b)
{
    node *a=new node;
    a->info=b;
    node *start=*head_ref;
    if(start==0)
    {
        start=new node;
        start->info=b;
        start->link=0;
        *head_ref=start;
        return;
    }
    else
    {while(start->link!=0)
    {
        start=start->link;
    }
    start->link=a;
    a->link=0;}
    //cout << "start->link is" << start->link << "\n";
    //cout << "start->link is" << start.link << "\n";
    cout << "node added successfully\n" ;
}

void searc_h(int infor, node *ptr, node *location)
{
    //node *ptr=start;
    if(ptr==0)
    {
        cout << "The linked list is empty.....there is nothing to search for!!!";
        return;
    }
    bool check=false;
    int i=0;
    while(ptr->link!=0)
    {
        i++;
        if((ptr->info)==infor)
        {
            location->info=ptr->info;
            cout << "Element found in the linked list at node number : " << i;
            check=true;
            break;
        }
        ptr=ptr->link;
    }
    if(check==false)
        {cout << "Element not found";}
}

void insrt_mid(int data, node *start, int node_number)
{
    if(node_number!=1)
    {
        node *n=new node;
        node *temp;
        n->info=data;
        node *avail=start;
        int i;
        for(i=1; i<node_number; i++)
        {
            if(i==node_number-1)
            {
                temp=avail;
            }
            if(avail==0)
                break;
            else
                avail=avail->link;
        }
        if(i==node_number)
        {
            temp->link=n;
            n->link=avail;
        }
        else
        {
            cout << "Error : Insertion cannot be executed.";
        }
    }
    else
    {
        cout << "Error : To insert at the beginning, use the option number 3";
    }
}

node* insrt_begin(int data, node *start)
{
    node *n=new node;
    n->info=data;
    n->link=start;
    return n;
}

void traverse(node *start)
{
    node *ptr=start;
    while(ptr!=nullptr)
    {
        cout << ptr->info;
        //cout << ptr;
        cout << "\n";
        ptr=ptr->link;
    }
    //cout << "\n" << ptr;
}

int deletion(node *ptr, int node_number)
{
    if(ptr==0)
    {
        cout << "Linked list is empty, no element can be deleted.\n";
        return -31000;
    }
    else
    {
        int i,ret;
        node *temp;
        for(i=1; i<=node_number; i++)
            {
                if(i==node_number-1)
                    temp=ptr;
                ptr=ptr->link;
            }
        if(i==node_number+1)
            {
                ret=(temp->link)->info;
                temp->link=ptr;
                return ret;
            }
        else
            {
                cout << "The linked list does not have these many nodes";
                return -31000;
            }
    }
}

node* revers(node *head)
{
    int j;
    node** arr;
    arr= new node*[100];
    for(j=0; j<100; j++)
        arr[j]=new node;
    int i;
    i=0;
    while(head->link!=0)
    {
        arr[i]->info=head->info;
        head=head->link;
        i++;
    }
    arr[i]->info=head->info;
    node *temp1=arr[i];
    while(i>0)
    {
        arr[i]->link=arr[i-1];
        i--;
    }
    arr[0]->link=0;
    return temp1;
}

int main()
{
    int a, b, y;
    int key;
    int n, l;
    node *loc=new node;
    char m='w';
    node *n1=new node;
    n1=0;
    //n1->info=12;
    //n1->link=0;
    while(m!='x')
    {cout <<"\nEnter 1 for adding data, 2 for insertion in the middle, 3 for insertion in the beginning, 4 for traversal, 5 for deletion, 6 for searching, 7 for reversing the linked list, 8 for exiting : ";
    cin >> y;
    if(y!=3)
    {switch(y)
    {
    case 1:
        cout << "Enter the data to be added :";
        cin >> a;
        addinfo(&n1, a);
        break;
    case 2:
        cout << "Enter the data to be inserted :";
        cin >> a;
        cout << "Enter the node number at which data is to be inserted :";
        cin >> b;
        insrt_mid(a, n1, b);
        break;
    case 4:
        traverse(n1);
        break;
    case 5:
        cout << "Enter the node which is to be deleted : ";
        cin >> n;
        if(n!=1)
        {
            l=deletion(n1, n);
        }
        else
        {
            l=n1->info;
            n1=n1->link;
        }
        cout << "The value at the deleted node was : " << l;
        break;
    case 6:
        cout << "Enter the key to be searched : ";
        cin >> key;
        searc_h(key, n1, loc);
        break;
    case 7:
        n1=revers(n1);
        cout << "Linked list reversed.";
        break;
    case 8:
        m='x';
        break;
    }}
    else
    {
        cout << "Enter the value to be inserted at the beginning : ";
        cin >> a;
        node *n2=new node;
        n2=insrt_begin(a, n1);
        n1=n2;
    }
    cout << "\n";
    }
}
