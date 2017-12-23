//Implementation of max, extract_max, increase_key, and insert operations on a priority queue in O(lg n) time_base
#include <iostream>
#include <algorithm>
using namespace std;

int arr_max(int arr[], int a, int r, int l)
{
    if(arr[a]>arr[r]&&arr[a]>arr[l])
        return a;
    else if(arr[r]>arr[l])
        return r;
    else
        return l;
}

void max_heapify(int arr[], int heapsize, int a)
{
    int r, l, largest;
    l=2*a;
    r=2*a+1;
    if(r<=heapsize-1)
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
    else if(l==heapsize-1)
    {
        if(arr[a]<arr[l])
            swap(arr[a], arr[l]);
    }
}

void build_max_heap(int arr[], int n, int heapsize)       //Here, n is the immediate larger power of 2(just greater than size of the array) minus 1 and heapsize is the size of the array
{
    int i;
    for(i=(n/2)-1; i>=0; i--)
    {
        max_heapify(arr, heapsize, i);
    }
}

int max_priority(int arr[], int heapsize)
{
    return arr[0];
}

int extract_max(int arr[], int heapsize)
{
    int temp;
    temp=arr[0];
    arr[0]=arr[heapsize-1];
    max_heapify(arr, heapsize-1, 0);
}

void increase_key(int arr[], int a, int new_key)
{
    if(arr[a]>new_key)
        cout << "Error : New key value is lesser than old key.";
    else
    {
        arr[a]=new_key;
        while(arr[a/2]<arr[a])
        {
            swap(arr[a/2], arr[a]);
            a=a/2;
        }
    }
}

void insrt_in_queue(int arr[], int arr_size, int heapsize, int elem)
{
    if(heapsize>=arr_size)
        cout << "Error : Queue overflow";
    else
    {
        arr[heapsize]=-31000;
        increase_key(arr, heapsize, elem);
    }
}

int main()
{
    int arr_size, heapsize;
    cout << "Enter the array-size and then the heapsize:";
    cin >> arr_size >> heapsize;
    int arr[arr_size];
    for(int i=0; i<heapsize; i++)
        cin >> arr[i];
    build_max_heap
}

