#include <iostream>
#define STACKSIZE 100
using namespace std;

struct stk
{
    int top=-1;
    int items[STACKSIZE];
    bool em_pty(struct stk *ps)
    {
        if(ps->top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(struct stk *ps, int x)
    {
        if(ps->top==STACKSIZE-1)
        {
            cout << "Stack overflow";
            return;
        }
        else
        {
            ps->items[++(ps->top)]=x;
            return;
        }
    }
    int pop(struct stk *ps)
    {
        if(em_pty(ps))
        {
            cout << "Stack underflow";
            return -1;
        }
        else
        {
            return ps->items[ps->top--];
        }
    }
};

int main()
{
    struct stk s1;
    s1.push(&s1, 3);
    s1.push(&s1, 6);
    cout << s1.pop(&s1);
    return 0;
}
