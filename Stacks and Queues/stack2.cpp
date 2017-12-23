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

int main()
{
    struct stk s1;
    cout << s1.pop()<< "\n";
    s1.push(3);
    cout << s1.pop() << "\n";
    s1.push(4);
    s1.push(7);
    s1.push(18);
    s1.push(15);
    s1.display();
    cout << "\n" << s1.pop();
    cout << "\n" << s1.pop();
    cout << "\n";
    s1.display();
    return 0;
}
