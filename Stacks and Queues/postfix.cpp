#include <iostream>
#include <stdio.h>
#include <ctype.h>
#define MAX 100
#define INT_MIN -1
using namespace std;

typedef struct stack
{
 int data[MAX];
 int top;
}stack;

int priority(char);
void init(stack *);
int empty(stack *);
int full(stack *);
char pop(stack *);
void push(stack *,char);
char top(stack *);

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
    stack s;
    while(i<strlen(exp))
    {
        if(exp[i]>='0'&&exp[i]<='9')
            push(&s, exp[i]-'0');
        else if(exp[i]==',')
        {
        }
        else
        {
            int x=pop(&s);
            int y=pop(&s);
            switch(exp[i])
            {
            case'+':
                push(&s,y+x);
                break;
            case'-':
                push(&s,y-x);
                break;
            case'*':
                push(&s,y*x);
                break;
            case'/':
                push(&s,y/x);
                break;
            }
        }
        i++;
    }
    return pop(&s);
}


int main()
{
stack s, s1;
char x;
int token;
init(&s);
init(&s1);
cout << "nEnter infix expression:";
  while((token=getchar())!='n')
  {
    if(isalnum(token))
       {cout << (char)token;
       push(&s1, (char)token);}
    else
       if(token == '(')
           push(&s,'(');
       else
       {
         if(token == ')')
             while((x=pop(&s))!='(')
             {cout << (char)x;
             push(&s1, (char)x);}
         else
         {
         while(priority(token)<=priority(top(&s)) && !empty(&s))
             {
             x=pop(&s);
             cout << (char)x;
             push(&s1, (char)x);
             }
         push(&s,token);
         }
       }
  }
  while(!empty(&s))
    {
    x=pop(&s);
    cout <<(char)x;
    push(&s1, (char)x);
    }
    cout << "\n";
    int i;
    char a[100];
    for(i=(s1.top); i>=0; i--)
    {
        a[i]=pop(&s1);
    }
    a[(s1.top)+1]='\0';
    int q;
    q=evaluate_postfix(a);
    cout << "\nThe evaluated postfix expression is : " << q;
    return 0;
}
//---------------------------------------------
int priority(char x)
{
   if(x == '(')
 return(0);
   if(x == '+' || x == '-')
 return(1);
   if(x == '*' || x == '/' || x == '%')
 return(2);
   return(3);
}
//---------------------------------------------
void init(stack *s)
{
   s->top=-1;
}
//---------------------------------------------
int empty(stack *s)
{
    if(s->top==-1)
 return(1);
    else
 return(0);
}
//---------------------------------------------
int full(stack *s)
{
    if(s->top==MAX-1)
 return(1);
    else
 return(0);
}
//---------------------------------------------
void push(stack *s,char x)
{
  s->top=s->top+1;
  s->data[s->top]=x;
}
//---------------------------------------------
char pop(stack *s)
{
   int x;
   x=s->data[s->top];
   s->top=s->top-1;
   return(x);
}
//---------------------------------------------
char top(stack * s)
{
   return(s->data[s->top]);
}
//---------------------------------------------
