#include <iostream>
#define MAXSTACK 100
using namespace std;

struct bndtype
{
    int lb;
    int ub;
};
bndtype newbnds;

struct stac_k
{
    int top;
    bndtype bounds[MAXSTACK];
    void push(st s1, bndtype data)
    {
        if(top>=0)

    }
};

typedef stac_k st;

