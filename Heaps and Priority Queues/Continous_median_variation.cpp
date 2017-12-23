#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

long  arr_max(long  arr[], long  a, long  r, long  l)
{
    if(arr[a]>arr[r]&&arr[a]>arr[l])
        return a;
    else if(arr[r]>arr[l])
        return r;
    else
        return l;
}

void max_heapify(long  arr[], long  heapsize, long  a)
{
    long  r, l, largest;
    l=2*a;
    r=2*a+1;
    if(r<=heapsize)
    {
        largest=arr_max(arr, a, r, l);
        if(largest!=a)
        {
            if(largest==r)
            {
                swap(arr[a], arr[r]);
                max_heapify(arr, heapsize, r);
            }
            else
            {
                swap(arr[a], arr[l]);
                max_heapify(arr, heapsize, l);
            }
        }
    }
    else if(l==heapsize)
    {
        if(arr[a]<arr[l])
            swap(arr[a], arr[l]);
    }
}

long  brr_min(long  brr[], long  a, long  r, long  l)
{
    if(brr[a]<brr[r]&&brr[a]<brr[l])
        return a;
    else if(brr[r]<brr[l])
        return r;
    else
        return l;
}

void min_heapify(long  brr[], long  heapsize, long  a)
{
    long  r, l, smallest;
    l=2*a;
    r=2*a+1;
    if(r<=heapsize)
    {
        smallest=brr_min(brr, a, r, l);
        if(smallest!=a)
        {
            if(smallest==r)
            {
                swap(brr[a], brr[r]);
                min_heapify(brr, heapsize, r);
            }
            else
            {
                swap(brr[a], brr[l]);
                min_heapify(brr, heapsize, l);
            }
        }
    }
    else if(l==heapsize)
    {
        if(brr[a]>brr[l])
            swap(brr[a], brr[l]);
    }
}


void increase_key(long  arr[], long  a, long  new_key)
{
    arr[a]=new_key;
    while(arr[a/2]<arr[a]&&a>1)
    {
        swap(arr[a/2], arr[a]);
        a=a/2;
    }
}

void ins_left(long  arr[], long  leftsize, long  elem)
{
    //arr[leftsize+1]=-1;
    increase_key(arr, leftsize+1, elem);
}

void decrease_key(long  brr[], long  a, long  new_key)
{
    brr[a]=new_key;
    while(brr[a/2]>brr[a]&&a>1)
    {
        swap(brr[a/2], brr[a]);
        a=a/2;
    }
}

void ins_right(long  brr[], long  rightsize, long  elem)
{
    decrease_key(brr, rightsize+1, elem);
}

long  extr_left(long  arr[], long  leftsize)
{
    long  temp=arr[1];
    arr[1]=arr[leftsize];
    max_heapify(arr, leftsize-1, 1);
    return temp;
}

long  extr_right(long  brr[], long  rightsize)
{
    long  temp=brr[1];
    brr[1]=brr[rightsize];
    min_heapify(brr, rightsize-1, 1);
    return temp;
}

int main()
{
    long  n, h, i, lefts, rights, temp, temp_extr;
    lefts=0;
    rights=0;
    float med;
    cin >> n;
    h=n/2;
    //if(n%2==0)
    //{
        long  a[h+2], b[h+2];
        a[0]=0;  //Index 0 is left unused
        b[0]=0;  //Index 0 is left unused
        for(i=1; i<=n; i++)
        {
            cin >> temp;
            if(i%2==1)         //This if block handles all cases in which the insertion of 2p+1th element takes place
            {
                if(i==1)       //For initialization of med when the first element is inserted
                {
                    a[1]=temp;
                    med=a[1];
                    lefts++;
                }
                else
                {
                    if(temp<med)
                    {
                        ins_left(a, lefts, temp);
                        lefts++;
                        med=a[1];
                    }
                    else
                    {
                        ins_right(b, rights, temp);
                        rights++;
                        med=b[1];
                    }
                }
            }
            else              //This block handles the insertion of 2pth elements
            {
                if(temp<med)
                {
                    if(lefts==rights-1)
                    {
                        ins_left(a, lefts, temp);
                        lefts++;
                        med=((float)a[1]+b[1])/2;
                    }
                    else
                    {
                        temp_extr=extr_left(a, lefts);
                        lefts--;
                        ins_right(b, rights, temp_extr);
                        rights++;
                        ins_left(a, lefts, temp);
                        lefts++;
                        med=((float)a[1]+b[1])/2;
                    }
                }
                else
                {
                    if(rights==lefts-1)
                    {
                        ins_right(b, rights, temp);
                        rights++;
                        med=((float)a[1]+b[1])/2;
                    }
                    else
                    {
                        temp_extr=extr_right(b, rights);
                        rights--;
                        ins_left(a, lefts, temp_extr);
                        lefts++;
                        ins_right(b, rights, temp);
                        rights++;
                        med=((float)a[1]+b[1])/2;
                    }
                }
            }
            cout << setiosflags(ios::fixed)<< setiosflags(ios::showpoint) << setprecision(1) << med << " ";
        }
    //}
    return 0;
}
