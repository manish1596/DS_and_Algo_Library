#include <iostream>
#include <string>
#define STACKSIZE 100
#include <stack>
#define INT_MIN -1
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

int strlen(char a[])
{
    int i=0;
    while(a[i]!='\0')
    {
        i++;
    }
    return i;
}

int evaluate_postfix(char exp[])
{
    if(strlen(exp)==0)
        return INT_MIN;
    int i=0;
    stk s;
    while(i<strlen(exp))
    {
        if(exp[i]>='0'&&exp[i]<='9')
            s.push(&s, exp[i]-'0');
        else if(exp[i]==',')
        {
        }
        else
        {
            int x=s.pop(&s);
            int y=s.pop(&s);
            switch(exp[i])
            {
            case'+':
                s.push(&s,y+x);
                break;
            case'-':
                s.push(&s,y-x);
                break;
            case'*':
                s.push(&s,y*x);
                break;
            case'/':
                s.push(&s,y/x);
                break;
            }
        }
        i++;
    }
    return s.pop(&s);
}

int main()
{
    char a[100];
    cin >> a;
    int x;
    x=evaluate_postfix(a);
    cout << "\n" << x;
    return 0;
}
