#include <iostream>
#define STACKSIZE 100
using namespace std;

struct stk
{
    int top=-1;
    int items[STACKSIZE];

    bool em_pty()
    {
        if(top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int x)
    {
        if(top==STACKSIZE-1)
        {
            cout << "Stack overflow";
            return;
        }
        else
        {
            items[++top]=x;
            return;
        }
    }
    int pop()
    {
        if(em_pty())
        {
            cout << "Stack underflow";
            return -1;
        }
        else
        {
            return items[top--];
        }
    }
    void display()
    {
        if(em_pty())
        {
            cout << "Stack Underflow";
        }
        else
        {
            for(int i=0; i<=top; i++)
                cout << items[i] << " ";
        }
    }
};


int pow(int a, int b)
{
    int i;
    int pow=1;
    for(i=1; i<=b; i++)
        pow *= a;
    return pow;
}


void toh(int n)
{
    int i;
    stk src, aux, dest;
    for(i=n; i>=1; i--)
        src.push(i);
    if(n%2==1)
    {
    for(i=1; i<=pow(2,n)-1; i++)
    {
        if(i%3==1)
        {
            if(src.top==-1)
            {
                src.push(dest.pop());
                cout << "Move disc from dest to src\n";

            }
            else if(dest.top==-1)
            {
                dest.push(src.pop());
                cout << "Move disc from src to dest\n";
            }
            else
            {
                if(src.items[src.top]<dest.items[dest.top])
                {
                    dest.push(src.pop());
                cout << "Move disc from src to dest\n";
                }
                else
                {
                    src.push(dest.pop());
                cout << "Move disc from dest to src\n";
                }
            }
        }
        if(i%3==2)
        {
            if(src.top==-1)
            {
                src.push(aux.pop());
                cout << "Move disc from aux to src\n";
            }
            else if(aux.top==-1)
            {
                aux.push(src.pop());
                cout << "Move disc from src to aux\n";
            }
            else
            {
                if(src.items[src.top]<aux.items[aux.top])
                {
                    aux.push(src.pop());
                cout << "Move disc from src to aux\n";
                }
                else
                {
                    src.push(aux.pop());
                cout << "Move disc from aux to src\n";
                }
            }
        }
        if(i%3==0)
        {
            if(dest.top==-1)
            {
                dest.push(aux.pop());
                cout << "Move disc from aux to dest\n";
            }
            else if(aux.top==-1)
            {
                aux.push(dest.pop());
                cout << "Move disc from dest to aux\n";
            }
            else
            {
                if(dest.items[dest.top]<aux.items[aux.top])
                {
                    aux.push(dest.pop());
                cout << "Move disc from dest to aux\n";
                }
                else
                {
                    dest.push(aux.pop());
                cout << "Move disc from aux to dest\n";
                }
            }
        }
    }
    }
    else
    {
        for(i=1; i<=pow(2,n)-1; i++)
    {
        if(i%3==1)
        {
            if(src.top==-1)
            {
                src.push(aux.pop());
                cout << "Move disc from aux to src\n";

            }
            else if(aux.top==-1)
            {
                aux.push(src.pop());
                cout << "Move disc from src to aux\n";
            }
            else
            {
                if(src.items[src.top]<aux.items[aux.top])
                {
                    aux.push(src.pop());
                cout << "Move disc from src to aux\n";
                }
                else
                {
                    src.push(aux.pop());
                cout << "Move disc from aux to src\n";
                }
            }
        }
        if(i%3==2)
        {
            if(src.top==-1)
            {
                src.push(dest.pop());
                cout << "Move disc from dest to src\n";
            }
            else if(dest.top==-1)
            {
                dest.push(src.pop());
                cout << "Move disc from src to dest\n";
            }
            else
            {
                if(src.items[src.top]<dest.items[dest.top])
                {
                    dest.push(src.pop());
                cout << "Move disc from src to dest\n";
                }
                else
                {
                    src.push(dest.pop());
                cout << "Move disc from dest to src\n";
                }
            }
        }
        if(i%3==0)
        {
            if(dest.top==-1)
            {
                dest.push(aux.pop());
                cout << "Move disc from aux to dest\n";
            }
            else if(aux.top==-1)
            {
                aux.push(dest.pop());
                cout << "Move disc from dest to aux\n";
            }
            else
            {
                if(dest.items[dest.top]<aux.items[aux.top])
                {
                    aux.push(dest.pop());
                cout << "Move disc from dest to aux\n";
                }
                else
                {
                    dest.push(aux.pop());
                cout << "Move disc from aux to dest\n";
                }
            }
        }
    }
    }
}

int main()
{
    toh(2);
}
