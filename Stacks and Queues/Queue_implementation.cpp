#include <iostream>
#define SIZE 100
using namespace std;

struct queu
{
    int arr[SIZE];
    int tail;
    int head;
    void init()
    {
        tail=0;
        head=0;
    }
    void enqueue(int data)
    {
        if(tail==SIZE-1 && head==0)
            {cout << "Queue Overflow";
            return;
            }
        else if(tail==head-1)
            {cout << "Queue Overflow";
            return;
            }
        else
        {
            arr[tail]=data;
            if(tail==SIZE-1)
                tail=0;
            else
                tail++;
        }
    }
    int dequ()
    {
        int x;
        if(head==tail)
            {cout << "Queue underflow";
            return -1;
            }
        else
            {x=arr[head];
            if(head==SIZE-1)
                head=0;
            else
                head++;
            return x;
                }
    }
};


int main()
{
    int a,b;
    struct queu s;
    s.init();
    s.enqueue(3);
    s.enqueue(7);
    s.enqueue(13);

    a=s.dequ();
    if(a!=-1)
        {cout << a;
        }
    a=s.dequ();
    cout << " " << a;
}
